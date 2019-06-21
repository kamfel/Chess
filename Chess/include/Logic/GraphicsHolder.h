#pragma once
#include "SFML\Graphics\Texture.hpp"
#include "SFML/Graphics/Text.hpp"
#include <unordered_map>

class ResourceStream;

class GraphicsHolder
{
private:

	//Text for displaying check, stalemate and checkmate
	sf::Text m_info;

	//Textures of pieces
	std::unordered_map<std::string, sf::Texture> m_texture_map;

	//Texture of board
	sf::Texture m_board_texture;

	//True if textures are loaded successfully
	bool m_are_loaded;

public:

	//Loads textures from input_stream; returns true if successful
	bool LoadTexturesFromStream(ResourceStream& input_stream);

	//Loads board from input_stream; returns true if succesful
	bool LoadBoardTextureFromStream(ResourceStream& input_stream);

	//Returns true if textures are loaded
	bool AreTexturesLoaded() { return m_are_loaded; }

	//Get texture with name texture_name; name convention "Color_Piecetype" eg. "Black_King"; throws std::out_of_bounds when texture doesn't exist
	const sf::Texture& GetTexture(const std::string& texture_name) const;

	//Get board texture
	const sf::Texture& GetBoardTexture() const;

	GraphicsHolder();
	~GraphicsHolder();
};


