#include "Logic/Settings.h"
#include "Logic/Board.h"
#include "Logic/EventHandler.h"
#include <string>
#include "SFML/System.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include <thread>
#include "SFML/Graphics/RenderWindow.hpp"
#include "Logic/Game.h"

Game::Game()
	:m_main_window(sf::VideoMode(1000, 800), "Chess Game"),
	m_settings(),
	m_board(),
	m_event_handler(m_main_window),
	m_has_move(NONE),
	m_is_check(false)
{
	m_main_window.setFramerateLimit(60);
}

Game::Game(sf::WindowHandle& wndhandle)
	:m_main_window(wndhandle),
	m_settings(),
	m_board(),
	m_event_handler(m_main_window),
	m_has_move(NONE),
	m_is_check(false)
{
	m_main_window.setFramerateLimit(60);
}


Game::~Game()
{
}

void Game::Run()
{
	sf::CircleShape circle(20, 20);
	circle.setPosition(sf::Vector2f(30, 30));

	m_main_window.draw(circle);
	m_main_window.display();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

const Settings& Game::GetCurrentSettings() const
{
	return m_settings;
}
