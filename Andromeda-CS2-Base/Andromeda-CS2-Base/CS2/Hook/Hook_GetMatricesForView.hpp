#pragma once

#include <Common/Common.hpp>

class VMatrix;

auto Hook_GetMatricesForView( void* rcx , void* view ,
                              VMatrix* pWorldToView ,
                              VMatrix* pViewToProjection ,
                              VMatrix* pWorldToProjection ,
                              VMatrix* pWorldToPixels ) -> void;

using GetMatricesForView_t = decltype( &Hook_GetMatricesForView );
inline GetMatricesForView_t GetMatricesForView_o = nullptr;
