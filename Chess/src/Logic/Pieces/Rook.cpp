#include "Logic\Pieces\Rook.h"
#include "Logic/Board.h"
#include "Logic/GraphicsHolder.h"

Rook::Rook(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh)
	:Piece(colour, pos)
{
	if (colour == WHITE) {
		setTexture(gh.GetTexture("White_Rook"));
	}
	else {
		setTexture(gh.GetTexture("Black_Rook"));
	}
}

Rook::~Rook()
{
}

const std::vector<sf::Vector2i>& Rook::GeneratePossibleMoves(const Board & board)
{
	std::vector<sf::Vector2i> tmpvec;

	//Get colour of opponents pieces
	COLOUR opponent_colour = m_colour == WHITE ? BLACK : WHITE;

	//Going up from rook's position
	for (int i = m_pos.y + 1; i < 8; i++)
	{
		sf::Vector2i current_pos = { m_pos.x, i };
		auto field_info = board.GetFieldInfo(current_pos);
		if (field_info.first)
		{
			tmpvec.push_back(current_pos);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(current_pos);
		}
		else
		{
			break;
		}
	}

	//Going down from rook's position
	for (int i = m_pos.y - 1; i >= 0; i--)
	{
		sf::Vector2i current_pos = { m_pos.x, i };
		auto field_info = board.GetFieldInfo(current_pos);
		if (field_info.first)
		{
			tmpvec.push_back(current_pos);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(current_pos);
		}
		else
		{
			break;
		}
	}

	//Going left from rook's position
	for (int i = m_pos.x - 1; i >= 0; i--)
	{
		sf::Vector2i current_pos = { i, m_pos.y };
		auto field_info = board.GetFieldInfo(current_pos);
		if (field_info.first)
		{
			tmpvec.push_back(current_pos);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(current_pos);
		}
		else
		{
			break;
		}
	}

	//Going right from rook's position
	for (int i = m_pos.x + 1; i >= 0; i++)
	{
		sf::Vector2i current_pos = { i, m_pos.y };
		auto field_info = board.GetFieldInfo(current_pos);
		if (field_info.first)
		{
			tmpvec.push_back(current_pos);
		}
		else if (field_info.second == opponent_colour) {
			tmpvec.push_back(current_pos);
		}
		else
		{
			break;
		}
	}

	m_possible_moves = tmpvec;

	return m_possible_moves;
}
