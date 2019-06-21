#include "Logic\Pieces\Piece.h"
#include "Logic/Board.h"
#include "Definitions.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Texture.hpp"


sf::RectangleShape Piece::m_highlight_background;

bool Piece::IsMoveValid(const sf::Vector2i pos) const
{
	for (auto i = m_possible_moves.begin(); i != m_possible_moves.end(); i++)
	{
		if (*i == pos) return true;
	}
	return false;
}

Piece::Piece(COLOUR colour, const sf::Vector2i& pos)
	:m_colour(colour), m_pos(pos)
{
	sf::Vector2i display_pos = Board::ConvertBoardXYtoDisplayXY(pos);
	setPosition(sf::Vector2f(static_cast<float>(display_pos.x), static_cast<float>(display_pos.y)));

	m_highlight_background.setSize({ 60.0f, 60.0f });
	m_highlight_background.setFillColor(sf::Color::Blue);
}

Piece::~Piece()
{
}

bool Piece::Move(const sf::Vector2i& pos)
{
	if (!IsMoveValid(pos)) return false;

	m_pos = pos;
	sf::Vector2i display_pos = Board::ConvertBoardXYtoDisplayXY(pos);
	setPosition(sf::Vector2f(static_cast<float>(display_pos.x), static_cast<float>(display_pos.y)));

	return true;
}

void Piece::Highlight()
{
	m_highlighted = true;
}

void Piece::Unhighlight()
{
	m_highlighted = false;
}

void Piece::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_highlight_background.setPosition(this->getPosition());
	if (m_highlighted) {
		target.draw(m_highlight_background);
	}
	target.draw(*this);
}
