#include "Logic\ResourceStream.h"
#include <Windows.h>
#include "resource.h"


ResourceStream::ResourceStream()
	: m_size(-1), m_data(nullptr), m_pos(0)
{
}

ResourceStream::ResourceStream(unsigned id, const char* type)
{
	LoadResourceById(id, type);
}


ResourceStream::~ResourceStream()
{
}

bool ResourceStream::LoadResourceById(unsigned id, const char* type)
{
	HMODULE handle = GetModuleHandle(NULL);
	if (!handle) return false;

	HRSRC hrsrc = FindResource(handle, MAKEINTRESOURCE(id), type);
	if (!hrsrc) return false;

	HGLOBAL pngpieces = LoadResource(handle, hrsrc);
	if (!pngpieces) return false;

	m_size = SizeofResource(handle, hrsrc);
	m_data = static_cast<char*>(LockResource(pngpieces));
	m_pos = 0;

	return true;
}

long long ResourceStream::read(void * data, long long size)
{
	if (!data) return -1;
	
	long long bytes_left = m_size - m_pos;
	long long bytes_to_copy = bytes_left > size ? size : bytes_left;

	memcpy(data, &m_data[m_pos], static_cast<size_t>(bytes_to_copy));

	return bytes_to_copy;
}

long long ResourceStream::seek(long long position)
{
	if (position < 0) return -1;
	if (position >= m_size) return 1;

	m_pos = position;
	return 0;
}

long long ResourceStream::tell()
{
	return m_pos;
}

long long ResourceStream::getSize()
{
	return m_size;
}
