#pragma once
#include "Piece.h"
class King :
	public Piece
{
private:

	bool m_is_checked = false;

	bool m_castling_left = true;

	bool m_castling_right = true;

public:
	King(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~King();

	// Odziedziczono za poœrednictwem elementu Piece
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;
	
	//Returns true if king is checked
	bool IsChecked() { return m_is_checked; };

	//Check
	void Check() { m_is_checked = true; }

	//Uncheck
	void Uncheck() { m_is_checked = false; }

	//Function which informs king if it is possible to castle
	//Should be called before generating moves
	void CastlingIsPossibleForLeftRook(bool left);
	void CastlingIsPossibleForRightRook(bool right);
};

