#pragma once

#include <string>

struct matrix3x4_t;

class QAngle;
class Vector4;

class Vector3
{
public:
	constexpr Vector3() = default;

	constexpr Vector3( float x , float y , float z ) :
		m_x( x ) , m_y( y ) , m_z( z )
	{
	}

	constexpr Vector3( const Vector3& vector ) = default;
	constexpr Vector3( Vector3&& ) = default;

	constexpr Vector3& operator=( const Vector3& ) = default;
	constexpr Vector3& operator=( Vector3&& ) = default;

	Vector3( const float* vector );

	auto Init( float x = 0.f , float y = 0.f , float z = 0.f ) -> void;

	auto ToArray() -> float*;
	auto ToArray() const -> const float*;

	auto At( unsigned int index ) -> float&;
	auto At( unsigned int index ) const -> const float;

	auto IsEqual( const Vector3& vector ) const -> bool;

	auto Add( const Vector3& vector ) -> void;
	auto Subtract( const Vector3& vector ) -> void;
	auto Multiply( const Vector3& vector ) -> void;
	auto Divide( const Vector3& vector ) -> void;

	auto Addf( float value ) -> void;
	auto Subtractf( float value ) -> void;
	auto Multiplyf( float value ) -> void;
	auto Dividef( float value ) -> void;

	auto IsZero() const -> bool;

	auto Dot( const Vector3& vector ) const -> float;
	auto Dot2D( const Vector3& vector ) const -> float;

	auto LengthSquared() const -> float;
	auto Length() const -> float;

	auto Length2DSquared() const -> float;
	auto Length2D() const -> float;

	auto DistanceSquared( const Vector3& vector ) const -> float;
	auto Distance( const Vector3& vector ) const -> float;
	auto Distance2D( const Vector3& vector ) const -> float;

	auto Normalize() -> float;
	auto NormalizeFast() -> void;
	auto Normalized() -> Vector3;

	auto MoveForward( const QAngle& angle , int distance ) -> Vector3;

	auto Rotated( float rad ) -> Vector3;

	auto Transform( const matrix3x4_t& transform ) const->Vector3;
	auto Cross( const Vector3& vector ) -> Vector3;

	auto ToVector4D( float w = 0.f ) const->Vector4;

	auto IsInvalid() const -> bool;

public:
	//auto operator = ( const Vector3& vector )->Vector3&;

	auto operator [] ( unsigned int index ) -> float&;
	auto operator [] ( unsigned int index ) const -> const float;

	auto operator == ( const Vector3& vector ) const -> bool;
	auto operator != ( const Vector3& vector ) const -> bool;

public:
	auto operator += ( const Vector3& vector )->Vector3&;
	auto operator -= ( const Vector3& vector )->Vector3&;
	auto operator *= ( const Vector3& vector )->Vector3&;
	auto operator /= ( const Vector3& vector )->Vector3&;

	auto operator += ( float value )->Vector3&;
	auto operator -= ( float value )->Vector3&;
	auto operator *= ( float value )->Vector3&;
	auto operator /= ( float value )->Vector3&;

	auto operator + ( const Vector3& vector ) const->Vector3;
	auto operator - ( const Vector3& vector ) const->Vector3;
	auto operator * ( const Vector3& vector ) const->Vector3;
	auto operator / ( const Vector3& vector ) const->Vector3;

	auto operator + ( float value ) const->Vector3;
	auto operator - ( float value ) const->Vector3;
	auto operator * ( float value ) const->Vector3;
	auto operator / ( float value ) const->Vector3;

	std::string __tostring() const;

public:
	static Vector3 Zero;

public:
	float m_x = 0.f;
	float m_y = 0.f;
	float m_z = 0.f;
};

#pragma pack(push, 16)

class Vector3Aligned : public Vector3
{
public:
	inline Vector3Aligned() = default;
	inline Vector3Aligned( float X , float Y , float Z )
	{
		Init( X , Y , Z );
	}

	explicit Vector3Aligned( const Vector3& vOther )
	{
		Init( vOther.m_x , vOther.m_y , vOther.m_z );
	}

	Vector3Aligned& operator=( const Vector3& vOther )
	{
		Init( vOther.m_x , vOther.m_y , vOther.m_z );
		return *this;
	}

	void Clear()
	{
		this->m_x = this->m_y = this->m_z = this->m_w = 0.f;
	}

	float m_w = 0.f;	// this space is used anyway
};

#pragma pack(pop)
