#pragma once
#include "SFML/Graphics/Sprite.hpp"
class Piece : 
	public sf::Sprite
{
private:
	unsigned m_x, m_y;
protected:
	virtual void MovePiece(unsigned x, unsigned y) = 0;
	virtual bool CheckIfMoveValid(unsigned x, unsigned y) const = 0;
public:
	Piece();
	virtual ~Piece();

	bool Move(unsigned x, unsigned y);
};

