#pragma once

#include <Common/Common.hpp>

enum eBasePatternSearchType : int32_t
{
	SEARCH_TYPE_NONE ,
	SEARCH_TYPE_PTR ,
	SEARCH_TYPE_CALL ,
	SEARCH_TYPE_PTR2 ,
	SEARCH_TYPE_PROC
};

class IBasePattern
{
public:
	virtual bool Search( bool SkipError ) = 0;
	virtual PVOID GetFunction() = 0;
	virtual const char* GetPatternName() = 0;
	virtual const char* GetDllName() = 0;
};

class CBasePattern final : public IBasePattern
{
public:
	CBasePattern( const char* szPatternName , const char* szPattern , const char* szDll , uint32_t Offset = 0 , eBasePatternSearchType Type = eBasePatternSearchType::SEARCH_TYPE_NONE );

public:
	virtual bool Search( bool SkipError = false ) override;
	virtual PVOID GetFunction() override;
	virtual const char* GetPatternName() override;
	virtual const char* GetDllName() override;

private:
	// !!! std::string_view crash on vmprotect !!!
	const char* PatternName = nullptr;
	const char* Pattern = nullptr;
	const char* Dll = nullptr;

private:
	PVOID pFunction = nullptr;
	uint32_t dwOffset = 0;
	eBasePatternSearchType m_Type = eBasePatternSearchType::SEARCH_TYPE_NONE;
};

#define DECLARATE_CS2_FUNCTION(Ret,Name,Decl,InterfaceSearch,DeclFn,ParamCall)\
	Ret Name Decl\
	{\
		using Fn = Ret ( __fastcall* ) DeclFn;\
		Fn Original = reinterpret_cast<Fn>( ##InterfaceSearch##_Search::##Name##Fn.GetFunction() );\
		return Original##ParamCall##;\
	}
