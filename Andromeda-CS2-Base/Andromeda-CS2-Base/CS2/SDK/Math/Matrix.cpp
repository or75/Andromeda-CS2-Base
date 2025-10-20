#include "Matrix.hpp"
#include "QAngle.hpp"
#include "Vector3.hpp"

#include <cmath>

auto matrix3x4_t::At( unsigned int index ) -> float*
{
	return m_data[index];
}

auto matrix3x4_t::At( unsigned int index ) const -> const float*
{
	return m_data[index];
}

auto matrix3x4_t::operator [] ( unsigned int index ) -> float*
{
	return At( index );
}

auto matrix3x4_t::operator [] ( unsigned int index ) const -> const float*
{
	return At( index );
}

auto VMatrix::At( unsigned int index ) -> float*
{
	return m_data[index];
}

auto VMatrix::At( unsigned int index ) const -> const float*
{
	return m_data[index];
}

auto VMatrix::Reset()-> void
{
	memset( &m_data[0][0] , 0 , sizeof( m_data ) );
}

auto VMatrix::operator [] ( unsigned int index ) -> float*
{
	return At( index );
}

auto VMatrix::operator [] ( unsigned int index ) const -> const float*
{
	return At( index );
}

typedef float VMatrixRaw_t[4];

void MatrixCopy( const VMatrix& src , VMatrix& dst )
{
	if ( &src != &dst )
		memcpy( dst.m_data , src.m_data , 16 * sizeof( float ) );
}

void MatrixMultiply( const VMatrix& src1 , const VMatrix& src2 , VMatrix& dst )
{
	// Make sure it works if src1 == dst or src2 == dst
	VMatrix tmp1 , tmp2;
	const VMatrixRaw_t* s1 = ( &src1 == &dst ) ? tmp1.m_data : src1.m_data;
	const VMatrixRaw_t* s2 = ( &src2 == &dst ) ? tmp2.m_data : src2.m_data;

	if ( &src1 == &dst )
	{
		MatrixCopy( src1 , tmp1 );
	}
	if ( &src2 == &dst )
	{
		MatrixCopy( src2 , tmp2 );
	}

	dst[0][0] = s1[0][0] * s2[0][0] + s1[0][1] * s2[1][0] + s1[0][2] * s2[2][0] + s1[0][3] * s2[3][0];
	dst[0][1] = s1[0][0] * s2[0][1] + s1[0][1] * s2[1][1] + s1[0][2] * s2[2][1] + s1[0][3] * s2[3][1];
	dst[0][2] = s1[0][0] * s2[0][2] + s1[0][1] * s2[1][2] + s1[0][2] * s2[2][2] + s1[0][3] * s2[3][2];
	dst[0][3] = s1[0][0] * s2[0][3] + s1[0][1] * s2[1][3] + s1[0][2] * s2[2][3] + s1[0][3] * s2[3][3];

	dst[1][0] = s1[1][0] * s2[0][0] + s1[1][1] * s2[1][0] + s1[1][2] * s2[2][0] + s1[1][3] * s2[3][0];
	dst[1][1] = s1[1][0] * s2[0][1] + s1[1][1] * s2[1][1] + s1[1][2] * s2[2][1] + s1[1][3] * s2[3][1];
	dst[1][2] = s1[1][0] * s2[0][2] + s1[1][1] * s2[1][2] + s1[1][2] * s2[2][2] + s1[1][3] * s2[3][2];
	dst[1][3] = s1[1][0] * s2[0][3] + s1[1][1] * s2[1][3] + s1[1][2] * s2[2][3] + s1[1][3] * s2[3][3];

	dst[2][0] = s1[2][0] * s2[0][0] + s1[2][1] * s2[1][0] + s1[2][2] * s2[2][0] + s1[2][3] * s2[3][0];
	dst[2][1] = s1[2][0] * s2[0][1] + s1[2][1] * s2[1][1] + s1[2][2] * s2[2][1] + s1[2][3] * s2[3][1];
	dst[2][2] = s1[2][0] * s2[0][2] + s1[2][1] * s2[1][2] + s1[2][2] * s2[2][2] + s1[2][3] * s2[3][2];
	dst[2][3] = s1[2][0] * s2[0][3] + s1[2][1] * s2[1][3] + s1[2][2] * s2[2][3] + s1[2][3] * s2[3][3];

	dst[3][0] = s1[3][0] * s2[0][0] + s1[3][1] * s2[1][0] + s1[3][2] * s2[2][0] + s1[3][3] * s2[3][0];
	dst[3][1] = s1[3][0] * s2[0][1] + s1[3][1] * s2[1][1] + s1[3][2] * s2[2][1] + s1[3][3] * s2[3][1];
	dst[3][2] = s1[3][0] * s2[0][2] + s1[3][1] * s2[1][2] + s1[3][2] * s2[2][2] + s1[3][3] * s2[3][2];
	dst[3][3] = s1[3][0] * s2[0][3] + s1[3][1] * s2[1][3] + s1[3][2] * s2[2][3] + s1[3][3] * s2[3][3];
}
