#pragma once

#include <vector>
#include <ImGui/imgui.h>

#include <Common/Common.hpp>
#include <CS2/SDK/Math/Vector3.hpp>
#include <AndromedaClient/Fonts/CFont.hpp>

// RenderObject:

class IRenderObject
{
public:
	virtual void OnRender() = 0;
};

// Render Classes:

class CRenderObjectDrawLine final : public IRenderObject
{
public:
	CRenderObjectDrawLine( const ImVec2& Start , const ImVec2& End , const ImColor& Color , const float thickness = 1.f ) :
		m_Start( Start ) , m_End( End ) , m_Color( Color ) , m_Thickness( thickness )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Start;
	ImVec2 m_End;
	ImColor m_Color;
	float m_Thickness = 1.f;
};

class CRenderObjectDrawBox final : public IRenderObject
{
public:
	CRenderObjectDrawBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) :
		m_Min( Min ) , m_Max( Max ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Min , m_Max;
	ImColor m_Color;
};

class CRenderObjectDrawOutlineBox final : public IRenderObject
{
public:
	CRenderObjectDrawOutlineBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) :
		m_Min( Min ) , m_Max( Max ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Min , m_Max;
	ImColor m_Color;
};

class CRenderObjectDrawCoalBox final : public IRenderObject
{
public:
	CRenderObjectDrawCoalBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) :
		m_Min( Min ) , m_Max( Max ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Min , m_Max;
	ImColor m_Color;
};

class CRenderObjectDrawOutlineCoalBox final : public IRenderObject
{
public:
	CRenderObjectDrawOutlineCoalBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) :
		m_Min( Min ) , m_Max( Max ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Min , m_Max;
	ImColor m_Color;
};

class CRenderObjectDrawFillBox final : public IRenderObject
{
public:
	CRenderObjectDrawFillBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) :
		m_Min( Min ) , m_Max( Max ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Min , m_Max;
	ImColor m_Color;
};

class CRenderObjectDrawRectFilledMultiColor final : public IRenderObject
{
public:
	CRenderObjectDrawRectFilledMultiColor( const ImVec2& Min , const ImVec2& Max , 
										   const ImU32 col_upr_left , 
										   const ImU32 col_upr_right , 
										   const ImU32 col_bot_right , 
										   const ImU32 col_bot_left ) :
		m_Min( Min ) , m_Max( Max ) , 
		m_Col_upr_left( col_upr_left ) , 
		m_Col_upr_right( col_upr_right ) ,
		m_Col_bot_right( col_bot_right ) ,
		m_Col_bot_left( col_bot_left )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Min , m_Max;
	ImU32 m_Col_upr_left , m_Col_upr_right , m_Col_bot_right , m_Col_bot_left;
};

class CRenderObjectDrawCircle final : public IRenderObject
{
public:
	CRenderObjectDrawCircle( const ImVec2& Center , float radius , const ImColor& Color ) :
		m_Center( Center ) , m_flRadius( radius ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Center;
	float m_flRadius;
	ImColor m_Color;
};

class CRenderObjectDrawCircleFilled final : public IRenderObject
{
public:
	CRenderObjectDrawCircleFilled( const ImVec2& Center , float radius , const ImColor& Color ) :
		m_Center( Center ) , m_flRadius( radius ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Center;
	float m_flRadius;
	ImColor m_Color;
};

class CRenderObjectDrawCircle3D final : public IRenderObject
{
public:
	CRenderObjectDrawCircle3D( const Vector3& Center , float radius , const ImColor& Color ) :
		m_Center( Center ) , m_flRadius( radius ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	Vector3 m_Center;
	float m_flRadius;
	ImColor m_Color;
};

class CRenderObjectDrawTriangleFilled final : public IRenderObject
{
public:
	CRenderObjectDrawTriangleFilled( const ImVec2& Center , const ImVec2& pos1 , const ImVec2& pos2 , const ImColor& Color ) :
		m_Center( Center ) , m_pos1( pos1 ) , m_pos2( pos2 ) , m_Color( Color )
	{
	};

public:
	virtual void OnRender() override;

private:
	ImVec2 m_Center , m_pos1 , m_pos2;
	ImColor m_Color;
};

class CRenderObjectDrawString final : public IRenderObject
{
public:
	CRenderObjectDrawString( CFont* pFont , const int X , const int Y , const int Flags , const ImColor& Color , const char* szText ) :
		m_pFont( pFont ) , m_x( X ) , m_y( Y ) , m_Flags( Flags ) , m_Color( Color ) , m_Text( szText )
	{
	};

public:
	virtual void OnRender() override;

private:
	CFont* m_pFont = nullptr;
	int m_x = 0;
	int m_y = 0;
	int m_Flags = FW1_CENTER;
	ImColor m_Color;
	std::string m_Text;
};

class CRenderObjectDrawWeaponIcon final : public IRenderObject
{
public:
	CRenderObjectDrawWeaponIcon( const char* m_pszItemBaseName , const float x , const float y ) :
		m_ItemBaseName( m_pszItemBaseName ) , m_x( x ) , m_y( y )
	{
	};

public:
	virtual void OnRender() override;

private:
	std::string m_ItemBaseName;
	float m_x , m_y;
};

// Stack System:

class CRenderStackSystem final
{
	using RenderObjectsVec_t = std::vector<std::shared_ptr<IRenderObject>>;
	using Lock_t = std::mutex;

public:
	auto DrawLine( const ImVec2& Start , const ImVec2& End , const ImColor& Color , const float thickness = 1.f ) -> void;
	auto DrawBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void;
	auto DrawOutlineBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void;
	auto DrawCoalBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void;
	auto DrawOutlineCoalBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void;
	auto DrawFillBox( const ImVec2& Min , const ImVec2& Max , const ImColor& Color ) -> void;
	auto DrawRectFilledMultiColor( const ImVec2& Min , const ImVec2& Max , const ImU32 col_upr_left , const ImU32 col_upr_right , const ImU32 col_bot_right , const ImU32 col_bot_left ) -> void;
	auto DrawCircle( const ImVec2& Center , float radius , const ImColor& Color ) -> void;
	auto DrawCircleFilled( const ImVec2& Center , const float radius , const ImColor& Color ) -> void;
	auto DrawCircle3D( const Vector3& Center , float radius , const ImColor& Color ) -> void;
	auto DrawTriangleFilled( const ImVec2& Center , const ImVec2& pos1 , const ImVec2& pos2 , const ImColor& Color ) -> void;

public:
	auto DrawString( CFont* pFont , const int X , const int Y , const int Flags , const ImColor& Color , const char* fmt , ... ) -> void;
	auto DrawString( CFont* pFont , const ImVec2& Pos , const int Flags , const ImColor& Color , const char* fmt , ... ) -> void;

public:
	auto OnClientOutput() -> void;
	auto OnRenderStack() -> void;

private:
	RenderObjectsVec_t m_vecUpdateBuffer; // Update buffer, lock is used for it
	std::atomic<std::shared_ptr<RenderObjectsVec_t>> m_pSharedBuffer; // Shared buffer, m_bSharedBufferReady notices about update
	std::atomic_bool m_bSharedBufferReady = false;
	std::shared_ptr<RenderObjectsVec_t> m_pRenderBuffer; // Present buffer

	Lock_t m_Lock;

private:
	static constexpr auto g_BufferSize = 64;
};

auto GetRenderStackSystem() -> CRenderStackSystem*;
