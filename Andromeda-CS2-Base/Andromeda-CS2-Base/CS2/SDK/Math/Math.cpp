#include "Math.hpp"

#include <cmath>
#include <ImGui/imgui_internal.h>

#include <CS2/SDK/FunctionListSDK.hpp>

namespace Math
{
    auto WorldToScreen( const Vector3& vIn , ImVec2& vOut ) -> bool
    {
        auto ret = false;

        Vector3 Out;

        ret = !( ScreenTransform( vIn , Out ) );

        if ( ImGui::GetCurrentContext() )
        {
            vOut.x = ( ( Out.m_x + 1.0f ) * 0.5f ) * ImGui::GetIO().DisplaySize.x;
            vOut.y = ImGui::GetIO().DisplaySize.y - ( ( ( Out.m_y + 1.0f ) * 0.5f ) * ImGui::GetIO().DisplaySize.y );
        }

        return ret;
    }

    auto WorldToScreen( const Vector3& vIn , Vector2& vOut ) -> bool
    {
        auto ret = false; 

        Vector3 Out;

        ret = !( ScreenTransform( vIn , Out ) );

        if ( ImGui::GetCurrentContext() )
        {
            vOut.m_x = ( ( Out.m_x + 1.0f ) * 0.5f ) * ImGui::GetIO().DisplaySize.x;
            vOut.m_y = ImGui::GetIO().DisplaySize.y - ( ( ( Out.m_y + 1.0f ) * 0.5f ) * ImGui::GetIO().DisplaySize.y );
        }

        return ret;
    }

    auto WorldToScreen( const Vector3& vIn , Vector3& vOut ) -> bool
    {
        auto ret = false;
        
        ret = !( ScreenTransform( vIn , vOut ) );

        if ( ImGui::GetCurrentContext() )
        {
            vOut.m_x = ( ( vOut.m_x + 1.0f ) * 0.5f ) * ImGui::GetIO().DisplaySize.x;
            vOut.m_y = ImGui::GetIO().DisplaySize.y - ( ( ( vOut.m_y + 1.0f ) * 0.5f ) * ImGui::GetIO().DisplaySize.y );
        }

        return ret;
    }

    auto AngleNormalize( float angle ) -> float
    {
        angle = std::fmod( angle , 360.f );

        if ( angle > 180.f )
            angle -= 360.f;
        else if ( angle < -180.f )
            angle += 360.f;

        return angle;
    }

    auto NormalizeAngles( QAngle& QAngle ) -> void
    {
        for ( auto i = 0; i < 3; i++ )
        {
            while ( QAngle[i] < -180.0f ) QAngle[i] += 360.0f;
            while ( QAngle[i] > 180.0f ) QAngle[i] -= 360.0f;
        }
    }

    auto ClampAngles( QAngle& QAngle ) -> void
    {
        if ( QAngle.m_x > 89.0f ) QAngle.m_x = 89.0f;
        else if ( QAngle.m_x < -89.0f ) QAngle.m_x = -89.0f;

        if ( QAngle.m_y > 180.0f ) QAngle.m_y = 180.0f;
        else if ( QAngle.m_y < -180.0f ) QAngle.m_y = -180.0f;

        QAngle.m_z = 0;
    }

    auto CalcAngle( const Vector3& src , const Vector3& dst ) -> QAngle
    {
        QAngle vAngle;

        Vector3 delta( ( src.m_x - dst.m_x ) , ( src.m_y - dst.m_y ) , ( src.m_z - dst.m_z ) );
        double hyp = sqrt( delta.m_x * delta.m_x + delta.m_y * delta.m_y );

        vAngle.m_x = float( atanf( float( delta.m_z / hyp ) ) * 57.295779513082f );
        vAngle.m_y = float( atanf( float( delta.m_y / delta.m_x ) ) * 57.295779513082f );
        vAngle.m_z = 0.0f;

        if ( delta.m_x >= 0.0 )
            vAngle.m_y += 180.0f;

        return vAngle;
    }

    auto VectorTransform( const Vector3& vIn1 , matrix3x4_t& vIn2 , Vector3& vOut ) -> void
    {
        vOut.m_x = vIn1.m_x * vIn2[0][0] + vIn1.m_y * vIn2[0][1] + vIn1.m_z * vIn2[0][2] + vIn2[0][3];
        vOut.m_y = vIn1.m_x * vIn2[1][0] + vIn1.m_y * vIn2[1][1] + vIn1.m_z * vIn2[1][2] + vIn2[1][3];
        vOut.m_z = vIn1.m_x * vIn2[2][0] + vIn1.m_y * vIn2[2][1] + vIn1.m_z * vIn2[2][2] + vIn2[2][3];
    }

