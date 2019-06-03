#pragma once
#include "Settings.h"
#include "Board.h"
#include <string>
#include "SFML/Graphics/RenderWindow.hpp"

enum WHOHASMOVE { NONE = 0, WHITE, BLACK};

class Game
{
private:
	sf::RenderWindow m_main_window;
	Settings m_settings;
	Board m_board;
	WHOHASMOVE m_has_move;
	bool m_is_check;
	bool m_gamerun;

	void GameLoop();
public:
	Game();
	Game(sf::WindowHandle& wndhandle);
	~Game();

	void Run();
	void Stop();

	void StartNewGame();
	void LoadGame(const std::string& filepath);
	void SaveGame(const std::string& filepath) const;
	bool ApplySettings(const Settings& new_settings) const;

	const Settings& GetCurrentSettings() const;
};

