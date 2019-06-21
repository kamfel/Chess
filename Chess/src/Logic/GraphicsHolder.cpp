#include "Logic\GraphicsHolder.h"
#include "Logic\ResourceStream.h"
#include "SFML\Graphics\Texture.hpp"

const sf::Texture& GraphicsHolder::GetTexture(const std::string & texture_name) const
{
	return m_texture_map.at(texture_name);
}

const sf::Texture & GraphicsHolder::GetBoardTexture() const
{
	return m_board_texture;
}

GraphicsHolder::GraphicsHolder()
{
}


GraphicsHolder::~GraphicsHolder()
{
}

bool GraphicsHolder::LoadTexturesFromStream(ResourceStream& input_stream)
{
	//Check if stream is valid
	if (!input_stream.is_open()) {
		return false;
	}

	sf::Image image;
	image.loadFromStream(input_stream);

	//Load textures from stream to container
	if (m_texture_map["White_Pawn"].loadFromStream(input_stream, { 300, 60, 60, 60 }) &&
		m_texture_map["White_Bishop"].loadFromStream(input_stream, { 240, 60, 60, 60 }) &&
		m_texture_map["White_Knight"].loadFromStream(input_stream, { 180, 60, 60, 60 }) &&
		m_texture_map["White_Rook"].loadFromStream(input_stream, { 120, 60, 60, 60 }) &&
		m_texture_map["White_King"].loadFromStream(input_stream, { 60, 60, 60, 60 }) &&
		m_texture_map["White_Queen"].loadFromStream(input_stream, { 0, 60, 60, 60 }) &&
							
		m_texture_map["Black_Pawn"].loadFromStream(input_stream, { 300, 0, 60, 60 }) &&
		m_texture_map["Black_Bishop"].loadFromStream(input_stream, { 240, 0, 60, 60 }) &&
		m_texture_map["Black_Knight"].loadFromStream(input_stream, { 180, 0, 60, 60 }) &&
		m_texture_map["Black_Rook"].loadFromStream(input_stream, { 120, 0, 60, 60 }) &&
		m_texture_map["Black_King"].loadFromStream(input_stream, { 60, 0, 60, 60 }) &&
		m_texture_map["Black_Queen"].loadFromStream(input_stream, { 0, 0, 60, 60 }))
	{
		//Textures were loaded successfully
		m_are_loaded = true;
		return true;
	}
	else
	{
		//One or more textures didn't load successfully
		m_are_loaded = false;
		return false;
	}
}

bool GraphicsHolder::LoadBoardTextureFromStream(ResourceStream& input_stream)
{
	return m_board_texture.loadFromStream(input_stream);
}
