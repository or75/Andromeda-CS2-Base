#pragma once

#include <CS2/SDK/Math/Vector3.hpp>

#include <minwindef.h>
#include <cmath>

struct hsv_t
{
	constexpr hsv_t( float t_h , float t_s , float t_v ) noexcept :h( t_h ) , s( t_s ) , v( t_v ) {}
	constexpr hsv_t() noexcept = default;

	bool operator==( hsv_t& a ) noexcept
	{
		return this->h == a.h && this->s == a.s && this->v == a.v;
	}

	float h = 0.f , s = 0.f , v = 0.f;
};

struct Color
{
public:
	Color()
	{
		r = g = b = a = 0;
	}

	Color( BYTE red , BYTE green , BYTE blue , BYTE alpha = 255 )
	{
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}

	Color( int red , int gren , int blue , int alpha = 255 )
	{
		r = static_cast<BYTE>( red );
		g = static_cast<BYTE>( gren );
		b = static_cast<BYTE>( blue );
		a = static_cast<BYTE>( alpha );
	}

	void SetColor( int red , int gren , int blue , int alpha = 255 )
	{
		r = static_cast<BYTE>( red );
		g = static_cast<BYTE>( gren );
		b = static_cast<BYTE>( blue );
		a = static_cast<BYTE>( alpha );
	}

	uint32_t GetABGR() const
	{
		return (uint32_t)( a << 24 ) | ( b << 16 ) | ( g << 8 ) | r;
	}

	operator uint32_t() const noexcept { return rgba; }

	Vector3 Vec3() const
	{
		return Vector3( r , g , b );
	}

	static Color None() { return Color( 0 , 0 , 0 , 0 ); }
	static Color White() { return Color( 255 , 255 , 255 ); }
	static Color Black() { return Color( 0 , 0 , 0 ); }
	static Color Red() { return Color( 255 , 0 , 0 ); }
	static Color Green() { return Color( 0 , 255 , 0 ); }
	static Color Blue() { return Color( 0 , 0 , 255 ); }
	static Color Cyan() { return Color( 0 , 255 , 255 ); }
	static Color Yellow() { return Color( 255 , 255 , 0 ); }

	void FromString( const char* str )
	{
		this->a = 255;

		BYTE* pValue = &this->r;
		std::string strValue;

		size_t len = strlen( str );

		for ( size_t i = 0u; i < len; i++ )
		{
			if ( pValue == &this->a )
				break;

			if ( isspace( str[i] ) )
			{
				*pValue = static_cast<BYTE>( std::stoi( strValue ) );
				pValue++;
				strValue.clear();
			}
			else if ( isdigit( str[i] ) != 0 )
				strValue.push_back( str[i] );
		}

		if ( !strValue.empty() )
			*pValue = static_cast<BYTE>( std::stoi( strValue ) );
	}

	template<typename T>
	static inline void SWAP( T& a , T& b )
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	hsv_t ToValveHSV()
	{
		struct float_clr_t
		{
			float r , g , b;
		} in;

		in.r = this->r / 255.f;
		in.g = this->g / 255.f;
		in.b = this->b / 255.f;

		hsv_t out;
		float K = 0.f;

		if ( in.g < in.b )
		{
			SWAP( in.g , in.b );
			K = -1.f;
		}

		if ( in.r < in.g )
		{
			SWAP( in.r , in.g );
			K = -2.f / 6.f - K;
		}

		const float chroma = in.r - ( in.g < in.b ? in.g : in.b );

		out.h = fabsf( K + ( in.g - in.b ) / ( 6.f * chroma + 1e-20f ) ) * 360.f;
		out.s = chroma / ( in.r + 1e-20f );
		out.v = in.r;

		return out;
	}

	bool operator==( Color& a ) noexcept
	{
		return this->r == a.r
			&& this->g == a.g
			&& this->b == a.b
			&& this->a == a.a;
	}

	bool operator!=( Color& a ) noexcept
	{
		return !( *this == a );
	}

	static Color lerp( const Color& a , const Color& b , float t ) noexcept
	{
		return Color(
			static_cast<int>( std::lerp( a.r , b.r , t ) ) ,
			static_cast<int>( std::lerp( a.g , b.g , t ) ) ,
			static_cast<int>( std::lerp( a.b , b.b , t ) ) ,
			static_cast<int>( std::lerp( a.a , b.a , t ) )
		);
	}

public:
	union
	{
		struct
		{
			byte r , g , b , a;
		};

		uint32_t rgba = { 0 };
	};
};
