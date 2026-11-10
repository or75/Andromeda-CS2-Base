#include "CDebugPage.hpp"

#include "../Custom/CSectionBar.hpp"
#include "../Core/CStyleManager.hpp"

#include <GameClient/CEntityCache/CEntityCache.hpp>

#include <algorithm>
#include <array>
#include <string>
#include <string_view>

namespace
{
	class CSchemaEditorWidget final : public GitMenu::IWidget
	{
	public:
		CSchemaEditorWidget() : IWidget( "Property Editor" , "Browse and edit schema properties." ) {}

		auto OnRenderImGui() -> void override
		{
			UpdateEntities();

			ImGui::PushID( this );

			const auto availableWidth = ImGui::GetContentRegionAvail().x;
			const auto listWidth = ImMin( 300.f * ImGui::GetFontSize() / 16.f , availableWidth * 0.45f );

			if ( ImGui::BeginChild( "##entities" , ImVec2( ImMax( 1.f , listWidth ) , 0.f ) , ImGuiChildFlags_ResizeX | ImGuiChildFlags_Borders | ImGuiChildFlags_NavFlattened ) )
			{
				ImGui::SetNextItemWidth( -FLT_MIN );
				ImGui::SetNextItemShortcut( ImGuiMod_Ctrl | ImGuiKey_F , ImGuiInputFlags_Tooltip );
				
				if ( ImGui::InputTextWithHint( "##Filter" , "incl -excl" , m_Filter.InputBuf , IM_COUNTOF( m_Filter.InputBuf ) , ImGuiInputTextFlags_EscapeClearsAll ) )
					m_Filter.Build();

				if ( ImGui::BeginTable( "##list" , 1 , ImGuiTableFlags_RowBg ) )
				{
					for ( const auto& entity : m_Entities )
					{
						if ( !m_Filter.PassFilter( entity.Name.c_str() ) )
							continue;

						ImGui::TableNextRow();
						ImGui::TableNextColumn();

						ImGui::PushID( static_cast<int>( entity.Handle.m_Index ) );
						
						auto flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_NavLeftJumpsToParent | ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_DrawLinesToNodes;
						
						if ( m_SelectedHandle == entity.Handle.m_Index && m_SelectedBaseIndex < 0 )
							flags |= ImGuiTreeNodeFlags_Selected;
						
						if ( !entity.HasBase )
							flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Bullet | ImGuiTreeNodeFlags_NoTreePushOnOpen;

						const auto open = ImGui::TreeNodeEx( "##entity" , flags , "%s" , entity.Name.c_str() );
						
						if ( ImGui::IsItemFocused() || ( ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen() ) )
						{
							m_SelectedHandle = entity.Handle.m_Index;
							m_SelectedBaseIndex = -1;
							m_SelectedClassName.clear();
						}

						if ( open && entity.HasBase )
						{
							RenderBaseClasses( entity.Handle );
							ImGui::TreePop();
						}
						
						ImGui::PopID();
					}

					ImGui::EndTable();
				}
			}

			ImGui::EndChild();
			ImGui::SameLine();

			if ( ImGui::BeginChild( "##details" , ImVec2( 0.f , 0.f ) ) )
			{
				const auto selected = std::find_if( m_Entities.begin() , m_Entities.end() , [this]( const auto& entity ) { return entity.Handle.m_Index == m_SelectedHandle; } );
				
				if ( selected != m_Entities.end() )
				{
					ImGui::TextUnformatted( m_SelectedBaseIndex >= 0 ? m_SelectedClassName.c_str() : selected->Name.c_str() );
					ImGui::TextDisabled( "ID: %d" , selected->Handle.GetEntryIndex() );
					ImGui::Separator();

					RenderProperties( selected->Handle );
				}
				else
					ImGui::TextDisabled( "Select an entity to view its properties." );
			}

			ImGui::EndChild();
			ImGui::PopID();
		}

	private:
		struct SEntity
		{
			CHandle Handle;
			std::string Name;
			bool HasBase = false;
		};

		template <typename T>
		static auto ReadField( const void* address , size_t available , T& value ) -> bool
		{
			SIZE_T read = 0;
			return available >= sizeof( T ) && ReadProcessMemory( GetCurrentProcess() , address , &value , sizeof( T ) , &read ) && read == sizeof( T );
		}

