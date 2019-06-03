#pragma once
#include "Piece.h"
#include <vector>
class Rook :
	public Piece
{
private:


	std::vector<sf::Vector2u>& GeneratePossibleMovesForWhite(const Board& board) override;
	std::vector<sf::Vector2u>& GeneratePossibleMovesForBlack(const Board& board) override;
public:
	Rook();
	virtual ~Rook();

	const std::vector<sf::Vector2u> GeneratePossibleMoves(const Board& board);
};

