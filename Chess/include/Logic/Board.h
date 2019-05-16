#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include <vector>

class Piece;

class Board : 
	public sf::Sprite
{
private:

	sf::Vector2f m_pos;
	std::vector<Piece*> m_pieces;

protected:

	Piece* GetPieceOnField(const sf::Vector2u pos) const;

public:

	Board();
	virtual ~Board();

	bool IsFieldEmpty(const sf::Vector2u pos) const;
	bool IsBlackPieceOnField(const sf::Vector2u pos) const;
	bool IsWhitePieceOnField(const sf::Vector2u pos) const;

	void SetPiecesOnStartingPos();

	bool LoadStateFromMemory(const void* const memptr);
	void* SaveStateToMemory() const;

	static sf::Vector2f ConvertBoardXYtoDisplayXY(const sf::Vector2u& boardXY);
	static sf::Vector2u ConvertDisplayXYtoBoardXy(const sf::Vector2f& displayXY);
};

