#include "Hook_GetMatricesForView.hpp"

#include <CS2/SDK/Math/Math.hpp>

#include <AndromedaClient/Features/CVisual/CVisual.hpp>

auto Hook_GetMatricesForView( void* rcx , void* view ,
                              VMatrix* pWorldToView ,
                              VMatrix* pViewToProjection ,
                              VMatrix* pWorldToProjection ,
                              VMatrix* pWorldToPixels ) -> void
{
    GetMatricesForView_o( rcx , view , pWorldToView , pViewToProjection , pWorldToProjection , pWorldToPixels );

    GetVisual()->CalculateBoundingBoxes();
}
