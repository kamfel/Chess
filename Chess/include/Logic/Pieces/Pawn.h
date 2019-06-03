#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
protected:

	std::vector<sf::Vector2u>& GeneratePossibleMovesForWhite(const Board& board);
	std::vector<sf::Vector2u>& GeneratePossibleMovesForBlack(const Board& board);

public:

	Pawn();
	virtual ~Pawn();

	const std::vector<sf::Vector2u>& GeneratePossibleMoves(const Board& board) override;

};

