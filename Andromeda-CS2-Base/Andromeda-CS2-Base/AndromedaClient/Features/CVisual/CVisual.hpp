#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/Math/Rect_t.hpp>

class CCSPlayerController;

class IVisual
{
public:
	virtual void OnRender() = 0;
	virtual void OnClientOutput() = 0;
	virtual void OnCreateMove() = 0;
};

class CVisual final : public IVisual
{
public:
	virtual void OnRender() override;
	virtual void OnClientOutput() override;
	virtual void OnCreateMove() override;

private:
	enum EVisualBoxType_t : int32_t
	{
		BOX ,
		OUTLINE_BOX ,
		COAL_BOX ,
		OUTLINE_COAL_BOX ,
		CIRCLE_3D ,
	};

	auto OnRenderPlayerEsp( CCSPlayerController* pCCSPlayerController , const Rect_t& bBox , const bool bVisible ) -> void;

public:
	auto CalculateBoundingBoxes() -> void;
};

auto GetVisual() -> CVisual*;
