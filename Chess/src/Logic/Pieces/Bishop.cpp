#include "Logic\Pieces\Bishop.h"
#include "Logic/Board.h"
#include "Logic/GraphicsHolder.h"

Bishop::Bishop(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh)
	:Piece(colour, pos)
{
	if (colour == WHITE) {
		setTexture(gh.GetTexture("White_Bishop"));
	}
	else {
		setTexture(gh.GetTexture("Black_Bishop"));
	}
}


Bishop::~Bishop()
{
}

const std::vector<sf::Vector2i>& Bishop::GeneratePossibleMoves(const Board & board)
{
	std::vector<sf::Vector2i> tmpvec;

	COLOUR opponent_colour = m_colour == WHITE ? BLACK : WHITE;

	//going up the positive diagonal
	int i = m_pos.x + 1;
	int j = m_pos.y - 1;
	for (i, j; i < 8 && j > -1; i++, j--)
	{
		sf::Vector2i possible_move = { i, j };
		auto field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == true) {
			tmpvec.push_back(possible_move);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(possible_move);
		}
		else {
			break;
		}
	}

	//going down the positive diagonal
	i = m_pos.x - 1;
	j = m_pos.y + 1;
	for (i, j; i > -1 && j < 8; i--, j++)
	{
		sf::Vector2i possible_move = { i, j };
		auto field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == true) {
			tmpvec.push_back(possible_move);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(possible_move);
		}
		else {
			break;
		}
	}

	//going up the negative diagonal
	i = m_pos.x - 1;
	j = m_pos.y - 1;
	for (i, j; i > -1 && j > -1; i--, j--)
	{
		sf::Vector2i possible_move = { i, j };
		auto field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == true) {
			tmpvec.push_back(possible_move);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(possible_move);
		}
		else {
			break;
		}
	}

	//going down the negative diagonal
	i = m_pos.x + 1;
	j = m_pos.y + 1;
	for (i, j; i < 8 && j < 8; i++, j++)
	{
		sf::Vector2i possible_move = { i, j };
		auto field_info = board.GetFieldInfo(possible_move);
		if (field_info.first == true) {
			tmpvec.push_back(possible_move);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(possible_move);
		}
		else {
			break;
		}
	}

	m_possible_moves = tmpvec;

	return m_possible_moves;
}
