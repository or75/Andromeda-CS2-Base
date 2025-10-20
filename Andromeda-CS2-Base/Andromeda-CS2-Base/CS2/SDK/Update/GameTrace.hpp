#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <CS2/SDK/Math/Math.hpp>
#include <CS2/SDK/Types/CEntityData.hpp>
#include <CS2/SDK/FunctionListSDK.hpp>

class C_BaseEntity;

struct Ray_t
{
	Vector3 Start;
	Vector3 End;
	Vector3 Mins;
	Vector3 Maxs;
private:
	PAD( 0x4 );
public:
	uint8_t Type;
};

class CTraceInfo
{
public:
	float m_flUnk;
	float m_flDistance;
	float m_flDamage;
	uint32_t m_nPenCount;
	uint32_t m_nHandle;
	uint32_t m_nPenetrationFlags;
};

struct TraceData_t
{
private:
	PAD( 0x8 );
public:
	void* m_pArrayPtr;
private:
	PAD( 0x1810 );
public:
	int m_nCurrentSurface;
	CTraceInfo* m_pTraceInfo;
	int m_nTotalSurfaces;
	void* m_pUnkPtr;
private:
	PAD( 0xB8 );
public:
	Vector3 Start;
	Vector3 End;
private:
	PAD( 0x50 );
};

class CHitBox
{
public:
	const char* szName; // 0x0
	const char* szSurfaceProperty; // 0x8
	const char* szBoneName; // 0x10
	Vector3 vecMinBounds; // 0x18
	Vector3 vecMaxBounds; // 0x24
	float flShapeRadius; // 0x30
	uint32_t uBoneNameHash; // 0x34
	int nGroupId; // 0x38
	uint8_t nShapeType; // 0x3C
	bool bTranslationOnly; // 0x3D	
private:
	PAD( 0x2 ); // 0x3E
public:
	uint32_t uCRC; // 0x40	
	uint32_t colRender; // 0x44	
	uint16_t nHitBoxIndex; // 0x48	
};

class CGameTrace
{
public:
	void* pSurfaceProperties; // 0x00
	C_BaseEntity* pHitEntity; // 0x08
	CHitBox* pHitBox; // 0x10
private:
	PAD( 0x38 ); // 0x18
public:
	uint32_t nSurfaceFlags; // 0x50
private:
	PAD( 0x24 ); // 0x54
public:
	Vector3 vecStart; // 0x78 // initial position
	Vector3 vecEnd; // 0x84 // final position
	Vector3 vecNormal; // 0x90 // surface normal at impact
	Vector3 vecPosition;
private:
	PAD( 0x4 );
public:
	float flFraction; // 0xAC // time completed, 1.0 = didn't hit anything
private:
	PAD( 0x6 ); // 0xB0
public:
	uint8_t nShapeType; // 0xB6
	bool bStartSolid; // 0xB7 // if true, the initial point was in a solid area
private:
	PAD( 0x9 );
public:

	inline bool DidHit() const
	{
		return ( flFraction < 1.0f || bStartSolid );
	}

	inline bool IsVisible() const
	{
		return ( flFraction > 0.97f );
	}

	inline int GetHitGroup()
	{
		if ( pHitBox )
			return pHitBox->nGroupId;

		return 0;
	}

	inline int GetHitBoxID()
	{
		if ( pHitBox )
			return static_cast<int>( pHitBox->nHitBoxIndex );

		return 0;
	}
};

class CTraceFilter
{
public:
	CTraceFilter( std::uint64_t uMask , C_CSPlayerPawn* pPassEntity , int nLayer , uint16_t unkNum )
	{
		CTraceFilter_Constructor( this , uMask , pPassEntity , nLayer , unkNum );
	}

public:
	virtual ~CTraceFilter() {}
	virtual bool ShouldHitEntity( CEntityInstance* pEntity ) { return true; }

private:
	PAD( 0x38 );
};
