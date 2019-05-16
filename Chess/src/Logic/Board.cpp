#include "Logic/Board.h"
#include "Logic/Pieces/Piece.h"


Piece* Board::GetPieceOnField(const sf::Vector2u pos) const
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

bool Board::IsFieldEmpty(const sf::Vector2u pos) const
{
	if (GetPieceOnField(pos) != nullptr)
		return true;
	else
		return false;
}

bool Board::IsBlackPieceOnField(const sf::Vector2u pos) const
{
	Piece* piece = GetPieceOnField(pos);

	if (piece == nullptr)
		return false;
	else
		return piece->IsBlack();
}

bool Board::IsWhitePieceOnField(const sf::Vector2u pos) const
{
	Piece* piece = GetPieceOnField(pos);

	if (piece == nullptr)
		return false;
	else
		return piece->IsWhite();
}
