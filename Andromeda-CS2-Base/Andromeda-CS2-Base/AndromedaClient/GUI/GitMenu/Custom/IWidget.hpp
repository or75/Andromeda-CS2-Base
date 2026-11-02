#pragma once

#include <Common/Common.hpp>

#include <cctype>
#include <memory>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace GitMenu
{
	class IWidget
	{
	public:
		IWidget( std::string name = {} , std::string description = {} ) : m_Name( std::move( name ) ) , m_Description( std::move( description ) ) {}

		virtual ~IWidget() = default;
		virtual auto OnRenderImGui() -> void = 0;

		virtual auto GetName() const -> std::string_view { return m_Name; }
		virtual auto GetDescription() const -> std::string_view { return m_Description; }

		auto SetName( std::string name ) -> void { m_Name = std::move( name ); }
		auto SetDescription( std::string description ) -> void { m_Description = std::move( description ); }

		auto AddTag( std::string_view tag ) -> void
		{
			if ( !tag.empty() && tag.front() == '#' )
				tag.remove_prefix( 1 );
			
			if ( tag.empty() )
				return;
			
			for ( const auto& existing : m_Tags )
				if ( EqualsIgnoreCase( existing , tag ) )
					return;
			
			m_Tags.emplace_back( tag );
		}

		auto GetTags() const -> const std::vector<std::string>& { return m_Tags; }
		auto ClearTags() -> void { m_Tags.clear(); }

		virtual auto GetChildren() const -> const std::vector<std::unique_ptr<IWidget>>&
		{
			static const std::vector<std::unique_ptr<IWidget>> empty;
			return empty;
		}

		auto MatchesSearch( std::string_view query ) const -> bool
		{
			if ( query.empty() )
				return false;

			if ( query.front() == '#' )
			{
				query.remove_prefix( 1 );

				for ( const auto& tag : m_Tags )
					if ( EqualsIgnoreCase( tag , query ) )

						return true;
				return false;
			}

			return ContainsIgnoreCase( GetName() , query ) || ContainsIgnoreCase( GetDescription() , query );
		}

		// Matching containers render their contents once; otherwise search their children.
		auto CollectSearchMatches( std::string_view query , std::vector<IWidget*>& results ) -> void
		{
			if ( MatchesSearch( query ) )
			{
				results.push_back( this );
				return;
			}

			for ( const auto& child : GetChildren() )
				if ( child )
					child->CollectSearchMatches( query , results );
		}

	protected:
		std::string m_Name;
		std::string m_Description;

	private:
		static auto EqualsIgnoreCase( std::string_view left , std::string_view right ) -> bool
		{
			if ( left.size() != right.size() )
				return false;
			
			for ( auto i = size_t{ 0 }; i < left.size(); ++i )
				if ( std::tolower( static_cast<unsigned char>( left[i] ) ) != std::tolower( static_cast<unsigned char>( right[i] ) ) )
					return false;
			
			return true;
		}

		static auto ContainsIgnoreCase( std::string_view text , std::string_view query ) -> bool
		{
			if ( query.size() > text.size() )
				return false;
			
			for ( auto i = size_t{ 0 }; i <= text.size() - query.size(); ++i )
				if ( EqualsIgnoreCase( text.substr( i , query.size() ) , query ) )
					return true;
			
			return false;
		}

		std::vector<std::string> m_Tags;
	};
}
