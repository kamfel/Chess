#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Knight();

	// Odziedziczono za po�rednictwem elementu Piece
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;
};

