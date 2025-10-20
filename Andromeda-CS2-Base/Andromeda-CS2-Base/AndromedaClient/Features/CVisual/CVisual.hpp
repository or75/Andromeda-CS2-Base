#pragma once

#include <Common/Common.hpp>

#include <CS2/SDK/Math/Rect_t.hpp>

class CCSPlayerController;

class IVisual
{
public:
	virtual void OnRender() = 0;
	virtual void OnClientOutput() = 0;
};

class CVisual final : public IVisual
{
public:
	virtual void OnRender() override;
	virtual void OnClientOutput() override;

private:
	auto OnRenderPlayerEsp( CCSPlayerController* pCCSPlayerController , const Rect_t& bBox , const bool bVisible ) -> void;

public:
	auto CalculateBoundingBoxes() -> void;
};

auto GetVisual() -> CVisual*;
