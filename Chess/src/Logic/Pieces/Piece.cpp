#include "Logic\Pieces\Piece.h"



Piece::Piece()
{
	
}


Piece::~Piece()
{
}

bool Piece::Move(unsigned x, unsigned y)
{
	if (!CheckIfMoveValid(x, y)) return false;
	
	m_x = x;
	m_y = y;
	setPosition()
	return true;
}
