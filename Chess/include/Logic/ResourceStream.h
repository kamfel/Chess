#pragma once
#include "SFML\System\InputStream.hpp"
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

	long long read(void* data, long long size) override;
	long long seek(long long position) override;
	long long tell() override;

	long long getSize() override;
};
