#pragma once
#include "SFML\System\InputStream.hpp"

/*! \brief Stream that loads from resources
*
*/
class ResourceStream :
	public sf::InputStream
{
private:

	char* m_data; ///< Buffer with data
	
	long long m_size; ///<Size of the buffer
	
	long long m_pos; ///< Current position in stream

public:
	ResourceStream();
	ResourceStream(unsigned id, const char* type);

	virtual ~ResourceStream();

	/*! \brief Loads from resource to buffer
	*
	* \param id Id of the resource
	* \param type Type of the resource eg. IMG, PNG, etc.
	* \return true if loading to buffer was succesful; false otherwise
	*/
	bool LoadResourceById(unsigned id, const char* type);

	/*! \brief Read chunk of data
	*
	* \param data Pointer to buffer to read to
	* \param size Size of buffer in bytes
	* \return Amount of bytes read, or -1 on error
	*/
	long long read(void* data, long long size) override;

	/*! \brief Set position in stream
	*
	* \param position New position in stream
	* \return The position actually sought to, or -1 on error 
	*/
	long long seek(long long position) override;

	/*! \brief Get the current reading position in the stream. 
	*
	* \return The current position, or -1 on error
	*/
	long long tell() override;

	/*! \brief Return the size of the stream. 
	*
	* \return The total number of bytes available in the stream, or -1 on error 
	*/
	long long getSize() override;

	/*! \brief Check if stream is opened
	*
	* \return true if opened; false otherwise
	*/
	bool is_open();
};
