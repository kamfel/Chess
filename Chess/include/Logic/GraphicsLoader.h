#pragma once
#include "SFML\Graphics\Texture.hpp"

class ResourceStream;

class GraphicsLoader
{
private:

	static sf::Texture m_WhitePawn;
	static sf::Texture m_WhiteBishop;
	static sf::Texture m_WhiteKnight;
	static sf::Texture m_WhiteRook;
	static sf::Texture m_WhiteKing; 
	static sf::Texture m_WhiteQueen;

	static sf::Texture m_BlackPawn;
	static sf::Texture m_BlackBishop;
	static sf::Texture m_BlackKnight;
	static sf::Texture m_BlackRook;
	static sf::Texture m_BlackKing;
	static sf::Texture m_BlackQueen;

	static bool m_are_loaded;

public:
	
	static const sf::Texture& GetTexture_WhitePawn();
	static const sf::Texture& GetTexture_WhiteBishop();
	static const sf::Texture& GetTexture_WhiteKnight();
	static const sf::Texture& GetTexture_WhiteRook();
	static const sf::Texture& GetTexture_WhiteKing();
	static const sf::Texture& GetTexture_WhiteQueen();

	static const sf::Texture& GetTexture_BlackPawn();
	static const sf::Texture& GetTexture_BlackBishop();
	static const sf::Texture& GetTexture_BlackKnight();
	static const sf::Texture& GetTexture_BlackRook();
	static const sf::Texture& GetTexture_BlackKing();
	static const sf::Texture& GetTexture_BlackQueen();

	static bool LoadTexturesFromStream(ResourceStream& input_stream);

	static bool AreTexturesLoaded() { return m_are_loaded; }

	GraphicsLoader();
	~GraphicsLoader();
};

bool GraphicsLoader::m_are_loaded = false;

