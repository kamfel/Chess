#include "Logic/Board.h"
#include "Logic/Pieces/Piece.h"
#include "Definitions.h"
#include "Logic/Settings.h"

Piece* Board::GetPieceOnField(const sf::Vector2u& pos) const
{
	if (pos.x >= 8 || pos.y >= 8) throw std::exception("Field not on board");

	for (auto iter = m_pieces.begin(); iter < m_pieces.end(); iter++) {
		if (*iter == nullptr) continue;
		if ((*iter)->IsAtPos(pos)) return *iter;
	}
	return nullptr;
}

Board::Board()
{
}


Board::~Board()
{
}

bool Board::IsFieldEmpty(const sf::Vector2u& pos) const
{
	if (GetPieceOnField(pos) != nullptr)
		return true;
	else
		return false;
}

bool Board::IsBlackPieceOnField(const sf::Vector2u& pos) const
{
	Piece* piece = GetPieceOnField(pos);

	if (piece == nullptr)
		return false;
	else
		return piece->IsBlack();
}

bool Board::IsWhitePieceOnField(const sf::Vector2u& pos) const
{
	Piece* piece = GetPieceOnField(pos);

	if (piece == nullptr)
		return false;
	else
		return piece->IsWhite();
}

bool Board::IsFieldHighlighted(const sf::Vector2u& pos) const
{
	return GetPieceOnField(pos)->IsHighlighted();
}

sf::Vector2f Board::ConvertBoardXYtoDisplayXY(const sf::Vector2u & boardXY)
{
	float x = CHESS_BOARD_DEFAULT_POS_X 
		+ CHESS_BOARD_GRID_THICKNESS * (boardXY.x+ 1)
		+ CHESS_BOARD_FIELD_SIZE * boardXY.x;

	float y = CHESS_BOARD_DEFAULT_POS_Y 
		+ CHESS_BOARD_GRID_THICKNESS * (boardXY.y + 1)
		+ CHESS_BOARD_FIELD_SIZE * boardXY.y;

	return sf::Vector2f(x, y);
}

sf::Vector2u Board::ConvertDisplayXYtoBoardXy(const sf::Vector2f & displayXY)
{
	unsigned x = (displayXY.x - CHESS_BOARD_DEFAULT_POS_X - CHESS_BOARD_GRID_THICKNESS)
		/ (CHESS_BOARD_GRID_THICKNESS + CHESS_BOARD_FIELD_SIZE);

	unsigned y = (displayXY.y - CHESS_BOARD_DEFAULT_POS_Y - CHESS_BOARD_GRID_THICKNESS)
		/ (CHESS_BOARD_GRID_THICKNESS + CHESS_BOARD_FIELD_SIZE);

	return sf::Vector2u(x, y);
}

bool Board::AreDisplayXYWithinBoard(const sf::Vector2f& displayXY)
{
	if (displayXY.x < CHESS_BOARD_DEFAULT_POS_X || displayXY.x > CHESS_BOARD_DEFAULT_POS_X + CHESS_BOARD_SIZE)
		return false;

	if (displayXY.y < CHESS_BOARD_DEFAULT_POS_Y || displayXY.y > CHESS_BOARD_DEFAULT_POS_Y + CHESS_BOARD_SIZE)
		return false;

	return true;
}
