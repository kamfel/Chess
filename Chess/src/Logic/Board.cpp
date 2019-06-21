#include "Logic/Pieces/Piece.h"
#include "Definitions.h"
#include "Logic/Settings.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Logic/Board.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Logic/GraphicsHolder.h"
#include <utility>

#include "Logic/Pieces/Pawn.h"
#include "Logic/Pieces/Bishop.h"
#include "Logic/Pieces/Rook.h"
#include "Logic/Pieces/Knight.h"
#include "Logic/Pieces/King.h"
#include "Logic/Pieces/Queen.h"

Piece* Board::GetPieceOnField(const sf::Vector2i& pos) const
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
	for (auto piece : m_pieces) {
		delete piece;
	}
	for (auto piece : m_captured_pieces) {
		delete piece;
	}
}

bool Board::CheckForStalemate(COLOUR colour)
{
	for (Piece* piece : m_pieces) {
		if (piece->GetColour() == colour && piece->GeneratePossibleMoves(*this).size() != 0) {
			return false;
		}
	}
	return true;
}

bool Board::CheckForCheck(COLOUR colour)
{
	return colour == WHITE ? m_white_king->IsChecked() : m_black_king->IsChecked();
}

bool Board::CheckForMate(COLOUR colour)
{
	King* king = colour == WHITE ? m_white_king : m_black_king;

	if (!king->IsChecked()) {
		return false;
	}

	for (Piece* piece : m_pieces) {
		if (piece->GetColour() == colour) {
			auto moves = piece->GeneratePossibleMoves(*this);
			sf::Vector2i original_pos = piece->GetPos();
			for (auto move : moves) {
				piece->Move(move);
				CalculateAttackedFields(colour);
				if (!IsFieldAttacked(king->GetPos(), colour)) {
					return false;
				}
			}
			m_chosen_piece->SetPos(original_pos);
		}
	}

	return true;
}

std::pair<bool, COLOUR> Board::GetFieldInfo(const sf::Vector2i& pos) const
{
	Piece* piece;
	try {
		 piece = GetPieceOnField(pos);
	}
	catch (...) {
		return std::make_pair<bool, COLOUR>(false, NONE);
	}
	if (piece == nullptr)
		return std::make_pair<bool, COLOUR>(true, WHITE);
	else
		return std::make_pair<bool, COLOUR>(false, piece->GetColour());
}

void Board::CalculateAttackedFields(COLOUR colour)
{
	long long tmp = 0;
	//For every piece find attacked fields
	for (auto piece : m_pieces) {
		//Don't calculate when piece is belonging to player
		if (piece->GetColour() == colour)
			continue;

		//Get moves
		auto moves = piece->GeneratePossibleMoves(*this);

		//For each move set flag that field is attacked
		for (auto move : moves) {
			int offset = move.x + move.y * 8;
			tmp = tmp | ((long long)1 << offset);
		}
	}

	m_attacked_fields = tmp;
}

void Board::UnchoosePiece()
{
	m_chosen_piece->Unhighlight();
	m_chosen_piece = nullptr;
}

bool Board::ChoosePiece(const sf::Vector2i & pos, COLOUR player_colour)
{
	Piece* piece = GetPieceOnField(pos);

	//If field is empty, return false
	if (!piece) return false;

	//If king is checked, the player can't choose other pieces
	if (player_colour == WHITE) {
		if (m_white_king->IsChecked() && piece == m_white_king) {
			return false;
		}
	}
	else
	{
		if (m_black_king->IsChecked() && piece == m_black_king) {
			return false;
		}
	}

	//Choosing piece
	if (piece->GetColour() == player_colour) {
		piece->Highlight();
		m_chosen_piece = piece;
		return true;
	}
	else {
		return false;
	}
}

