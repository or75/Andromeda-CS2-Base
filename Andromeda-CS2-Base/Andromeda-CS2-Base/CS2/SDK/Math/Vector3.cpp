#include "Matrix.hpp"
#include "QAngle.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#include <cmath>

Vector3::Vector3( const float* vector )
	: m_x( vector[0] )
	, m_y( vector[1] )
	, m_z( vector[2] )
{
}

auto Vector3::Init( float x /* = 0.f */ , float y /* = 0.f */ , float z /* = 0.f */ ) -> void
{
	m_x = x;
	m_y = y;
	m_z = z;
}

auto Vector3::ToArray() -> float*
{
	return reinterpret_cast<float*>( this );
}

auto Vector3::ToArray() const -> const float*
{
	return reinterpret_cast<const float*>( this );
}

auto Vector3::At( unsigned int index ) -> float&
{
	auto data = ToArray();
	return data[index];
}

auto Vector3::At( unsigned int index ) const -> const float
{
	auto data = ToArray();
	return data[index];
}

auto Vector3::IsEqual( const Vector3& vector ) const -> bool
{
	return ( m_x == vector[0] &&
			 m_y == vector[1] &&
			 m_z == vector[2] );
}

auto Vector3::Dot( const Vector3& vector ) const -> float
{
	return ( m_x * vector[0] +
			 m_y * vector[1] +
			 m_z * vector[2] );
}

auto Vector3::Dot2D( const Vector3& vector ) const -> float
{
	return ( m_x * vector[0] +
			 m_y * vector[1] );
}

auto Vector3::LengthSquared() const -> float
{
	return Dot( *this );
}

auto Vector3::Length() const -> float
{
	return std::sqrt( LengthSquared() );
}

auto Vector3::Length2DSquared() const -> float
{
	return ( m_x * m_x +
			 m_y * m_y );
}

auto Vector3::Length2D() const -> float
{
	return std::sqrt( Length2DSquared() );
}

auto Vector3::Add( const Vector3& vector ) -> void
{
	m_x += vector[0];
	m_y += vector[1];
	m_z += vector[2];
}

auto Vector3::Subtract( const Vector3& vector ) -> void
{
	m_x -= vector[0];
	m_y -= vector[1];
	m_z -= vector[2];
}

auto Vector3::Multiply( const Vector3& vector ) -> void
{
	m_x *= vector[0];
	m_y *= vector[1];
	m_z *= vector[2];
}

auto Vector3::Divide( const Vector3& vector ) -> void
{
	m_x /= vector[0];
	m_y /= vector[1];
	m_z /= vector[2];
}

auto Vector3::Addf( float value ) -> void
{
	m_x += value;
	m_y += value;
	m_z += value;
}

auto Vector3::Subtractf( float value ) -> void
{
	m_x -= value;
	m_y -= value;
	m_z -= value;
}

auto Vector3::Multiplyf( float value ) -> void
{
	m_x *= value;
	m_y *= value;
	m_z *= value;
}

auto Vector3::Dividef( float value ) -> void
{
	m_x /= value;
	m_y /= value;
	m_z /= value;
}

auto Vector3::DistanceSquared( const Vector3& vector ) const -> float
{
	auto data = *this;
	data.Subtract( vector );
	return data.LengthSquared();
}

auto Vector3::Distance( const Vector3& vector ) const -> float
{
	auto data = *this;
	data.Subtract( vector );
	return data.Length();
}

auto Vector3::Distance2D( const Vector3& vector ) const -> float
{
	auto data = *this;
	data.Subtract( vector );
	return data.Length2D();
}

auto Vector3::Normalize() -> float
{
	auto length = Length();
	auto length_normal = 1.f / length;

	m_x *= length_normal;
	m_y *= length_normal;
	m_z *= length_normal;

	return length;
}

auto Vector3::NormalizeFast() -> void
{
	auto length = Length();
	auto length_normal = 1.f / length;

	m_x *= length_normal;
	m_y *= length_normal;
	m_z *= length_normal;
}

auto Vector3::Normalized()->Vector3
{
	auto inv_len = static_cast<float>( 1.0 / sqrt( pow( this->m_x , 2 ) + pow( this->m_y , 2 ) + pow( this->m_z , 2 ) ) );
	return Vector3( this->m_x * inv_len , this->m_y * inv_len , this->m_z * inv_len );
}

