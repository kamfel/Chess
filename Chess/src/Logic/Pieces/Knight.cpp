#include "Logic\Pieces\Knight.h"
#include "Logic/Board.h"
#include "Logic/GraphicsHolder.h"

Knight::Knight(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh)
	:Piece(colour, pos)
{
	if (colour == WHITE) {
		setTexture(gh.GetTexture("White_Knight"));
	}
	else {
		setTexture(gh.GetTexture("Black_Knight"));
	}
}


Knight::~Knight()
{
}

const std::vector<sf::Vector2i>& Knight::GeneratePossibleMoves(const Board & board)
{

	std::vector<sf::Vector2i> tmpvec;

	std::vector<sf::Vector2i> offsets = {
		{-1, -2},
		{1, -2},
		{2, -1},
		{2, 1},
		{1, 2},
		{-1, 2},
		{-2, 1},
		{-2, -1}
	};

	COLOUR opponent_colour = m_colour == WHITE ? BLACK : WHITE;

	for (sf::Vector2i offset : offsets) {
		sf::Vector2i possible_move = offset + m_pos;
		if (possible_move.x < 0 || possible_move.x > 7 ||
			possible_move.y < 0 || possible_move.y > 7) 
			continue;

		auto field_info = board.GetFieldInfo(possible_move);

		if (field_info.first == true) {
			tmpvec.push_back(possible_move);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(possible_move);
		}
	}

	m_possible_moves = tmpvec;

	return m_possible_moves;
}
