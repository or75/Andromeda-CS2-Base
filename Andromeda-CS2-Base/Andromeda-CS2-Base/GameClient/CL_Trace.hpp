#pragma once

#include <Common/Common.hpp>
#include <CS2/SDK/Update/GameTrace.hpp>

#include "CL_Bones.hpp"

class QAngle;
class Vector3;

class CCSGOInput;
class C_BaseEntity;

class CL_Trace final
{
public:
	auto TraceToBoneEntity( CCSGOInput* pInput , const QAngle* AngleCorrection , QAngle* ViewAngleCorrection ) -> std::pair<uint64_t , C_BaseEntity*>;
	auto TraceToEntityEndPos( const Vector3* vEnd ) -> C_BaseEntity*;
};

auto GetCL_Trace() -> CL_Trace*;