		template <typename T>
		static auto WriteField( void* address , size_t available , const T& value ) -> bool
		{
			if ( available < sizeof( T ) )
				return false;

			MEMORY_BASIC_INFORMATION memory{};
			
			if ( !VirtualQuery( address , &memory , sizeof( memory ) ) || memory.State != MEM_COMMIT || ( memory.Protect & PAGE_GUARD ) )
				return false;

			const auto protection = memory.Protect & 0xFF;
			
			if ( protection != PAGE_READWRITE && protection != PAGE_WRITECOPY && protection != PAGE_EXECUTE_READWRITE && protection != PAGE_EXECUTE_WRITECOPY )
				return false;

			const auto offset = reinterpret_cast<uintptr_t>( address ) - reinterpret_cast<uintptr_t>( memory.BaseAddress );
			
			if ( offset >= memory.RegionSize || sizeof( T ) > memory.RegionSize - offset )
				return false;

			SIZE_T written = 0;
			return WriteProcessMemory( GetCurrentProcess() , address , &value , sizeof( T ) , &written ) && written == sizeof( T );
		}

		static auto SetWriteResult( bool success ) -> void
		{
			ImGui::GetStateStorage()->SetBool( ImGui::GetID( "##write_failed" ) , !success );
		}

		template <typename T>
		static auto EditScalar( void* address , size_t available , ImGuiDataType dataType , const char* format = nullptr ) -> void
		{
			T value{};
			
			if ( !ReadField( address , available , value ) )
			{
				ImGui::TextDisabled( "<unreadable>" );
				return;
			}

			ImGui::SetNextItemWidth( -FLT_MIN );
			
			if ( ImGui::InputScalar( "##value" , dataType , &value , nullptr , nullptr , format , ImGuiInputTextFlags_EnterReturnsTrue ) )
				SetWriteResult( WriteField( address , available , value ) );
			
			ImGui::SetItemTooltip( "Press Enter to apply." );
		}

		static auto RenderEditableValue( std::string_view type , void* address , size_t available ) -> void
		{
			if ( type == "bool" )
			{
				uint8_t stored{};
				
				if ( !ReadField( address , available , stored ) )
				{
					ImGui::TextDisabled( "<unreadable>" );
					return;
				}
				
				auto value = stored != 0;
				
				if ( ImGui::Checkbox( "##value" , &value ) )
					SetWriteResult( WriteField( address , available , static_cast<uint8_t>( value ) ) );
				
				return;
			}

			if ( type == "int8" || type == "int8_t" || type == "char" ) return EditScalar<int8_t>( address , available , ImGuiDataType_S8 );
			if ( type == "uint8" || type == "uint8_t" || type == "unsigned char" ) return EditScalar<uint8_t>( address , available , ImGuiDataType_U8 );
			if ( type == "int16" || type == "int16_t" || type == "short" ) return EditScalar<int16_t>( address , available , ImGuiDataType_S16 );
			if ( type == "uint16" || type == "uint16_t" || type == "unsigned short" ) return EditScalar<uint16_t>( address , available , ImGuiDataType_U16 );
			if ( type == "int32" || type == "int32_t" || type == "int" ) return EditScalar<int32_t>( address , available , ImGuiDataType_S32 );
			if ( type == "uint32" || type == "uint32_t" || type == "unsigned int" ) return EditScalar<uint32_t>( address , available , ImGuiDataType_U32 );
			if ( type == "int64" || type == "int64_t" || type == "long long" ) return EditScalar<int64_t>( address , available , ImGuiDataType_S64 );
			if ( type == "uint64" || type == "uint64_t" || type == "unsigned long long" ) return EditScalar<uint64_t>( address , available , ImGuiDataType_U64 );
			if ( type == "float32" || type == "float" ) return EditScalar<float>( address , available , ImGuiDataType_Float , "%.9g" );
			if ( type == "float64" || type == "double" ) return EditScalar<double>( address , available , ImGuiDataType_Double , "%.17g" );

			if ( type.ends_with( '*' ) )
			{
				return EditScalar<uintptr_t>( address , available , sizeof( uintptr_t ) == 8 ? ImGuiDataType_U64 : ImGuiDataType_U32 , sizeof( uintptr_t ) == 8 ? "0x%016llX" : "0x%08X" );
			}

			if ( type == "Vector" || type == "Vector3" || type == "QAngle" )
			{
				std::array<float , 3> value{};
				
				if ( !ReadField( address , available , value ) )
				{
					ImGui::TextDisabled( "<unreadable>" );
					return;
				}

				ImGui::PushMultiItemsWidths( 3 , ImGui::GetContentRegionAvail().x );

				for ( auto component = 0; component < 3; ++component )
				{
					ImGui::PushID( component );

					if ( component )
						ImGui::SameLine( 0.f , ImGui::GetStyle().ItemInnerSpacing.x );
					
					const auto submitted = ImGui::InputScalar( "##value" , ImGuiDataType_Float , &value[component] , nullptr , nullptr , "%.9g" , ImGuiInputTextFlags_EnterReturnsTrue );
					
					ImGui::SetItemTooltip( "%s: press Enter to apply." , component == 0 ? "X" : component == 1 ? "Y" : "Z" );
					ImGui::PopID();
					ImGui::PopItemWidth();
					
					if ( submitted )
						SetWriteResult( WriteField( static_cast<unsigned char*>( address ) + component * sizeof( float ) , available - component * sizeof( float ) , value[component] ) );
				}
				return;
			}

			ImGui::TextUnformatted( "-" );
		}

