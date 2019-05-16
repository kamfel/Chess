#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
protected:

	std::vector<sf::Vector2u>& GeneratePossibleMovesForWhite(const Board& board) override;
	std::vector<sf::Vector2u>& GeneratePossibleMovesForBlack(const Board& board) override;

public:

	Pawn();
	virtual ~Pawn();

};

