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

struct TraceData_t
{
private:
	PAD( 0x8 );
public:
	void* m_pArrayPtr;
private:
	PAD( 0x1C10 );
public:
	int m_nCurrentSurface;
private:
	PAD( 0x4 );
public:
	CTraceInfo* m_pTraceInfo;
	int m_nTotalSurfaces;
private:
	PAD( 0x4 );
public:
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
	C_BaseEntity* pHitEntity;         // 0x08
	CHitBox* pHitBox;                 // 0x10

private:
	PAD( 0x38 );                        // 0x18

public:
	uint32_t nSurfaceFlags;            // 0x50

private:
	PAD( 0x24 );                         // 0x54

public:
	Vector3 vecStart;                  // 0x78
	Vector3 vecEnd;                    // 0x84
	Vector3 vecNormal;                 // 0x90

private:
	PAD( 0x0C );                         // 0x9C

public:
	char pad_00A8[0x4];                // 0xA8

	float flFraction;                  // 0xAC

private:
	PAD( 0x0B );                         // 0xB0

public:
	bool bStartSolid;                  // 0xBB

private:
	PAD( 0x4 );                          // 0xBC
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
	PAD( 0x100 );
};
