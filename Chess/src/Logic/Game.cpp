#include "Logic/Game.h"
#include "Logic/Settings.h"
#include "Logic/Board.h"
#include <string>
#include "Logic/EventHandler.h"
#include "SFML/System.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Logic\GraphicsHolder.h"
#include "Logic\ResourceStream.h"
#include "../resource.h"
#include "Logic/Pieces/Piece.h"
#include "SFML/System/Clock.hpp"


Game::Game(sf::WindowHandle& wndhandle)
	:m_textures(),
	m_main_window(wndhandle),
	m_has_move(WHITE),
	m_is_check(false)
{
	m_main_window.setFramerateLimit(60);
	//Load pieces textures
	ResourceStream r_stream(IDB_PIECES, "PNG");
	if (!r_stream.is_open() || !m_textures.LoadTexturesFromStream(r_stream)) {
		throw std::exception("Can't load pieces");
	}

	//Load board texture
	r_stream.LoadResourceById(IDB_BOARD, "PNG");
	if (!r_stream.is_open() || !m_textures.LoadBoardTextureFromStream(r_stream)) {
		throw std::exception("Can't load board");
	}

	m_board.SetTexture(m_textures);
}

Game::~Game()
{
}

void Game::StartNewGame()
{
	m_board.SetPiecesOnStartingPos();

	m_has_move = WHITE;
}

void Game::CallEventHandler()
{
	if (m_is_locked) return;

	EventHandler eh(m_main_window);
	if (eh.HandleEvents(m_board, m_has_move)) {

		m_is_check = m_board.CheckForCheck(m_has_move);
		if (m_is_check) {
			m_is_locked = m_board.CheckForMate(m_has_move);
		}
		if (m_board.CheckForStalemate(m_has_move)) {
			m_is_locked = true;
		}

		m_has_move = m_has_move == WHITE ? BLACK : WHITE;
	}
}

void Game::Draw()
{
	m_main_window.clear(sf::Color::White);
	m_board.DrawBoardAndPieces(m_main_window);



	m_main_window.display();
}