bool Board::TryMove(const sf::Vector2i & pos, COLOUR player_colour)
{
	//If move is made by a king, calculate fields that are attacked
	if (m_chosen_piece == m_white_king || m_chosen_piece == m_black_king)
	{
		CalculateAttackedFields(player_colour);
	}


	//Check if pawn can capture au passant
	if (dynamic_cast<Pawn*>(m_chosen_piece) != nullptr) {
		sf::Vector2i tmp_pos = m_chosen_piece->GetPos();
		Pawn* left = nullptr;
		try {
			left = dynamic_cast<Pawn*>(GetPieceOnField({ tmp_pos.x - 1, tmp_pos.y }));
		}
		catch (...) {

		}

		Pawn* right = nullptr;
		try {
			right = dynamic_cast<Pawn*>(GetPieceOnField({ tmp_pos.x + 1, tmp_pos.y }));
		}
		catch (...) {

		}

		bool left_possible = false;
		bool right_possible = false;

		if (left) {
			left_possible = left->IsAupassantVulnerable();
		}
		if (right) {
			right_possible = right->IsAupassantVulnerable();
		}

		((Pawn*)m_chosen_piece)->AupassantIsPossible(left_possible, right_possible);
	}


	King* king = player_colour == WHITE ? m_white_king : m_black_king;

	//If king is checked, the player has to uncheck him
	std::vector<std::vector<sf::Vector2i>::iterator> iter_vec;
	auto moves = m_chosen_piece->GeneratePossibleMoves(*this);
	sf::Vector2i original_pos = m_chosen_piece->GetPos();
	for (auto move = moves.begin(); move != moves.end(); move++) {
		m_chosen_piece->Move(*move);
		CalculateAttackedFields(player_colour);
		if (IsFieldAttacked(king->GetPos(), player_colour)) {
			iter_vec.push_back(move);
		}
	}
	m_chosen_piece->SetPos(original_pos);

	for (auto it = iter_vec.rbegin(); it != iter_vec.rend(); it++) {
		moves.erase(*it);
	}


	//Check if move is valid
	bool move_is_valid = false;
	for (auto move : moves) {
		if (move == pos)
			move_is_valid = true;
		
	}

	//If move is not valid return false
	if (!move_is_valid) return false;

	sf::Vector2i tmp_pos = m_chosen_piece->GetPos();



	std::vector<Piece*>::iterator piece_on_attacked_field = m_pieces.begin();

	for (piece_on_attacked_field; piece_on_attacked_field != m_pieces.end(); piece_on_attacked_field++) {
		if ((*piece_on_attacked_field)->GetPos() == pos) {
			break;
		}
	}

	//Move piece
	m_chosen_piece->Move(pos);
	CalculateAttackedFields(player_colour);

	//Check if move didn't expose the king
	//If yes then revert move
	if (player_colour == WHITE) {
		if (IsFieldAttacked(m_white_king->GetPos(), WHITE)) {
			m_chosen_piece->Move(tmp_pos);
			return false;
		}
	}
	else 
	{
		if (IsFieldAttacked(m_black_king->GetPos(), BLACK)) {
			m_chosen_piece->Move(tmp_pos);
			return false;
		}
	}



	//Remove piece if captured
	if (piece_on_attacked_field != m_pieces.end()) {
		m_captured_pieces.push_back(*piece_on_attacked_field);
		m_pieces.erase(piece_on_attacked_field);
	}

	//Capturing au passant
	if (dynamic_cast<Pawn*>(m_chosen_piece) != nullptr) {
		Pawn* left = nullptr;
		try {
			left = dynamic_cast<Pawn*>(GetPieceOnField({ tmp_pos.x - 1, tmp_pos.y }));
		}
		catch (...) {

		}

		Pawn* right = nullptr;
		try {
			right = dynamic_cast<Pawn*>(GetPieceOnField({ tmp_pos.x + 1, tmp_pos.y }));
		}
		catch (...) {
		}

		bool left_possible = false;
		bool right_possible = false;

		if (left && left->IsAupassantVulnerable()) {
			if (m_chosen_piece->GetPos() == sf::Vector2i(tmp_pos.x - 1, tmp_pos.y - 1) ||
				m_chosen_piece->GetPos() == sf::Vector2i(tmp_pos.x - 1, tmp_pos.y + 1)) {

				for (piece_on_attacked_field = m_pieces.begin(); piece_on_attacked_field != m_pieces.end(); piece_on_attacked_field++) {
					if ((*piece_on_attacked_field) == dynamic_cast<Piece*>(left)) {
						m_captured_pieces.push_back(*piece_on_attacked_field);
						m_pieces.erase(piece_on_attacked_field);
						break;
					}
				}

			}
		}
		if (right && right->IsAupassantVulnerable()) {
			if (m_chosen_piece->GetPos() == sf::Vector2i(tmp_pos.x + 1, tmp_pos.y - 1) ||
				m_chosen_piece->GetPos() == sf::Vector2i(tmp_pos.x + 1, tmp_pos.y + 1)) {

				for (piece_on_attacked_field = m_pieces.begin(); piece_on_attacked_field != m_pieces.end(); piece_on_attacked_field++) {
					if ((*piece_on_attacked_field) == dynamic_cast<Piece*>(right)) {
						m_captured_pieces.push_back(*piece_on_attacked_field);
						m_pieces.erase(piece_on_attacked_field);
						break;
					}
				}

			}
		}
	}

	//Promoting pawn to queen
	if (dynamic_cast<Pawn*>(m_chosen_piece) != nullptr) {
		COLOUR pawn_colour = m_chosen_piece->GetColour();
		sf::Vector2i pawn_pos = m_chosen_piece->GetPos();

		if (pawn_colour == WHITE && pawn_pos.y == 0 ||
			pawn_colour == BLACK && pawn_pos.y == 7) {
			
			for (Piece* piece : m_pieces) {
				if (piece == m_chosen_piece) {
					delete piece;
					piece = new Queen(pawn_colour, pawn_pos, *m_textures);
					m_chosen_piece = piece;
				}
			}
		}
	}

	//Check or uncheck kings if necessary
	if (IsFieldAttacked(m_white_king->GetPos(), WHITE)) m_white_king->Check();
	else m_white_king->Uncheck();
	if (IsFieldAttacked(m_black_king->GetPos(), BLACK)) m_black_king->Check();
	else m_black_king->Uncheck();

	//If move was made by rook, castling for this rook is no longer possible
	if (dynamic_cast<Rook*>(m_chosen_piece) != nullptr) {
		if (m_chosen_piece->GetColour() == WHITE) {
			if (tmp_pos == sf::Vector2i(0, 7)) {
				m_white_king->CastlingIsPossibleForLeftRook(false);
			}
			else {
				m_white_king->CastlingIsPossibleForRightRook(false);
			}
		}
		else {
			if (tmp_pos == sf::Vector2i(0, 0)) {
				m_black_king->CastlingIsPossibleForLeftRook(false);
			}
			else {
				m_black_king->CastlingIsPossibleForRightRook(false);
			}
		}
	}

	//If move was made by king, castling is no longer possible
	if (dynamic_cast<King*>(m_chosen_piece) != nullptr) {
		((King*)m_chosen_piece)->CastlingIsPossibleForLeftRook(false);
		((King*)m_chosen_piece)->CastlingIsPossibleForRightRook(false);
	}

	//If pawn made first move and it was over 2 fields then Au Passant is possible
	if (dynamic_cast<Pawn*>(m_chosen_piece) != nullptr) {
		if (!m_chosen_piece->WasPieceMoved() && abs(tmp_pos.y - pos.y) == 2)
			((Pawn*)m_chosen_piece)->SetAupassantVulnerable(true);
		else
			((Pawn*)m_chosen_piece)->SetAupassantVulnerable(false);
	}



	m_chosen_piece->Moved();

	return true;
}

