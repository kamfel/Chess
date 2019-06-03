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
