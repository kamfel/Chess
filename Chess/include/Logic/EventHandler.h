#pragma once
#include "SFML/Window.hpp"
class EventHandler
{
private:
	sf::Window& m_window;
	sf::Event m_event;
public:
	EventHandler() = delete;
	EventHandler(sf::Window& window);

	~EventHandler();

	void SetWindow(sf::Window& window);

	void Run();
};