		static auto RenderFieldValue( std::string_view type , uintptr_t address , size_t available ) -> void
		{
			ImGui::PushID( reinterpret_cast<const void*>( address ) );
			RenderEditableValue( type , reinterpret_cast<void*>( address ) , available );
			
			if ( ImGui::GetStateStorage()->GetBool( ImGui::GetID( "##write_failed" ) ) )
				ImGui::TextDisabled( "Write failed." );
			
			ImGui::PopID();
		}

		struct SFieldType
		{
			std::string ClassName;
			size_t PointerDepth = 0;
		};

		static auto ParseFieldType( std::string_view type ) -> SFieldType
		{
			SFieldType result;
			
			while ( !type.empty() )
			{
				if ( type.front() == ' ' ) type.remove_prefix( 1 );
				else if ( type.back() == ' ' ) type.remove_suffix( 1 );
				else if ( type.starts_with( "const " ) ) type.remove_prefix( 6 );
				else if ( type.starts_with( "volatile " ) ) type.remove_prefix( 9 );
				else if ( type.starts_with( "class " ) ) type.remove_prefix( 6 );
				else if ( type.starts_with( "struct " ) ) type.remove_prefix( 7 );
				else if ( type.ends_with( " const" ) ) type.remove_suffix( 6 );
				else if ( type.ends_with( " volatile" ) ) type.remove_suffix( 9 );
				else if ( type.back() == '*' ) { type.remove_suffix( 1 ); ++result.PointerDepth; }
				else break;
			}
			
			result.ClassName = type;
			return result;
		}

		using SchemaPath = std::vector<std::pair<uintptr_t , std::string>>;

