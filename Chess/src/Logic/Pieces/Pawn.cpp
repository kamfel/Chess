#include "Logic\Pieces\Pawn.h"
#include "Logic\Board.h"


Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}

std::vector<sf::Vector2u>& Pawn::GeneratePossibleMovesForWhite(const Board& board)
{
	m_possible_moves.clear();
	m_possible_moves.reserve(4);

	sf::Vector2u tmp_pos(m_pos);

	tmp_pos.y += 1;
	if (board.IsFieldEmpty(tmp_pos)) {
		m_possible_moves.push_back(tmp_pos);
	}

	tmp_pos.y += 1;
	if (board.IsFieldEmpty(tmp_pos)) {
		m_possible_moves.push_back(tmp_pos);
	}

	std::vector<sf::Vector2u> vec;
	return vec;
}

std::vector<sf::Vector2u>& Pawn::GeneratePossibleMovesForBlack(const Board & board)
{
	std::vector<sf::Vector2u> vec;
	return vec;
}
