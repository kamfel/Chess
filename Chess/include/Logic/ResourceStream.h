#pragma once
#include "SFML\System\InputStream.hpp"
class ResourceStream :
	public sf::InputStream
{
private:

	//Buffer with data
	char* m_data;

	//Size of the buffer
	long long m_size;

	//Current position in stream
	long long m_pos;
public:
	ResourceStream();
	ResourceStream(unsigned id, const char* type);

	virtual ~ResourceStream();

	//Loads from resources to buffer
	//param id: resource id
	//param type: resource type eg. IMG, PNG, etc.
	bool LoadResourceById(unsigned id, const char* type);

	//Read chunk of data
	//param data: pointer to buffer
	//param size: size of buffer in bytes
	long long read(void* data, long long size) override;

	//Set position in stream
	//param position: new position in the stream
	long long seek(long long position) override;

	//Get current position in the stream
	long long tell() override;

	//Get buffer size
	long long getSize() override;

	//Check if data from resource was loaded
	bool is_open();
};
