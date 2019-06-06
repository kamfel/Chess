#include "Logic\GraphicsLoader.h"
#include "Logic\ResourceStream.h"


GraphicsLoader::GraphicsLoader()
{
}


GraphicsLoader::~GraphicsLoader()
{
}

const sf::Texture & GraphicsLoader::GetTexture_WhitePawn()
{
	return m_WhitePawn;
}

const sf::Texture & GraphicsLoader::GetTexture_WhiteBishop()
{
	return m_WhiteBishop;
}

const sf::Texture & GraphicsLoader::GetTexture_WhiteKnight()
{
	return m_WhiteKnight;
}

const sf::Texture & GraphicsLoader::GetTexture_WhiteRook() 
{
	return m_WhiteRook;
}

const sf::Texture & GraphicsLoader::GetTexture_WhiteKing() 
{
	return m_WhiteKing;
}

const sf::Texture & GraphicsLoader::GetTexture_WhiteQueen()
{
	return m_WhiteQueen;
}

const sf::Texture & GraphicsLoader::GetTexture_BlackPawn()
{
	return m_BlackPawn;
}

const sf::Texture & GraphicsLoader::GetTexture_BlackBishop()
{
	return m_BlackBishop;
}

const sf::Texture & GraphicsLoader::GetTexture_BlackKnight()
{
	return m_BlackKnight;
}

const sf::Texture & GraphicsLoader::GetTexture_BlackRook() 
{
	return m_BlackRook;
}

const sf::Texture & GraphicsLoader::GetTexture_BlackKing() 
{
	return m_BlackKing;
}

const sf::Texture & GraphicsLoader::GetTexture_BlackQueen()
{
	return m_BlackQueen;
}

bool GraphicsLoader::LoadTexturesFromStream(ResourceStream& input_stream)
{
	if (!input_stream.is_open()) {
		return false;
	}

	if (m_BlackQueen.loadFromStream(input_stream, { 0, 0, 60, 60 }) ||
		m_BlackKing.loadFromStream(input_stream, { 60, 0, 60, 60 }) ||
		m_BlackRook.loadFromStream(input_stream, { 120, 0, 60, 60 }) ||
		m_BlackKnight.loadFromStream(input_stream, { 180, 0, 60, 60 }) ||
		m_BlackBishop.loadFromStream(input_stream, { 240, 0, 60, 60 }) ||
		m_BlackPawn.loadFromStream(input_stream, { 300, 0, 60, 60 }) ||

		m_WhiteQueen.loadFromStream(input_stream, { 0, 60, 60, 60 }) ||
		m_WhiteKing.loadFromStream(input_stream, { 60, 60, 60, 60 }) ||
		m_WhiteRook.loadFromStream(input_stream, { 120, 60, 60, 60 }) ||
		m_WhiteKnight.loadFromStream(input_stream, { 180, 60, 60, 60 }) ||
		m_WhiteBishop.loadFromStream(input_stream, { 240, 60, 60, 60 }) ||
		m_WhitePawn.loadFromStream(input_stream, { 300, 60, 60, 60 })) 
	{
		m_are_loaded = false;
		return false;
	}

	m_are_loaded = true;
	return true;
}
