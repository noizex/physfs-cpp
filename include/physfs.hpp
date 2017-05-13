#ifndef _INCLUDE_PHYSFS_HPP_
#define _INCLUDE_PHYSFS_HPP_

#include <physfs.h>
#include <string>
#include <vector>
#include <iostream>

namespace PhysFS {

typedef enum {
	READ,
	WRITE,
	APPEND
} mode;

using std::string;

typedef std::vector<string> StringList;

typedef PHYSFS_uint8 uint8;

typedef PHYSFS_sint8 sint8;

typedef PHYSFS_uint16 uint16;

typedef PHYSFS_sint16 sint16;

typedef PHYSFS_uint32 uint32;

typedef PHYSFS_sint32 sint32;

typedef PHYSFS_uint64 uint64;

typedef PHYSFS_sint64 sint64;

typedef PHYSFS_StringCallback StringCallback;

typedef PHYSFS_EnumFilesCallback EnumFilesCallback;

typedef PHYSFS_Version Version;

typedef PHYSFS_Allocator Allocator;

typedef PHYSFS_ArchiveInfo ArchiveInfo;

typedef std::vector<ArchiveInfo> ArchiveInfoList;

typedef uint64 size_t;

class base_fstream {
protected:
	PHYSFS_File * const file;
public:
	base_fstream(PHYSFS_File * file);
	virtual ~base_fstream();
	size_t length();
};

class ifstream : public base_fstream, public std::istream {
public:
	ifstream(string const & filename);
	virtual ~ifstream();
};

class ofstream : public base_fstream, public std::ostream {
public:
	ofstream(string const & filename, mode writeMode = WRITE);
	virtual ~ofstream();
};

class fstream : public base_fstream, public std::iostream {
public:
	fstream(string const & filename, mode openMode = READ);
	virtual ~fstream();
};

Version getLinkedVersion();

int init(char const * argv0);

int deinit();

ArchiveInfoList supportedArchiveTypes();

string getDirSeparator();

void permitSymbolicLinks(bool allow);

StringList getCdRomDirs();

void getCdRomDirs(StringCallback callback, void * extra);

string getBaseDir();

string getUserDir();

string getWriteDir();

int setWriteDir(string const & newDir);

int removeFromSearchPath(string const & oldDir);

StringList getSearchPath();

void getSearchPath(StringCallback callback, void * extra);

int setSaneConfig(string const & orgName, string const & appName, string const & archiveExt, bool includeCdRoms, bool archivesFirst);

int mkdir(string const & dirName);

int deleteFile(string const & filename);

string getRealDir(string const & filename);

StringList enumerateFiles(string const & directory);

void enumerateFiles(string const & directory, EnumFilesCallback callback, void * extra);

bool exists(string const & filename);

bool isDirectory(string const & filename);

bool isSymbolicLink(string const & filename);

sint64 getLastModTime(string const & filename);

bool isInit();

bool symbolicLinksPermitted();

int setAllocator(Allocator const * allocator);

int mount(string const & newDir, string const & mountPoint, bool appendToPath);

string getMountPoint(string const & dir);

namespace Util {

sint16 swapSLE16(sint16 value);

uint16 swapULE16(uint16 value);

sint32 swapSLE32(sint32 value);

uint32 swapULE32(uint32 value);

sint64 swapSLE64(sint64 value);

uint64 swapULE64(uint64 value);

sint16 swapSBE16(sint16 value);

uint16 swapUBE16(uint16 value);

sint32 swapSBE32(sint32 value);

uint32 swapUBE32(uint32 value);

sint64 swapSBE64(sint64 value);

uint64 swapUBE64(uint64 value);

string utf8FromUcs4(uint32 const * src);

string utf8ToUcs4(char const * src);

string utf8FromUcs2(uint16 const * src);

string utf8ToUcs2(char const * src);

string utf8FromLatin1(char const * src);

}

}

#endif /* _INCLUDE_PHYSFS_HPP_ */
