#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Queen();

	// Odziedziczono za poœrednictwem elementu Piece
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;
};

