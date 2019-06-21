#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Rook();
	
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;
};

