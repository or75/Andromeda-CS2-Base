#include "Matrix.hpp"
#include "Vector4.hpp"

#include <cmath>

Vector4::Vector4()
	: m_x( 0.f )
	, m_y( 0.f )
	, m_z( 0.f )
	, m_w( 0.f )
{
}

Vector4::Vector4( float x , float y , float z , float w )
	: m_x( x )
	, m_y( y )
	, m_z( z )
	, m_w( w )
{
}

Vector4::Vector4( const Vector4& vector )
	: m_x( vector[0] )
	, m_y( vector[1] )
	, m_z( vector[2] )
	, m_w( vector[3] )
{
}

Vector4::Vector4( const float* vector )
	: m_x( vector[0] )
	, m_y( vector[1] )
	, m_z( vector[2] )
	, m_w( vector[3] )
{
}

auto Vector4::Init( float x /* = 0.f */ , float y /* = 0.f */ , float z /* = 0.f */ , float w /*= 0.f*/ ) -> void
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;
}

auto Vector4::ToArray() -> float*
{
	return reinterpret_cast<float*>( this );
}

auto Vector4::ToArray() const -> const float*
{
	return reinterpret_cast<const float*>( this );
}

auto Vector4::At( unsigned int index ) -> float&
{
	auto data = ToArray();
	return data[index];
}

auto Vector4::At( unsigned int index ) const -> const float
{
	auto data = ToArray();
	return data[index];
}

auto Vector4::IsEqual( const Vector4& vector ) const -> bool
{
	return ( m_x == vector[0] &&
			 m_y == vector[1] &&
			 m_z == vector[2] &&
			 m_w == vector[3] );
}

auto Vector4::Dot( const Vector4& vector ) const -> float
{
	return ( m_x * vector[0] +
			 m_y * vector[1] +
			 m_z * vector[2] +
			 m_w * vector[3] );
}

auto Vector4::LengthSquared() const -> float
{
	return Dot( *this );
}

auto Vector4::Length() const -> float
{
	return std::sqrt( LengthSquared() );
}

auto Vector4::Add( const Vector4& vector ) -> void
{
	m_x += vector[0];
	m_y += vector[1];
	m_z += vector[2];
	m_w += vector[3];
}

auto Vector4::Subtract( const Vector4& vector ) -> void
{
	m_x -= vector[0];
	m_y -= vector[1];
	m_z -= vector[2];
	m_w -= vector[3];
}

auto Vector4::Multiply( const Vector4& vector ) -> void
{
	m_x *= vector[0];
	m_y *= vector[1];
	m_z *= vector[2];
	m_w *= vector[3];
}

auto Vector4::Divide( const Vector4& vector ) -> void
{
	m_x /= vector[0];
	m_y /= vector[1];
	m_z /= vector[2];
	m_w /= vector[3];
}

auto Vector4::Add( float value ) -> void
{
	m_x += value;
	m_y += value;
	m_z += value;
	m_w += value;
}

auto Vector4::Subtract( float value ) -> void
{
	m_x -= value;
	m_y -= value;
	m_z -= value;
	m_w -= value;
}

auto Vector4::Multiply( float value ) -> void
{
	m_x *= value;
	m_y *= value;
	m_z *= value;
	m_w *= value;
}

auto Vector4::Divide( float value ) -> void
{
	m_x /= value;
	m_y /= value;
	m_z /= value;
	m_w /= value;
}

auto Vector4::DistanceSquared( const Vector4& vector ) const -> float
{
	auto data = *this;
	data.Subtract( vector );
	return data.LengthSquared();
}

auto Vector4::Distance( const Vector4& vector ) const -> float
{
	auto data = *this;
	data.Subtract( vector );
	return data.Length();
}

auto Vector4::Normalize() -> float
{
	auto length = Length();
	auto length_normal = 1.f / length;

	m_x *= length_normal;
	m_y *= length_normal;
	m_z *= length_normal;
	m_w *= length_normal;

	return length;
}

auto Vector4::NormalizeFast() -> void
{
	auto length = Length();
	auto length_normal = 1.f / length;

	m_x *= length_normal;
	m_y *= length_normal;
	m_z *= length_normal;
	m_w *= length_normal;
}


auto Vector4::operator = ( const Vector4& vector ) -> Vector4&
{
	Init( vector[0] , vector[1] , vector[2] , vector[3] );
	return *this;
}

auto Vector4::operator [] ( unsigned int index ) -> float&
{
	return At( index );
}

auto Vector4::operator [] ( unsigned int index ) const -> const float
{
	return At( index );
}

auto Vector4::operator == ( const Vector4& vector ) const -> bool
{
	return IsEqual( vector );
}

auto Vector4::operator != ( const Vector4& vector ) const -> bool
{
	return !IsEqual( vector );
}

auto Vector4::operator += ( const Vector4& vector ) -> Vector4&
{
	Add( vector );
	return *this;
}

auto Vector4::operator -= ( const Vector4& vector ) -> Vector4&
{
	Subtract( vector );
	return *this;
}

auto Vector4::operator *= ( const Vector4& vector ) -> Vector4&
{
	Multiply( vector );
	return *this;
}

auto Vector4::operator /= ( const Vector4& vector ) -> Vector4&
{
	Divide( vector );
	return *this;
}

auto Vector4::operator += ( float value ) -> Vector4&
{
	Add( value );
	return *this;
}

auto Vector4::operator -= ( float value ) -> Vector4&
{
	Subtract( value );
	return *this;
}

auto Vector4::operator *= ( float value ) -> Vector4&
{
	Multiply( value );
	return *this;
}

auto Vector4::operator /= ( float value ) -> Vector4&
{
	Divide( value );
	return *this;
}

auto Vector4::operator + ( const Vector4& vector ) const -> Vector4
{
	auto data = *this;
	data.Add( vector );
	return data;
}

auto Vector4::operator - ( const Vector4& vector ) const -> Vector4
{
	auto data = *this;
	data.Subtract( vector );
	return data;
}

auto Vector4::operator * ( const Vector4& vector ) const -> Vector4
{
	auto data = *this;
	data.Multiply( vector );
	return data;
}

auto Vector4::operator / ( const Vector4& vector ) const -> Vector4
{
	auto data = *this;
	data.Divide( vector );
	return data;
}

auto Vector4::operator + ( float value ) const -> Vector4
{
	auto data = *this;
	data.Add( value );
	return data;
}

auto Vector4::operator - ( float value ) const -> Vector4
{
	auto data = *this;
	data.Subtract( value );
	return data;
}

auto Vector4::operator * ( float value ) const -> Vector4
{
	auto data = *this;
	data.Multiply( value );
	return data;
}

auto Vector4::operator / ( float value ) const -> Vector4
{
	auto data = *this;
	data.Divide( value );
	return data;
}

Vector4 Vector4::Zero = { 0.f, 0.f, 0.f, 0.f };
