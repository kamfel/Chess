#pragma once
#include "SFML/Window.hpp"

class Game;

class EventHandler
{
private:
	sf::Window& m_window;
	sf::Event m_event;

	void HandleMouseButtonPressed(int x, int y);

public:
	EventHandler() = delete;
	EventHandler(sf::Window& window);

	~EventHandler();

	void SetWindow(sf::Window& window);

	void Run();

	void HandleEvents();
};