auto Vector3::MoveForward( const QAngle& angle , int distance ) -> Vector3
{
	Vector3 k = Vector3( cos( angle.m_y / 57.3f ) , sin( angle.m_y / 57.3f ) , 0 );
	k.Multiplyf( static_cast<float>( distance ) );
	k += *this;

	return Vector3( k.m_x , k.m_y , this->m_z );
}

auto Vector3::Rotated( float rad ) -> Vector3
{
	return Vector3( m_x * cos( rad ) - m_y * sin( rad ) , m_y * cos( rad ) + m_x * sin( rad ) , this->m_z );
}

auto Vector3::Transform( const matrix3x4_t& transform ) const -> Vector3
{
	return { Dot( transform[0] ) + transform[0][3],
			 Dot( transform[1] ) + transform[1][3],
			 Dot( transform[2] ) + transform[2][3] };
}

auto Vector3::IsZero() const -> bool
{
	return IsEqual( Vector3::Zero );
}

auto Vector3::Cross( const Vector3& vector ) -> Vector3
{
	return { m_y * vector[2] - m_z * vector[1],
			 m_z * vector[0] - m_x * vector[2],
			 m_x * vector[1] - m_y * vector[0] };
}

auto Vector3::ToVector4D( float w /*= 0.f*/ ) const -> Vector4
{
	return { m_x, m_y, m_z, w };
}

auto Vector3::operator [] ( unsigned int index ) -> float&
{
	return At( index );
}

auto Vector3::operator [] ( unsigned int index ) const -> const float
{
	return At( index );
}

auto Vector3::operator == ( const Vector3& vector ) const -> bool
{
	return IsEqual( vector );
}

auto Vector3::operator != ( const Vector3& vector ) const -> bool
{
	return !IsEqual( vector );
}

auto Vector3::operator += ( const Vector3& vector ) -> Vector3&
{
	Add( vector );
	return *this;
}

auto Vector3::operator -= ( const Vector3& vector ) -> Vector3&
{
	Subtract( vector );
	return *this;
}

auto Vector3::operator *= ( const Vector3& vector ) -> Vector3&
{
	Multiply( vector );
	return *this;
}

auto Vector3::operator /= ( const Vector3& vector ) -> Vector3&
{
	Divide( vector );
	return *this;
}

auto Vector3::operator += ( float value ) -> Vector3&
{
	Addf( value );
	return *this;
}

auto Vector3::operator -= ( float value ) -> Vector3&
{
	Subtractf( value );
	return *this;
}

auto Vector3::operator *= ( float value ) -> Vector3&
{
	Multiplyf( value );
	return *this;
}

auto Vector3::operator /= ( float value ) -> Vector3&
{
	Dividef( value );
	return *this;
}

auto Vector3::operator + ( const Vector3& vector ) const -> Vector3
{
	auto data = *this;
	data.Add( vector );
	return data;
}

auto Vector3::operator - ( const Vector3& vector ) const -> Vector3
{
	auto data = *this;
	data.Subtract( vector );
	return data;
}

auto Vector3::operator * ( const Vector3& vector ) const -> Vector3
{
	auto data = *this;
	data.Multiply( vector );
	return data;
}

auto Vector3::operator / ( const Vector3& vector ) const -> Vector3
{
	auto data = *this;
	data.Divide( vector );
	return data;
}

auto Vector3::operator + ( float value ) const -> Vector3
{
	auto data = *this;
	data.Addf( value );
	return data;
}

auto Vector3::operator - ( float value ) const -> Vector3
{
	auto data = *this;
	data.Subtractf( value );
	return data;
}

auto Vector3::operator * ( float value ) const -> Vector3
{
	auto data = *this;
	data.Multiplyf( value );
	return data;
}

auto Vector3::operator / ( float value ) const -> Vector3
{
	auto data = *this;
	data.Dividef( value );
	return data;
}

std::string Vector3::__tostring() const
{
	return std::string( "<Vector3(" + std::to_string( m_x ) + ", " + std::to_string( m_y ) + ", " + std::to_string( m_z ) + ")>" );
}

auto Vector3::IsInvalid() const -> bool
{
	return m_x == FLT_MAX
		&& m_y == FLT_MAX
		&& m_z == FLT_MAX;
}

Vector3 Vector3::Zero = { 0.f, 0.f, 0.f };
