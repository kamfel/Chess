#include "Logic\Pieces\Rook.h"
#include "Logic\Board.h"


std::vector<sf::Vector2u>& Rook::GeneratePossibleMovesForWhite(const Board & board)
{
	m_possible_moves.clear();
	m_possible_moves.reserve(10);

	for (int i = m_pos.x; i < 8; i++)
	{
		sf::Vector2u new_move(i, m_pos.y);
		if (board.IsFieldEmpty(new_move)) {
			m_possible_moves.push_back(new_move);
		}
		else if (board.IsBlackPieceOnField(new_move))
		{
			m_possible_moves.push_back(new_move);
		
		}
		else
		{
			break;
		}
	}
	return m_possible_moves;
}

std::vector<sf::Vector2u>& Rook::GeneratePossibleMovesForBlack(const Board & board)
{
	// TODO: tu wstawiæ instrukcjê return
	return m_possible_moves;
}

Rook::Rook()
{
}


Rook::~Rook()
{
}

const std::vector<sf::Vector2u> Rook::GeneratePossibleMoves(const Board & board)
{
	return std::vector<sf::Vector2u>();
}
