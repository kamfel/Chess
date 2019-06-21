#include "Logic/Pieces/Piece.h"
#include "Logic/EventHandler.h"
#include "Logic/Game.h"
#include "Logic/Board.h"

bool EventHandler::HandleMouseButtonPressed(Board& board, COLOUR player_colour)
{
	//Check if mouse click was within board boundaries
	sf::Vector2i mouse_pos = { m_event.mouseButton.x, m_event.mouseButton.y };
	if (!Board::AreDisplayXYWithinBoard(mouse_pos))
		return false;

	//Get target field
	sf::Vector2i field = Board::ConvertDisplayXYtoBoardXY(mouse_pos);
	
	if (!board.IsPieceChosen()) {
		//If there was no piece chosen, choose piece and return
		board.ChoosePiece(field, player_colour);
		return false;
	}

	//A piece was chosen earlier so try to make a move to field with this piece
	bool made_move = board.TryMove(field, player_colour);
	board.UnchoosePiece();
	return made_move;
}

EventHandler::EventHandler(sf::Window& window)
	: m_window(window), m_event()
{
}

EventHandler::~EventHandler()
{
	
}

bool EventHandler::HandleEvents(Board& board, COLOUR colour)
{
	while (m_window.pollEvent(m_event)) {
		switch (m_event.type)
		{
		case sf::Event::MouseButtonReleased:
			return HandleMouseButtonPressed(board, colour);
		default:
			break;
		}
	}
	return false;
}
