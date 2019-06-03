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

	bool IsMoveValid(const sf::Vector2u pos) const;

	virtual std::vector<sf::Vector2u>& GeneratePossibleMovesForWhite(const Board& board) = 0;
	virtual std::vector<sf::Vector2u>& GeneratePossibleMovesForBlack(const Board& board) = 0;

public:

	Piece();
	virtual ~Piece();

	bool Move(const sf::Vector2u& pos);
	const std::vector<sf::Vector2u>& GeneratePossibleMoves(const Board& board);

	bool IsAtPos(const sf::Vector2u& pos);
	bool IsBlack() const;
	bool IsWhite() const;
};
