#pragma once

class Vector4
{
public:
	Vector4();
	Vector4( float x , float y , float z , float w );
	Vector4( const Vector4& vector );
	Vector4( const float* vector );

	auto Init( float x = 0.f , float y = 0.f , float z = 0.f , float w = 0.f ) -> void;

	auto ToArray() -> float*;
	auto ToArray() const -> const float*;

	auto At( unsigned int index ) -> float&;
	auto At( unsigned int index ) const -> const float;

	auto IsEqual( const Vector4& vector ) const -> bool;

	auto Add( const Vector4& vector ) -> void;
	auto Subtract( const Vector4& vector ) -> void;
	auto Multiply( const Vector4& vector ) -> void;
	auto Divide( const Vector4& vector ) -> void;

	auto Add( float value ) -> void;
	auto Subtract( float value ) -> void;
	auto Multiply( float value ) -> void;
	auto Divide( float value ) -> void;

	auto Dot( const Vector4& vector ) const -> float;

	auto LengthSquared() const -> float;
	auto Length() const -> float;

	auto DistanceSquared( const Vector4& vector ) const -> float;
	auto Distance( const Vector4& vector ) const -> float;

	auto Normalize() -> float;
	auto NormalizeFast() -> void;

public:
	auto operator = ( const Vector4& vector )->Vector4&;

	auto operator [] ( unsigned int index ) -> float&;
	auto operator [] ( unsigned int index ) const -> const float;

	auto operator == ( const Vector4& vector ) const -> bool;
	auto operator != ( const Vector4& vector ) const -> bool;

public:
	auto operator += ( const Vector4& vector )->Vector4&;
	auto operator -= ( const Vector4& vector )->Vector4&;
	auto operator *= ( const Vector4& vector )->Vector4&;
	auto operator /= ( const Vector4& vector )->Vector4&;

	auto operator += ( float value )->Vector4&;
	auto operator -= ( float value )->Vector4&;
	auto operator *= ( float value )->Vector4&;
	auto operator /= ( float value )->Vector4&;

	auto operator + ( const Vector4& vector ) const->Vector4;
	auto operator - ( const Vector4& vector ) const->Vector4;
	auto operator * ( const Vector4& vector ) const->Vector4;
	auto operator / ( const Vector4& vector ) const->Vector4;

	auto operator + ( float value ) const->Vector4;
	auto operator - ( float value ) const->Vector4;
	auto operator * ( float value ) const->Vector4;
	auto operator / ( float value ) const->Vector4;

public:
	static Vector4 Zero;

private:
	float m_x = 0.f;
	float m_y = 0.f;
	float m_z = 0.f;
	float m_w = 0.f;
};

inline auto operator * ( float value , const Vector4& vector ) -> Vector4
{
	return ( value * vector );
}
