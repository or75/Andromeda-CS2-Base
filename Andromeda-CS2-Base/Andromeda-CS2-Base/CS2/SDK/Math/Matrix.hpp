#pragma once

struct matrix3x4_t
{
public:
	auto At( unsigned int index ) -> float*;
	auto At( unsigned int index ) const -> const float*;

public:
	auto operator [] ( unsigned int index ) -> float*;
	auto operator [] ( unsigned int index ) const -> const float*;

private:
	float m_data[3][4] = { };
};

class VMatrix
{
public:
	VMatrix() = default;

	auto At( unsigned int index ) -> float*;
	auto At( unsigned int index ) const -> const float*;
	auto Reset() -> void;

	inline void Init(
		float m00 , float m01 , float m02 , float m03 ,
		float m10 , float m11 , float m12 , float m13 ,
		float m20 , float m21 , float m22 , float m23 ,
		float m30 , float m31 , float m32 , float m33
	)
	{
		m_data[0][0] = m00;
		m_data[0][1] = m01;
		m_data[0][2] = m02;
		m_data[0][3] = m03;

		m_data[1][0] = m10;
		m_data[1][1] = m11;
		m_data[1][2] = m12;
		m_data[1][3] = m13;

		m_data[2][0] = m20;
		m_data[2][1] = m21;
		m_data[2][2] = m22;
		m_data[2][3] = m23;

		m_data[3][0] = m30;
		m_data[3][1] = m31;
		m_data[3][2] = m32;
		m_data[3][3] = m33;
	}

	inline VMatrix(
		float m00 , float m01 , float m02 , float m03 ,
		float m10 , float m11 , float m12 , float m13 ,
		float m20 , float m21 , float m22 , float m23 ,
		float m30 , float m31 , float m32 , float m33 )
	{
		Init(
			m00 , m01 , m02 , m03 ,
			m10 , m11 , m12 , m13 ,
			m20 , m21 , m22 , m23 ,
			m30 , m31 , m32 , m33
		);
	}

public:
	auto operator [] ( unsigned int index ) -> float*;
	auto operator [] ( unsigned int index ) const -> const float*;

	float m_data[4][4] = { };
};

void MatrixMultiply( const VMatrix& src1 , const VMatrix& src2 , VMatrix& dst );
