#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Bishop();

	// Odziedziczono za po�rednictwem elementu Piece
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;

};

 