		static auto RenderProperty( const char* type , const char* name , uintptr_t address , size_t available , SchemaPath& path , int depth ) -> void
		{
			const auto parsed = ParseFieldType( type ? type : "" );
			auto schemaName = parsed.ClassName;
			
			auto* schema = &GetSchemaOffset()->GetSchemaData( schemaName );
			
			if ( schema->empty() && name )
			{
				schemaName = name;
				schema = &GetSchemaOffset()->GetSchemaData( schemaName );
			}

			ImGui::PushID( name ? name : "<unnamed>" );
			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			ImGui::TextUnformatted( type ? type : "<unknown>" );
			ImGui::TableNextColumn();
			ImGui::Indent( ( depth + 1 ) * ImGui::GetStyle().IndentSpacing );
			
			const auto expandable = parsed.PointerDepth > 0 || !schema->empty();
			auto flags = ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
			
			if ( !expandable )
				flags |= ImGuiTreeNodeFlags_Leaf;
			
			const auto open = ImGui::TreeNodeEx( "##field" , flags , "%s" , name ? name : "<unnamed>" );
			
			ImGui::Unindent( ( depth + 1 ) * ImGui::GetStyle().IndentSpacing );
			ImGui::TableNextColumn();
			
			RenderFieldValue( parsed.PointerDepth ? "void*" : parsed.ClassName , address , available );
			
			ImGui::TableNextColumn();
			ImGui::Text( "%p" , reinterpret_cast<void*>( address ) );

			if ( open && expandable )
			{
				auto object = address;
				const char* error = nullptr;
				
				for ( size_t level = 0; level < parsed.PointerDepth; ++level )
				{
					uintptr_t target{};
					
					if ( !ReadField( reinterpret_cast<const void*>( object ) , level == 0 ? available : sizeof( target ) , target ) )
					{
						error = "Unreadable pointer.";
						break;
					}

					object = target;

					if ( !object ){ error = "nullptr"; break; }
				}

				const auto key = std::make_pair( object , schemaName );
				
				if ( !error && depth >= 32 ) error = "Maximum nesting depth reached.";
				if ( !error && std::find( path.begin() , path.end() , key ) != path.end() ) error = "Cyclic reference.";
				if ( !error && schema->empty() ) error = "Schema fields are unavailable.";

				if ( error )
				{
					ImGui::TableNextRow();
					ImGui::TableSetColumnIndex( 1 );
					ImGui::Indent( ( depth + 2 ) * ImGui::GetStyle().IndentSpacing );
					ImGui::TextDisabled( "%s" , error );
					ImGui::Unindent( ( depth + 2 ) * ImGui::GetStyle().IndentSpacing );
				}
				else
				{
					std::vector<const SchemaOffset_t*> fields;
					
					for ( const auto& [fieldName , field] : *schema )
						fields.push_back( &field );
					
					std::sort( fields.begin() , fields.end() , []( const auto* left , const auto* right ) {
						return left->m_Offset != right->m_Offset ? left->m_Offset < right->m_Offset : left->m_PropertyName < right->m_PropertyName;
					} );

					path.push_back( key );
					
					for ( const auto* field : fields )
					{
						auto remaining = field->m_Offset < field->m_ClassSize ? static_cast<size_t>( field->m_ClassSize - field->m_Offset ) : size_t{ 0 };
						if ( !parsed.PointerDepth )
							remaining = field->m_Offset < available ? ( std::min )( remaining , available - field->m_Offset ) : 0;
						RenderProperty( field->m_TypeName.c_str() , field->m_PropertyName.c_str() , object + field->m_Offset , remaining , path , depth + 1 );
					}
					
					path.pop_back();
				}
			}

			ImGui::PopID();
		}

		auto RenderProperties( CHandle handle ) -> void
		{
			auto* cache = GetEntityCache();
			
			std::scoped_lock lock( cache->GetLock() );

			auto* entity = handle.Get();
			auto* identity = entity ? entity->pEntityIdentity() : nullptr;
			
			if ( !identity || !( identity->Handle() == handle ) )
				return;

			auto* binding = entity->GetSchemaClassBinding();
			
			std::vector<CSchemaClassBinding*> visited;
			
			for ( auto index = 0; binding && index <= m_SelectedBaseIndex; ++index )
			{
				visited.push_back( binding );
				
				auto* base = binding->m_baseClass();
				
				binding = base ? base->m_classInfo() : nullptr;
				
				if ( std::find( visited.begin() , visited.end() , binding ) != visited.end() )
					binding = nullptr;
			}

			if ( !binding )
			{
				ImGui::TextDisabled( "Schema class is unavailable." );
				return;
			}

			const auto fieldCount = binding->m_DataArraySize();
			const auto* fields = binding->m_DataArray();
			
			if ( fieldCount && !fields )
			{
				ImGui::TextDisabled( "Schema fields are unavailable." );
				return;
			}

			if ( ImGui::BeginTable( "##properties" , 4 , ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_ScrollY ) )
			{
				ImGui::TableSetupColumn( "Type" );
				ImGui::TableSetupColumn( "Name" );
				ImGui::TableSetupColumn( "Value" );
				ImGui::TableSetupColumn( "Address" );
				ImGui::TableSetupScrollFreeze( 0 , 1 );
				ImGui::TableHeadersRow();

				ImGui::PushID( static_cast<int>( handle.m_Index ) );
				ImGui::PushID( binding );
				
				SchemaPath path{ { reinterpret_cast<uintptr_t>( entity ) , binding->m_bindingName() ? binding->m_bindingName() : "" } };
				
				for ( auto index = 0; index < fieldCount; ++index )
				{
					const auto& field = fields[index];
					const auto* type = field.FieldType ? field.FieldType->szTypeName : nullptr;
					const auto address = reinterpret_cast<uintptr_t>( entity ) + field.FieldOffset;
					const auto classSize = binding->m_SizeOf();
					const auto available = field.FieldOffset >= 0 && field.FieldOffset < classSize ? static_cast<size_t>( classSize - field.FieldOffset ) : size_t{ 0 };
					
					RenderProperty( type , field.FieldName , address , available , path , 0 );
				}
				
				ImGui::PopID();
				ImGui::PopID();

				ImGui::EndTable();
			}
		}

