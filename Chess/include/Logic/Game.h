#pragma once
#include "Settings.h"
#include "Board.h"
#include "EventHandler.h"
#include <string>
#include "SFML/Graphics/RenderWindow.hpp"

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
	bool CheckForStalemate();
	bool CheckForCheck();
	bool CheckForMate();
public:
	Game();
	Game(sf::WindowHandle& wndhandle);
	~Game();

	void Run();

	void StartNewGame();
	void LoadGame(const std::string& filepath);
	void SaveGame(const std::string& filepath) const;

	const Settings& GetCurrentSettings() const;
	bool ApplySettings(const Settings& new_settings) const;
};

