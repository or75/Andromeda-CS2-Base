#pragma once

class CPageManager;

class CPageRegistry final
{
public:
	static auto RegisterAll( CPageManager* pPageManager ) -> void;
};