		auto RenderBaseClasses( CHandle handle ) -> void
		{
			std::vector<std::string> names;
			std::vector<CSchemaClassBinding*> visited;

			auto cycle = false;
			{
				auto* cache = GetEntityCache();

				std::scoped_lock lock( cache->GetLock() );

				auto* entity = handle.Get();

				auto* identity = entity ? entity->pEntityIdentity() : nullptr;

				if ( !identity || !( identity->Handle() == handle ) )
					return;

				// Walk the recursive base-class chain without growing the call stack.
				auto* binding = entity->GetSchemaClassBinding();

				while ( binding )
				{
					visited.push_back( binding );

					auto* base = binding->m_baseClass();

					binding = base ? base->m_classInfo() : nullptr;

					if ( !binding )
						break;

					if ( std::find( visited.begin() , visited.end() , binding ) != visited.end() )
					{
						cycle = true;
						break;
					}

					const auto* name = binding->m_bindingName();
					names.emplace_back( name ? name : "<unnamed>" );
				}
			}

			const auto selectedEntity = m_SelectedHandle == handle.m_Index;
			
			if ( selectedEntity && m_SelectedBaseIndex >= static_cast<int>( names.size() ) )
			{
				m_SelectedBaseIndex = -1;
				m_SelectedClassName.clear();
			}
			else if ( selectedEntity && m_SelectedBaseIndex >= 0 )
				m_SelectedClassName = names[m_SelectedBaseIndex];

			auto pushed = 0;
			auto reachedEnd = true;
			
			for ( auto index = 0; index < static_cast<int>( names.size() ); ++index )
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				
				auto flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_NavLeftJumpsToParent | ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_DrawLinesToNodes;
				const auto leaf = index + 1 == static_cast<int>( names.size() );
				
				if ( leaf )
					flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Bullet | ImGuiTreeNodeFlags_NoTreePushOnOpen;
				
				if ( m_SelectedHandle == handle.m_Index && m_SelectedBaseIndex == index )
					flags |= ImGuiTreeNodeFlags_Selected;

				const auto open = ImGui::TreeNodeEx( reinterpret_cast<void*>( static_cast<intptr_t>( index + 1 ) ) , flags , "%s" , names[index].c_str() );
				
				if ( ImGui::IsItemFocused() || ( ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen() ) )
				{
					m_SelectedHandle = handle.m_Index;
					m_SelectedBaseIndex = index;
					m_SelectedClassName = names[index];
				}

				if ( !leaf && !open )
				{
					reachedEnd = false;
					break;
				}

				if ( !leaf )
					++pushed;
			}

			if ( cycle && reachedEnd )
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				ImGui::TextDisabled( "Inheritance cycle detected." );
			}

