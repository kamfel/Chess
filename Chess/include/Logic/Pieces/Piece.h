#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include <vector>

class Board;

class Piece : 
	public sf::Sprite
{
protected:

	sf::Vector2u m_pos;
	std::vector<sf::Vector2u> m_possible_moves;
	bool m_was_piece_moved = false;
	bool m_color; //true - white, false - black
	bool m_highlighted;

	bool IsMoveValid(const sf::Vector2u pos) const;

public:

	Piece();
	virtual ~Piece();

	bool Move(const sf::Vector2u& pos);
	virtual const std::vector<sf::Vector2u>& GeneratePossibleMoves(const Board& board) = 0;

	void Highlight() { m_highlighted = true; }
	void Unhighlight() { m_highlighted = false; }

	inline bool IsAtPos(const sf::Vector2u& pos) { return pos == m_pos; }
	inline bool IsBlack() const { return !m_color; }
	inline bool IsWhite() const { return m_color; }
	inline bool IsHighlighted() const { return m_highlighted; }

	void SetColor(bool color) { m_color = color; }
};
