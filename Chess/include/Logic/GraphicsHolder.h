#pragma once
#include "SFML\Graphics\Texture.hpp"
#include "SFML/Graphics/Text.hpp"
#include <unordered_map>

class ResourceStream;

/*! \brief Class for holding textures
*
* Provides textures for the game
*/
class GraphicsHolder
{
private:
	
	sf::Text m_info; ///< Text for displaying check, stalemate and checkmate
	
	std::unordered_map<std::string, sf::Texture> m_texture_map; ///< Textures of pieces
	
	sf::Texture m_board_texture; ///< Texture of board
	 
	bool m_are_loaded; ///< True if textures are loaded successfully

public:

	/*! \brief Loads piece textures from input_stream
	*
	* Textures are expected to be on one picture alligned one by one
	* \param input_stream Stream from which the textures are loaded
	* \return true if succesful; false otherwise
	*/
	bool LoadTexturesFromStream(ResourceStream& input_stream);

	/*! \brief Loads board texture from input_stream
	*
	* \param input_stream Stream from which the texture is loaded
	* \return true if succesful; false otherwise
	*/
	bool LoadBoardTextureFromStream(ResourceStream& input_stream);

	/*! \brief Checks if textures are loaded
	*
	* \return true if textures are loaded; false otherwise
	*/
	bool AreTexturesLoaded() { return m_are_loaded; }

	/*! \brief Get piece texture
	*
	* Get texture with name texture_name; name convention "Color_Piecetype" eg. "Black_King"
	*
	* \exception std::out_of_bounds Throws when texture doesn't exist
	* \param texture_name Name of the texture
	* \return Texture of the piece
	*/
	const sf::Texture& GetTexture(const std::string& texture_name) const;

	/*! \brief Get board texture
	*
	* \return Texture of the board
	*/
	const sf::Texture& GetBoardTexture() const;

	GraphicsHolder();
	~GraphicsHolder();
};


