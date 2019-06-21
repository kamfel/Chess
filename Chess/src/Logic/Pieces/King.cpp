#include "Logic\Pieces\King.h"
#include "Logic/GraphicsHolder.h"
#include "Logic/Board.h"

King::King(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh)
	:Piece(colour, pos)
{
	if (colour == WHITE) {
		setTexture(gh.GetTexture("White_King"));
	}
	else {
		setTexture(gh.GetTexture("Black_King"));
	}
}

King::~King()
{
}

const std::vector<sf::Vector2i>& King::GeneratePossibleMoves(const Board & board)
{
	std::vector<sf::Vector2i> tmpvec;

	std::vector<sf::Vector2i> offsets = {
		{-1, 0},
		{-1, -1},
		{0, -1},
		{1, -1},
		{1, 0},
		{1, 1},
		{0, 1},
		{-1, 1}
	};

	//Get opponents colour
	COLOUR opponent_colour = m_colour == WHITE ? BLACK : WHITE;

	//Generate moves around the king
	for (auto offset : offsets) {
		sf::Vector2i possible_move = m_pos + offset;

		//Check if move out of bound
		if (possible_move.x < 0 || possible_move.x > 7 ||
			possible_move.y < 0 || possible_move.y > 7)
			continue;

		//Check if field is attacked by opponents piece
		if (board.IsFieldAttacked(possible_move, m_colour)) {
			continue;
		}

		auto field_info = board.GetFieldInfo(possible_move);

		//Check if field is empty
		if (field_info.first == true) {
			tmpvec.push_back(possible_move);
		}
		//Else check if field is taken by opponent
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(possible_move);
		}
	}

	//Castling to the left
	if (m_castling_left && !m_is_checked) {
		//Check if fields between king and rook are attacked or taken
		bool is_any_field_attacked = false;
		for (int i = m_pos.x - 1; i > -1; i--)
		{
			sf::Vector2i possible_move = { i, m_pos.y };
			if (board.IsFieldAttacked(possible_move, m_colour)) {
				is_any_field_attacked = true;
				break;
			}

			auto field_info = board.GetFieldInfo(possible_move);

			if (field_info.first == false && i != 0) {
				is_any_field_attacked = true;
				break;
			}
		}

		if (!is_any_field_attacked)
			tmpvec.push_back({ 1, m_pos.y });
	}

	//Castling to the right
	if (m_castling_right && !m_is_checked) {
		//Check if fields between king and rook are attacked or taken
		bool is_any_field_attacked = false;
		for (int i = m_pos.x + 1; i < 8; i++)
		{
			sf::Vector2i possible_move = { i, m_pos.y };
			if (board.IsFieldAttacked(possible_move, m_colour)) {
				is_any_field_attacked = true;
				break;
			}

			auto field_info = board.GetFieldInfo(possible_move);

			if (field_info.first == false && i != 7) {
				is_any_field_attacked = true;
				break;
			}
		}

		if (!is_any_field_attacked)
			tmpvec.push_back({ 5, m_pos.y });
	}

	m_possible_moves = tmpvec;

	return m_possible_moves;
}

void King::CastlingIsPossibleForLeftRook(bool left)
{
	m_castling_left = left;
}

void King::CastlingIsPossibleForRightRook(bool right)
{
	m_castling_right = right;
}