#pragma once

#include <string>

class Vector3;

class QAngle
{
public:
	constexpr QAngle() = default;

	constexpr QAngle( float x , float y , float z ) :
		m_x( x ) , m_y( y ) , m_z( z )
	{
	}

	constexpr QAngle( const QAngle& angles ) = default;
	constexpr QAngle( QAngle&& ) = default;

	constexpr QAngle& operator=( const QAngle& angles ) = default;
	constexpr QAngle& operator=( QAngle&& ) = default;

	QAngle( const float* angles );

	auto Init( float x = 0.f , float y = 0.f , float z = 0.f ) -> void;

	auto ToArray() -> float*;
	auto ToArray() const -> const float*;

	auto At( unsigned int index ) -> float&;
	auto At( unsigned int index ) const -> const float;

	auto IsEqual( const QAngle& angles ) const -> bool;
	auto IsZero() const -> bool;

	auto Add( const QAngle& angles ) -> void;
	auto Subtract( const QAngle& angles ) -> void;
	auto Multiply( const QAngle& angles ) -> void;
	auto Divide( const QAngle& angles ) -> void;

	auto Add( float value ) -> void;
	auto Subtract( float value ) -> void;
	auto Multiply( float value ) -> void;
	auto Divide( float value ) -> void;

	auto Negate() -> void;
	auto Dot( const QAngle& angles ) const -> float;

	auto LengthSquared() const -> float;
	auto Length() const -> float;

	auto DistanceSquared( const QAngle& angles ) const -> float;
	auto Distance( const QAngle& angles ) const -> float;

	auto Normalize() -> void;
	auto Clamp() -> void;

public:

	auto operator [] ( unsigned int index ) -> float&;
	auto operator [] ( unsigned int index ) const -> const float;

	auto operator == ( const QAngle& angles ) const -> bool;
	auto operator != ( const QAngle& angles ) const -> bool;

public:
	auto operator += ( const QAngle& angles )->QAngle&;
	auto operator -= ( const QAngle& angles )->QAngle&;
	auto operator *= ( const QAngle& angles )->QAngle&;
	auto operator /= ( const QAngle& angles )->QAngle&;

	auto operator += ( float value )->QAngle&;
	auto operator -= ( float value )->QAngle&;
	auto operator *= ( float value )->QAngle&;
	auto operator /= ( float value )->QAngle&;

	auto operator + ( const QAngle& angles ) const->QAngle;
	auto operator - ( const QAngle& angles ) const->QAngle;
	auto operator * ( const QAngle& angles ) const->QAngle;
	auto operator / ( const QAngle& angles ) const->QAngle;

	auto operator + ( float value ) const->QAngle;
	auto operator - ( float value ) const->QAngle;
	auto operator * ( float value ) const->QAngle;
	auto operator / ( float value ) const->QAngle;

	std::string __tostring();

public:
	static QAngle Zero;

public:
	float m_x = 0.f;
	float m_y = 0.f;
	float m_z = 0.f;
};

inline auto operator * ( float value , const QAngle& angles ) -> QAngle
{
	return ( value * angles );
}
