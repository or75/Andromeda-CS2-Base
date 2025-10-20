#pragma once

#include "CBaseTypes.hpp"

template <class T>
class CStrongHandle
{
public:
    explicit operator T* ( ) const
    {
        return is_valid() ? reinterpret_cast<T*>( binding_->data ) : nullptr;
    }

    T* operator->() const
    {
        return is_valid() ? reinterpret_cast<T*>( binding_->data ) : nullptr;
    }

    [[nodiscard]] bool is_valid() const { return ( binding_ && binding_->data != nullptr ); }

private:
    const ResourceBindingBase_t* binding_;
};
