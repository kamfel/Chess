#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
private:
	bool m_aupassant_left_possible = false;
	bool m_aupassant_right_possible = false;

	bool m_aupassant_vulnerable = false;
public:

	Pawn(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Pawn();

	const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board& board) override;

	void AupassantIsPossible(bool left, bool right);

	bool IsAupassantVulnerable() { return m_aupassant_vulnerable; }
	void SetAupassantVulnerable(bool t) { m_aupassant_vulnerable = t; }
};


