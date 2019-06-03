#include "Logic/EventHandler.h"
#include "Logic/Game.h"
#include "Logic/Board.h"

void EventHandler::HandleMouseButtonPressed(int x, int y)
{
	if (!Board::AreDisplayXYWithinBoard(sf::Vector2f(x, y)))
		return;

	if ()
}

EventHandler::EventHandler(sf::Window& window)
	: m_window(window), m_event()
{
}

EventHandler::~EventHandler()
{
	
}

void EventHandler::HandleEvents()
{
	while (m_window.pollEvent(m_event)) {
		switch (m_event.type)
		{
		case sf::Event::MouseButtonReleased:
			HandleMouseButtonPressed(m_event.mouseButton.x, m_event.mouseButton.y);
			break;
		default:
			break;
		}
	}
}
