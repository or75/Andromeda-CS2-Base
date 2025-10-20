#pragma once

#include <Common/Common.hpp>
#include <array>

#include <ImGui/imgui.h>

#include "Matrix.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "QAngle.hpp"

typedef float vec_t;

#define X_INDEX	0
#define Y_INDEX	1
#define Z_INDEX	2

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define M_PI_F ((float)(M_PI))

#ifndef RAD2DEG
#define RAD2DEG( x ) ( (float)(x) * (float)(180.f / M_PI_F) )
#endif

#ifndef DEG2RAD
#define DEG2RAD( x ) ( (float)(x) * (float)(M_PI_F / 180.f) )
#endif

namespace Math
{
	auto WorldToScreen( const Vector3& vIn , ImVec2& vOut ) -> bool;
	auto WorldToScreen( const Vector3& vIn , Vector2& vOut ) -> bool;
	auto WorldToScreen( const Vector3& vIn , Vector3& vOut ) -> bool;

	auto AngleNormalize( float angle ) -> float;
	auto NormalizeAngles( QAngle& QAngle ) -> void;
	auto ClampAngles( QAngle& QAngle ) -> void;
	auto CalcAngle( const Vector3& src , const Vector3& dst ) -> QAngle;
	auto VectorTransform( const Vector3& vIn1 , matrix3x4_t& vIn2 , Vector3& vOut ) -> void;
	auto AngleVectors( const QAngle& QAngle , Vector3& vForward ) -> void;
	auto AngleVectors( const QAngle& QAngle , Vector3& vForward , Vector3& vRight , Vector3& vUp ) -> void;
	auto VectorAngles( const Vector3& vForward , QAngle& QAngle ) -> void;
	auto SmoothAngles( QAngle QViewAngles , QAngle QAimAngles , QAngle& QOutAngles , float Smoothing = 1.f ) -> void;
	auto RotateTriangle( std::array<Vector2 , 3>& points , float rotation ) -> void;
	auto CalculateCameraPosition( Vector3 anchorPos , float distance , QAngle viewAngles ) -> Vector3;
	auto AnglesToPixels( QAngle SourceAngles , QAngle FinalAngles , float Sensitivity , float Pitch , float Yaw ) -> Vector3;
	auto PixelsDeltaToAnglesDelta( Vector3 PixelsDelta , float Sensitivity , float Pitch , float Yaw ) -> QAngle;
}
