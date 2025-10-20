#pragma once

#include "Vector2.hpp"

struct Rect_t
{
public:
	inline auto Center() const -> Vector2
	{
		return Vector2( x + w / 2.f , y + h / 2.f );
	}

public:
	inline auto GetMin() const -> Vector2
	{
		return Vector2( x , y );
	}

public:
	inline auto GetMax() const -> Vector2
	{
		return Vector2( x + w , y + h );
	}

public:
	inline auto GetSize() const -> Vector2
	{
		return Vector2( w , h );
	}

public:
	float x = 0.f;
	float y = 0.f;
	float w = 0.f;
	float h = 0.f;
};
