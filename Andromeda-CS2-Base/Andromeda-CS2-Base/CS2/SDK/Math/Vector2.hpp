#pragma once

#include <cmath>
#include <cstdint>

class Vector2
{
public:
	constexpr Vector2() = default;

	constexpr Vector2( float x , float y ) :
		m_x( x ) , m_y( y )
	{
	}

	constexpr Vector2( const Vector2& ) = default;
	constexpr Vector2( Vector2&& ) = default;
	constexpr Vector2& operator=( const Vector2& ) = default;
	constexpr Vector2& operator=( Vector2&& ) = default;

	constexpr Vector2( const float* vector )
		: m_x( vector[0] )
		, m_y( vector[1] )
	{
	}

	constexpr auto Init( float x /* = 0.f */ , float y /* = 0.f */ ) -> void
	{
		m_x = x;
		m_y = y;
	}

	constexpr auto ToArray() -> float* { return &m_x; }
	constexpr auto ToArray() const -> const float* { return &m_x; }

	constexpr auto At( unsigned int index ) -> float&
	{
		auto data = ToArray();
		return data[index];
	}

	constexpr auto At( unsigned int index ) const -> const float
	{
		auto data = ToArray();
		return data[index];
	}

	constexpr auto IsEqual( const Vector2& vector ) const -> bool { return ( m_x == vector.m_x && m_y == vector.m_y ); }

	constexpr auto Add( const Vector2& vector ) -> void
	{
		m_x += vector[0];
		m_y += vector[1];
	}

	constexpr auto Subtract( const Vector2& vector ) -> void
	{
		m_x -= vector[0];
		m_y -= vector[1];
	}

	constexpr auto Multiply( const Vector2& vector ) -> void
	{
		m_x *= vector[0];
		m_y *= vector[1];
	}

	constexpr auto Divide( const Vector2& vector ) -> void
	{
		m_x /= vector[0];
		m_y /= vector[1];
	}

	constexpr auto Add( float value ) -> void
	{
		m_x += value;
		m_y += value;
	}

	constexpr auto Subtract( float value ) -> void
	{
		m_x -= value;
		m_y -= value;
	}

	constexpr auto Multiply( float value ) -> void
	{
		m_x *= value;
		m_y *= value;
	}

	constexpr auto Divide( float value ) -> void
	{
		m_x /= value;
		m_y /= value;
	}

	constexpr auto Negate() -> void
	{
		m_x = -m_x;
		m_y = -m_y;
	}

	constexpr auto IsZero() const -> bool { return IsEqual( Vector2{} ); }

	constexpr auto operator[]( unsigned int index ) -> float& { return At( index ); }

	constexpr auto operator[]( unsigned int index ) const -> const float { return At( index ); }

	constexpr auto operator==( const Vector2& vector ) const -> bool { return IsEqual( vector ); }

	constexpr auto operator!=( const Vector2& vector ) const -> bool { return !IsEqual( vector ); }

	constexpr auto operator+=( const Vector2& vector ) -> Vector2&
	{
		Add( vector );
		return *this;
	}

	constexpr auto operator-=( const Vector2& vector ) -> Vector2&
	{
		Subtract( vector );
		return *this;
	}

	constexpr auto operator*=( const Vector2& vector ) -> Vector2&
	{
		Multiply( vector );
		return *this;
	}

	constexpr auto operator/=( const Vector2& vector ) -> Vector2&
	{
		Divide( vector );
		return *this;
	}

	constexpr auto operator+=( float value ) -> Vector2&
	{
		Add( value );
		return *this;
	}

	constexpr auto operator-=( float value ) -> Vector2&
	{
		Subtract( value );
		return *this;
	}

	constexpr auto operator*=( float value ) -> Vector2&
	{
		Multiply( value );
		return *this;
	}

	constexpr auto operator/=( float value ) -> Vector2&
	{
		Divide( value );
		return *this;
	}

	constexpr auto operator+( const Vector2& vector ) const -> Vector2
	{
		auto data = *this;
		data.Add( vector );
		return data;
	}

	constexpr auto operator-( const Vector2& vector ) const -> Vector2
	{
		auto data = *this;
		data.Subtract( vector );
		return data;
	}

	constexpr auto operator*( const Vector2& vector ) const -> Vector2
	{
		auto data = *this;
		data.Multiply( vector );
		return data;
	}

	constexpr auto operator/( const Vector2& vector ) const -> Vector2
	{
		auto data = *this;
		data.Divide( vector );
		return data;
	}

	constexpr auto operator+( float value ) const -> Vector2
	{
		auto data = *this;
		data.Add( value );
		return data;
	}

	constexpr auto operator-( float value ) const -> Vector2
	{
		auto data = *this;
		data.Subtract( value );
		return data;
	}

	constexpr auto operator*( float value ) const -> Vector2
	{
		auto data = *this;
		data.Multiply( value );
		return data;
	}

	constexpr auto operator/( float value ) const -> Vector2
	{
		auto data = *this;
		data.Divide( value );
		return data;
	}

	constexpr auto Dot( const Vector2& vector ) const -> float { return ( m_x * vector[0] + m_y * vector[1] ); }

	constexpr auto LengthSquared() const -> float { return Dot( *this ); }

	constexpr auto DistanceSquared( const Vector2& vector ) const -> float
	{
		auto data = *this;
		data.Subtract( vector );
		return data.LengthSquared();
	}

	inline auto Length() const -> float { return std::sqrt( LengthSquared() ); }

	inline auto Distance( const Vector2& vector ) const -> float
	{
		auto data = *this;
		data.Subtract( vector );
		return data.Length();
	}

	inline auto Normalize() -> float
	{
		auto length = Length();
		auto length_normal = 1.f / length;

		m_x *= length_normal;
		m_y *= length_normal;

		return length;
	}

	inline auto NormalizeFast() -> void
	{
		auto length = Length();
		auto length_normal = 1.f / length;

		m_x *= length_normal;
		m_y *= length_normal;
	}

	float m_x = 0.f;
	float m_y = 0.f;
};

inline auto operator*( float value , const Vector2& vector ) -> Vector2 { return ( value * vector ); }