    auto AngleVectors( const QAngle& QAngle , Vector3& vForward ) -> void
    {
        vec_t sp , sy , cp , cy;

        sp = sinf( DEG2RAD( QAngle[0] ) );
        cp = cosf( DEG2RAD( QAngle[0] ) );

        sy = sinf( DEG2RAD( QAngle[1] ) );
        cy = cosf( DEG2RAD( QAngle[1] ) );

        vForward.m_x = cp * cy;
        vForward.m_y = cp * sy;
        vForward.m_z = -sp;
    }

    auto AngleVectors( const QAngle& QAngle , Vector3& vForward , Vector3& vRight , Vector3& vUp ) -> void
    {
        vec_t sr , sp , sy , cr , cp , cy;

        sp = sinf( DEG2RAD( QAngle[0] ) );
        cp = cosf( DEG2RAD( QAngle[0] ) );

        sy = sinf( DEG2RAD( QAngle[1] ) );
        cy = cosf( DEG2RAD( QAngle[1] ) );

        sr = sinf( DEG2RAD( QAngle[2] ) );
        cr = cosf( DEG2RAD( QAngle[2] ) );

        vForward.m_x = ( cp * cy );
        vForward.m_y = ( cp * sy );
        vForward.m_z = ( -sp );

        vRight.m_x = ( -1 * sr * sp * cy + -1 * cr * -sy );
        vRight.m_y = ( -1 * sr * sp * sy + -1 * cr * cy );
        vRight.m_z = ( -1 * sr * cp );

        vUp.m_x = ( cr * sp * cy + -sr * -sy );
        vUp.m_y = ( cr * sp * sy + -sr * cy );
        vUp.m_z = ( cr * cp );
    }

    auto VectorAngles( const Vector3& vForward , QAngle& QAngle ) -> void
    {
        float tmp , yaw , pitch;

        if ( vForward[1] == 0.f && vForward[0] == 0.f )
        {
            yaw = 0.f;

            if ( vForward[2] > 0 )
                pitch = 270.f;
            else
                pitch = 90.f;
        }
        else
        {
            yaw = ( atan2f( vForward[1] , vForward[0] ) * 180.f / M_PI_F );

            if ( yaw < 0 )
                yaw += 360.f;

            tmp = sqrtf( vForward[0] * vForward[0] + vForward[1] * vForward[1] );
            pitch = ( atan2f( -vForward[2] , tmp ) * 180.f / M_PI_F );

            if ( pitch < 0 )
                pitch += 360.f;
        }

        QAngle[0] = pitch;
        QAngle[1] = yaw;
        QAngle[2] = 0;
    }

    auto SmoothAngles( QAngle QViewAngles , QAngle QAimAngles , QAngle& QOutAngles , float Smoothing ) -> void
    {
        if ( Smoothing < 1.f )
            Smoothing = 1.f;

        QAngle qDiffAngles = QAimAngles - QViewAngles;

        NormalizeAngles( qDiffAngles );
        ClampAngles( qDiffAngles );

        QOutAngles = qDiffAngles / Smoothing + QViewAngles;

        NormalizeAngles( QOutAngles );
        ClampAngles( QOutAngles );
    }

    auto RotateTriangle( std::array<Vector2 , 3>& points , float rotation ) -> void
    {
        const auto points_center = ( points.at( 0 ) + points.at( 1 ) + points.at( 2 ) ) / 3;
        
        for ( auto& point : points )
        {
            point -= points_center;

            const auto temp_x = point.m_x;
            const auto temp_y = point.m_y;

            const auto theta = DEG2RAD( rotation );
            const auto c = cosf( theta );
            const auto s = sinf( theta );

            point.m_x = temp_x * c - temp_y * s;
            point.m_y = temp_x * s + temp_y * c;

            point += points_center;
        }
    }

    auto CalculateCameraPosition( Vector3 anchorPos , float distance , QAngle viewAngles ) -> Vector3
    {
        float yaw = DEG2RAD( viewAngles.m_y );
        float pitch = DEG2RAD( viewAngles.m_x );

        float x = anchorPos.m_x + distance * cosf( yaw ) * cosf( pitch );
        float y = anchorPos.m_y + distance * sinf( yaw ) * cosf( pitch );
        float z = anchorPos.m_z + distance * sinf( pitch );

        return { x, y, z };
    }

    auto AnglesToPixels( QAngle SourceAngles , QAngle FinalAngles , float Sensitivity , float Pitch , float Yaw ) -> Vector3
    {
        QAngle delta = SourceAngles - FinalAngles;

        delta.Normalize();

        float xMove = ( -delta.m_x ) / ( Yaw * Sensitivity );
        float yMove = ( delta.m_y ) / ( Pitch * Sensitivity );

        return Vector3( yMove , xMove , 0.0f );
    }

    auto PixelsDeltaToAnglesDelta( Vector3 PixelsDelta , float Sensitivity , float Pitch , float Yaw ) -> QAngle
    {
        float xMove = ( -PixelsDelta.m_x ) * ( Yaw * Sensitivity );
        float yMove = ( PixelsDelta.m_y ) * ( Pitch * Sensitivity );

        return QAngle( yMove , xMove , 0.0f );
    }
}
