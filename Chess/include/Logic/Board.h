#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "Logic/Pieces/Piece.h"
class Board : 
	public sf::Sprite
{
private:
	float m_x, m_y;
	Piece* m_pieces[32];

public:
	Board();
	virtual ~Board();

	void SetPiecesOnStartingPos();

	bool LoadStateFromMemory(const void* const memptr);
	void* SaveStateToMemory();

	static sf::Vector2f ConvertBoardXYtoDisplayXY(const sf::Vector2u& boardXY);
	static sf::Vector2u ConvertDisplayXYtoBoardXy(const sf::Vector2f& displayXY);
};