bool Board::IsFieldAttacked(const sf::Vector2i & pos, COLOUR player_colour) const
{
	long long field_as_bit = (long long)1 << (pos.x + pos.y * 8);
	return field_as_bit & m_attacked_fields;
}

void Board::SetPiecesOnStartingPos()
{
	//Delete previous board state
	for (Piece* piece : m_pieces) {
		delete piece;
	}
	for (Piece* piece : m_captured_pieces) {
		delete piece;
	}
	m_pieces.clear();
	m_pieces.reserve(32);
	m_captured_pieces.clear();

	//------------------
	//Setup white pieces
	for (int i = 0; i < 8; i++)
	{
		m_pieces.push_back(new Pawn(WHITE, { i, 6 }, *m_textures));
	}
	m_pieces.push_back(new Rook(WHITE, { 0, 7 }, *m_textures));
	m_pieces.push_back(new Rook(WHITE, { 7, 7 }, *m_textures));
	m_pieces.push_back(new Knight(WHITE, { 1, 7 }, *m_textures));
	m_pieces.push_back(new Knight(WHITE, { 6, 7 }, *m_textures));
	m_pieces.push_back(new Bishop(WHITE, { 2, 7 }, *m_textures));
	m_pieces.push_back(new Bishop(WHITE, { 5, 7 }, *m_textures));
	m_pieces.push_back(new Queen(WHITE, { 4, 7 }, *m_textures));

	m_white_king = new King(WHITE, { 3, 7 }, *m_textures);
	m_pieces.push_back(m_white_king);
	//------------------

	//-----------------
	//Setup black pawns
	for (int i = 0; i < 8; i++)
	{
		m_pieces.push_back(new Pawn(BLACK, { i, 1 }, *m_textures));
	}

	m_pieces.push_back(new Rook(BLACK, { 0, 0 }, *m_textures));
	m_pieces.push_back(new Rook(BLACK, { 7, 0 }, *m_textures));
	m_pieces.push_back(new Knight(BLACK, { 1, 0 }, *m_textures));
	m_pieces.push_back(new Knight(BLACK, { 6, 0 }, *m_textures));
	m_pieces.push_back(new Bishop(BLACK, { 2, 0 }, *m_textures));
	m_pieces.push_back(new Bishop(BLACK, { 5, 0 }, *m_textures));
	m_pieces.push_back(new Queen(BLACK, { 4, 0 }, *m_textures));

	m_black_king = new King(BLACK, { 3, 0 }, *m_textures);
	m_pieces.push_back(m_black_king);
	//------------------

}