			for ( auto index = 0; index < pushed; ++index )
				ImGui::TreePop();
		}

		auto UpdateEntities() -> void
		{
			m_Entities.clear();

			auto* cache = GetEntityCache();
			{
				std::scoped_lock lock( cache->GetLock() );
				
				for ( const auto& cached : *cache->GetCachedEntity() )
				{
					if ( cached.m_Type == CachedEntity_t::UNKNOWN || !cached.m_Handle.IsValid() )
						continue;

					auto* entity = cached.m_Handle.Get();
					
					if ( !entity )
						continue;

					auto* identity = entity->pEntityIdentity();
					
					if ( !identity || !( identity->Handle() == cached.m_Handle ) )
						continue;

					auto* binding = entity->GetSchemaClassBinding();
					const auto* name = binding ? binding->m_bindingName() : nullptr;
					
					m_Entities.push_back( { cached.m_Handle , name ? name : "<unnamed>" , binding && binding->m_baseClass() && binding->m_baseClass()->m_classInfo() } );
				}
			}

			std::sort( m_Entities.begin() , m_Entities.end() , []( const auto& left , const auto& right ) { return left.Handle.GetEntryIndex() < right.Handle.GetEntryIndex(); } );
			
			if ( std::none_of( m_Entities.begin() , m_Entities.end() , [this]( const auto& entity ) { return entity.Handle.m_Index == m_SelectedHandle; } ) )
			{
				m_SelectedHandle = INVALID_EHANDLE_INDEX;
				m_SelectedBaseIndex = -1;
				m_SelectedClassName.clear();
			}
		}

		ImGuiTextFilter m_Filter;
		uint32_t m_SelectedHandle = INVALID_EHANDLE_INDEX;
		int m_SelectedBaseIndex = -1;
		std::string m_SelectedClassName;
		std::vector<SEntity> m_Entities;
	};

	class CDebugLogWidget final : public GitMenu::IWidget
	{
	public:
		CDebugLogWidget() : IWidget( "Log output" , "Select and copy logs. Filter by text." ) {}

		auto OnRenderImGui() -> void override
		{
			const auto source = GetDevLog()->GetBuffer();
			const auto changed = source != m_Source || m_FilterChanged;
			
			if ( changed )
			{
				m_Source = source;
				RebuildText();
				m_FilterChanged = false;
			}

			ImGui::PushID( this );

			auto* parent = ImGui::GetCurrentWindow();
			
			const auto id = parent->GetID( "##log_output" );
			const auto editorHeight = ImMax( 1.f , ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeight() - ImGui::GetStyle().ItemSpacing.y );
			
			// Native read-only editing provides mouse/keyboard selection and clipboard
			// support. Draw the text ourselves to color individual severity prefixes.
			ImGui::PushStyleColor( ImGuiCol_Text , ImVec4( 0.f , 0.f , 0.f , 0.f ) );
			ImGui::InputTextMultiline( "##log_output" , m_Text.data() , m_Text.size() + 1 , ImVec2( -1.f , editorHeight ) , ImGuiInputTextFlags_ReadOnly );
			ImGui::PopStyleColor();

			for ( auto* child : parent->DC.ChildWindows )
			{
				if ( child->ChildId != id || !child->Active || child->SkipItems )
					continue;

				RenderText( child , id );
				
				if ( changed && !ImGui::IsItemActive() && child->Scroll.y >= child->ScrollMax.y - 1.f )
					ImGui::SetScrollY( child , static_cast<float>( m_Lines.size() ) * ImGui::GetFontSize() );
				
				break;
			}

			ImGui::SetNextItemWidth( -1.f );
			m_FilterChanged = ImGui::InputTextWithHint( "##log_filter" , "Filter logs..." , m_Filter , sizeof( m_Filter ) );
			ImGui::PopID();
		}

	private:
		auto RebuildText() -> void
		{
			m_Text.clear();
			m_Lines.clear();
			
			const auto source = std::string_view( m_Source );
			
			for ( auto start = size_t{ 0 }; start < source.size(); )
			{
				const auto newline = source.find( '\n' , start );
				const auto end = newline == std::string_view::npos ? source.size() : newline;
				
				auto line = source.substr( start , end - start );
				
				if ( !line.empty() && line.back() == '\r' )
					line.remove_suffix( 1 );

				if ( m_Filter[0] == '\0' || ImStristr( line.data() , line.data() + line.size() , m_Filter , nullptr ) )
				{
					m_Lines.push_back( m_Text.size() );
					m_Text.append( line );
					
					if ( newline != std::string_view::npos )
						m_Text.push_back( '\n' );
				}
				
				start = newline == std::string_view::npos ? source.size() : newline + 1;
			}
		}

		auto RenderText( ImGuiWindow* child , ImGuiID id ) -> void
		{
			const auto fontSize = ImGui::GetFontSize();
			auto origin = child->DC.CursorStartPos + ImGui::GetStyle().FramePadding;
			
			if ( const auto* state = ImGui::GetInputTextState( id ); state && ImGui::GetActiveID() == id )
				origin.x -= state->Scroll.x;

			const auto& colors = GetStyleManager()->GetDebugLogColors();
			const auto textColor = ImGui::GetColorU32( ImGuiCol_Text );
			const auto firstLine = ImMax( 0 , static_cast<int>( ( child->ClipRect.Min.y - origin.y ) / fontSize ) );
			const auto lastLine = ImMin( static_cast<int>( m_Lines.size() ) , static_cast<int>( ( child->ClipRect.Max.y - origin.y ) / fontSize ) + 1 );
			
			child->DrawList->PushClipRect( child->ClipRect.Min , child->ClipRect.Max , true );
			
			for ( auto index = firstLine; index < lastLine; ++index )
			{
				const auto start = m_Lines[index];
				const auto end = m_Text.find( '\n' , start );
				const auto line = std::string_view( m_Text ).substr( start , end == std::string::npos ? m_Text.size() - start : end - start );
				
				auto prefixSize = size_t{ 0 };
				auto prefixColor = textColor;
				
				if ( line.starts_with( GitMenu::CDebugPage::ErrorPrefix ) ) { prefixSize = GitMenu::CDebugPage::ErrorPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Error ); }
				else if ( line.starts_with( GitMenu::CDebugPage::MinusPrefix ) ) { prefixSize = GitMenu::CDebugPage::MinusPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Info ); }
				else if ( line.starts_with( GitMenu::CDebugPage::InfoPrefix ) ) { prefixSize = GitMenu::CDebugPage::InfoPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Info ); }
				else if ( line.starts_with( GitMenu::CDebugPage::DebugPrefix ) ) { prefixSize = GitMenu::CDebugPage::DebugPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Info ); }
				else if ( line.starts_with( GitMenu::CDebugPage::WarningPrefix ) ) { prefixSize = GitMenu::CDebugPage::WarningPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Warning ); }
				else if ( line.starts_with( GitMenu::CDebugPage::SuccessPrefix ) ) { prefixSize = GitMenu::CDebugPage::SuccessPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Success ); }
				else if ( line.starts_with( GitMenu::CDebugPage::PlusPrefix ) ) { prefixSize = GitMenu::CDebugPage::PlusPrefix.size(); prefixColor = ImGui::GetColorU32( colors.Success ); }

				auto position = ImVec2( origin.x , origin.y + index * fontSize );
				
				if ( prefixSize > 0 )
				{
					child->DrawList->AddText( position , prefixColor , line.data() , line.data() + prefixSize );
					position.x += ImGui::CalcTextSize( line.data() , line.data() + prefixSize ).x;
				}
				
				child->DrawList->AddText( position , textColor , line.data() + prefixSize , line.data() + line.size() );
			}

			child->DrawList->PopClipRect();
		}

		char m_Filter[256]{};
		bool m_FilterChanged = true;

		std::string m_Source;
		std::string m_Text;

		std::vector<size_t> m_Lines;
	};
}

namespace GitMenu
{
	CDebugSchemaEditorSubPage::CDebugSchemaEditorSubPage()
	{
		auto section = std::make_unique<CSectionBar>( "Schema Editor" , ImVec2( 0.f , 0.f ) );

		section->AddTag( "debug" );
		section->AddTag( "schema" );

		section->AddWidget( std::make_unique<CSchemaEditorWidget>() );

		AddWidget( std::move( section ) );
	}

	CDebugLogsSubPage::CDebugLogsSubPage()
	{
		auto section = std::make_unique<CSectionBar>( "Debug Logs" , ImVec2( 0.f , 0.f ) );

		section->AddTag( "debug" );
		section->AddTag( "logs" );

		section->AddWidget( std::make_unique<CDebugLogWidget>() );

		AddWidget( std::move( section ) );
	}
}
