#include "Logic\Pieces\Piece.h"



bool Piece::IsMoveValid(const sf::Vector2u pos) const
{
	for (auto i = m_possible_moves.begin(); i != m_possible_moves.end(); i++)
	{
		if (*i == pos) return true;
	}
	return false;
}

Piece::Piece()
{
	
}


Piece::~Piece()
{
}

bool Piece::Move(const sf::Vector2u& pos)
{
	if (!IsMoveValid(pos)) return false;
	
	m_pos = pos;
	//setPosition(Board::ConvertBoardXYtoDisplayXY(pos));

	return true;
}

const std::vector<sf::Vector2u>& Piece::GeneratePossibleMoves(const Board & board)
{
	if (IsWhite()) return GeneratePossibleMovesForWhite(board);
	else return GeneratePossibleMovesForBlack(board);
}

bool Piece::IsAtPos(const sf::Vector2u & pos)
{
	return m_pos == pos;
}

bool Piece::IsBlack() const
{
	return !m_color;
}

bool Piece::IsWhite() const
{
	return m_color;
}
