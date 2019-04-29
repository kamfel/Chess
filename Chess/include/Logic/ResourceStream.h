#pragma once
#include "SFML\System\InputStream.hpp"
#include <memory>
class ResourceStream :
	public sf::InputStream
{
private:
	char* m_data;
	long long m_size;
	long long m_pos;
public:
	ResourceStream();
	ResourceStream(unsigned id, const char* type);

	virtual ~ResourceStream();

	bool LoadResourceById(unsigned id, const char* type);

	long long read(void* data, long long size);
	long long seek(long long position);
	long long tell();

	long long getSize();
};
