#pragma once
#include <string>
#include "SFML/Graphics/RenderWindow.hpp"
#include "Settings.h"
#include "Board.h"
#include "EventHandler.h"

enum WHOHASMOVE { NONE = 0, WHITE, BLACK};

class Game
{
private:
	sf::RenderWindow m_main_window;
	Settings m_settings;
	Board m_board;
	EventHandler m_event_handler;
	WHOHASMOVE m_has_move;
	bool m_is_check;
protected:

public:
	Game();
	~Game();

	void Run();

	bool CheckForStalemate();
	bool CheckForCheck();
	bool CheckForMate();

	void StartNewGame();
	void LoadGame(const std::string& filepath);
	void SaveGame(const std::string& filepath);
};

