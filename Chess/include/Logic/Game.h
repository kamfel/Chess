#pragma once
#include "Settings.h"
#include "Board.h"
#include <string>
#include "SFML/Graphics/RenderWindow.hpp"
#include "GraphicsHolder.h"

enum COLOUR;

class Game
{
private:

	//Conatiner holding textures for the game
	GraphicsHolder m_textures;

	//Window which the game will render to
	sf::RenderWindow m_main_window;

	//Board containing information about the board and pieces
	Board m_board;

	//The player which has move
	COLOUR m_has_move;

	//True if previous move checked the player
	bool m_is_check;

	//Lock game when checkmate or stalemate
	bool m_is_locked = false;

public:
	Game(sf::WindowHandle& wndhandle);
	~Game();

	bool IsGameFinished() { return m_is_locked; }

	//Starts a new game; previous state is discarded
	void StartNewGame();

	//Handles any events in the event queue of the window associated with the game
	void CallEventHandler();

	//Draws chess game to window associated with the game; also flips display buffers
	void Draw();
};

