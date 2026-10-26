#pragma once

#include <AndromedaClient/CAndromedaGUI.hpp>

#include "../Resources/ResourceCatalog.hpp"

class CResourceManager final
{
public:
	auto LoadAll() -> void;
	auto Shutdown() -> void;
	auto GetTexture( EResource id ) const -> ImTextureRef;

private:
	ImTextureRef m_Textures[static_cast<int>( EResource::Count )] = {};
};

auto GetResourceManager() -> CResourceManager*;
