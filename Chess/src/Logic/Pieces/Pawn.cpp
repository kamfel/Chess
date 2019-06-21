#include "Logic\Pieces\Pawn.h"
#include "Logic\Board.h"
#include "Logic/GraphicsHolder.h"

Pawn::Pawn(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh)
	:Piece(colour, pos)
{
	if (colour == WHITE) {
		setTexture(gh.GetTexture("White_Pawn"));
	}
	else {
		setTexture(gh.GetTexture("Black_Pawn"));
	}
}


Pawn::~Pawn()
{
}

const std::vector<sf::Vector2i>& Pawn::GeneratePossibleMoves(const Board & board)
{
	std::vector<sf::Vector2i> tmpvec;

	if (m_colour == WHITE) {
		//Generate moves for white pawn

		//One field up
		sf::Vector2i possible_move = { m_pos.x, m_pos.y - 1 };
		auto field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == true)
		{
			tmpvec.push_back(possible_move);

			//Two fields up
			//Only possible when one field up is empty
			if (!m_was_piece_moved) {
				possible_move = { m_pos.x, m_pos.y - 2 };
				field_info = board.GetFieldInfo(possible_move);
				if (field_info.first == true)
				{
					tmpvec.push_back(possible_move);
				}
			}
		}
		
		//Top-left field from pawn
		possible_move = { m_pos.x - 1, m_pos.y - 1 };
		field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == false && 
			field_info.second == BLACK) {
			tmpvec.push_back(possible_move);
		}
		if (m_aupassant_left_possible) {
			tmpvec.push_back(possible_move);
		}


		//Top-right field from pawn
		possible_move = { m_pos.x + 1, m_pos.y - 1 };
		field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == false && 
			field_info.second == BLACK) {
			tmpvec.push_back(possible_move);
		}
		if (m_aupassant_right_possible) {
			tmpvec.push_back(possible_move);
		}
	}
	else
	{
		//Generate moves for black pawn

		//One field down
		sf::Vector2i possible_move = { m_pos.x, m_pos.y + 1 };
		auto field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == true)
		{
			tmpvec.push_back(possible_move);

			//Two fields down
			//Only possible when one field down is empty
			possible_move = { m_pos.x, m_pos.y + 2 };
			field_info = board.GetFieldInfo(possible_move);
			if (field_info.first == true)
			{
				tmpvec.push_back(possible_move);
			}
		}

		//Lower-left field from pawn
		possible_move = { m_pos.x - 1, m_pos.y + 1 };
		field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == false &&
			field_info.second == WHITE) {
			tmpvec.push_back(possible_move);
		}
		if (m_aupassant_left_possible) {
			tmpvec.push_back(possible_move);
		}

		//Lower-right field from pawn
		
		possible_move = { m_pos.x + 1, m_pos.y + 1 };
		field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == false &&
			field_info.second == WHITE) {
			tmpvec.push_back(possible_move);
		}
		if (m_aupassant_right_possible) {
			tmpvec.push_back(possible_move);
		}
	}

	m_possible_moves = tmpvec;

	return m_possible_moves;
}

void Pawn::AupassantIsPossible(bool left, bool right)
{
	m_aupassant_left_possible = left;
	m_aupassant_right_possible = right;
}