void Board::SetTexture(GraphicsHolder& gh)
{
	m_textures = &gh;

	setTexture(gh.GetBoardTexture());
	setPosition(sf::Vector2f(CHESS_BOARD_DEFAULT_POS_X, CHESS_BOARD_DEFAULT_POS_Y));
	setScale({ CHESS_BOARD_SIZE / 800.0f, CHESS_BOARD_SIZE / 800.0f });
}

void Board::DrawBoardAndPieces(sf::RenderWindow& window)
{
	window.draw(*this);

	for (auto piece : m_pieces) {
		piece->Draw(window, sf::RenderStates::Default);
	}
}

sf::Vector2i Board::ConvertBoardXYtoDisplayXY(const sf::Vector2i & boardXY)
{
	int x = CHESS_BOARD_DEFAULT_POS_X 
		+ CHESS_BOARD_GRID_THICKNESS * (boardXY.x + 1)
		+ CHESS_BOARD_FIELD_SIZE * boardXY.x;

	int y = CHESS_BOARD_DEFAULT_POS_Y 
		+ CHESS_BOARD_GRID_THICKNESS * (boardXY.y + 1)
		+ CHESS_BOARD_FIELD_SIZE * boardXY.y;

	return {x, y};
}

sf::Vector2i Board::ConvertDisplayXYtoBoardXY(const sf::Vector2i & displayXY)
{
	int x = (displayXY.x - CHESS_BOARD_DEFAULT_POS_X - CHESS_BOARD_GRID_THICKNESS)
		/ (CHESS_BOARD_GRID_THICKNESS + CHESS_BOARD_FIELD_SIZE);

	int y = (displayXY.y - CHESS_BOARD_DEFAULT_POS_Y - CHESS_BOARD_GRID_THICKNESS)
		/ (CHESS_BOARD_GRID_THICKNESS + CHESS_BOARD_FIELD_SIZE);

	return {x, y};
}

bool Board::AreDisplayXYWithinBoard(const sf::Vector2i& displayXY)
{
	if (displayXY.x < CHESS_BOARD_DEFAULT_POS_X || displayXY.x > CHESS_BOARD_DEFAULT_POS_X + CHESS_BOARD_SIZE)
		return false;

	if (displayXY.y < CHESS_BOARD_DEFAULT_POS_Y || displayXY.y > CHESS_BOARD_DEFAULT_POS_Y + CHESS_BOARD_SIZE)
		return false;

	return true;
}
