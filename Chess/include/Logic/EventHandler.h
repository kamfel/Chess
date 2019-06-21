#pragma once
#include "SFML/Window.hpp"

class Game;
enum COLOUR;

class EventHandler
{
private:
	//window which the event queue is associated with
	sf::Window& m_window;

	//Currently handled event 
	sf::Event m_event;

	//Called when mouse button is pressed inside the window
	//return value: true if move was made
	bool HandleMouseButtonPressed(Board& board, COLOUR player_colour);

public:
	EventHandler() = delete;
	EventHandler(sf::Window& window);

	~EventHandler();

	//Handles all events in the event queue
	//return value: true if move was made
	bool HandleEvents(Board& board, COLOUR player_colour);
};

