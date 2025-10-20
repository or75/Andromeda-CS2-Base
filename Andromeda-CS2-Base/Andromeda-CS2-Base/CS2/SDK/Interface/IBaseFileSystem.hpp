#pragma once

#include <CS2/SDK/AppFramework/IAppSystem.hpp>

#define FILE_SYSTEM_INTERFACE_VERSION "VFileSystem017"

#define FILESYSTEM_MAX_SEARCH_PATHS 128
#define FILESYSTEM_INVALID_HANDLE	( FileHandle_t )0

class CUtlBuffer;

typedef void* FileHandle_t;

enum FileSystemSeek_t
{
	FILESYSTEM_SEEK_HEAD = SEEK_SET ,
	FILESYSTEM_SEEK_CURRENT = SEEK_CUR ,
	FILESYSTEM_SEEK_TAIL = SEEK_END ,
};

typedef void* ( *FSAllocFunc_t )( const char* pszFilename , unsigned nBytes );

class IBaseFileSystem : public IAppSystem
{
public:
	virtual int        Read( void* pOutput , int size , FileHandle_t file ) = 0;
	virtual int        Write( void const* pInput , int size , FileHandle_t file ) = 0;

	// if pathID is NULL, all paths will be searched for the file
	virtual FileHandle_t  Open( const char* pFileName , const char* pOptions , const char* pathID = 0 ) = 0;
	virtual void      Close( FileHandle_t file ) = 0;

	virtual void      Seek( FileHandle_t file , int pos , FileSystemSeek_t seekType ) = 0;
	virtual unsigned int  Tell( FileHandle_t file ) = 0;
	virtual unsigned int  Size( FileHandle_t file ) = 0;
	virtual unsigned int  Size( const char* pFileName , const char* pPathID = 0 ) = 0;

	virtual void      Flush( FileHandle_t file ) = 0;
	virtual bool      Precache( const char* pFileName , const char* pPathID = 0 ) = 0;

	virtual bool      FileExists( const char* pFileName , const char* pPathID = 0 ) = 0;
	virtual bool      IsFileWritable( char const* pFileName , const char* pPathID = 0 ) = 0;
	virtual bool      SetFileWritable( char const* pFileName , bool writable , const char* pPathID = 0 ) = 0;

	virtual long      GetFileTime( const char* pFileName , const char* pPathID = 0 ) = 0;

	//--------------------------------------------------------
	// Reads/writes files to utlbuffers. Use this for optimal read performance when doing open/read/close
	//--------------------------------------------------------
	virtual bool      ReadFile( const char* pFileName , const char* pPath , CUtlBuffer& buf , int nMaxBytes = 0 , int nStartingByte = 0 , FSAllocFunc_t pfnAlloc = NULL ) = 0;
	virtual bool      WriteFile( const char* pFileName , const char* pPath , CUtlBuffer& buf ) = 0;
	virtual bool      UnzipFile( const char* pFileName , const char* pPath , const char* pDestination ) = 0;
};
