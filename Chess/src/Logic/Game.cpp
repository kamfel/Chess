#include "Logic/Game.h"
#include "Logic/Settings.h"
#include "Logic/Board.h"
#include <string>
#include "Logic/EventHandler.h"
#include "SFML/System.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Logic\GraphicsLoader.h"
#include "Logic\ResourceStream.h"
#include "../resource.h"

void Game::GameLoop()
{
	while (m_gamerun) {

	}
}

Game::Game()
	:m_main_window(sf::VideoMode(1000, 800), "Chess Game"),
	m_settings(),
	m_board(),
	m_has_move(NONE),
	m_is_check(false)
{
	m_main_window.setFramerateLimit(60);
}

Game::Game(sf::WindowHandle& wndhandle)
	:m_main_window(wndhandle),
	m_settings(),
	m_board(),
	m_has_move(NONE),
	m_is_check(false)
{
	m_main_window.setFramerateLimit(60);
	ResourceStream r_stream(IDB_PIECES, "PNG");
	GraphicsLoader::LoadTexturesFromStream(r_stream);
}


Game::~Game()
{
}

void Game::Run()
{
	m_gamerun = true;
	EventHandler handler(m_main_window);
}

void Game::Stop()
{
	m_gamerun = false;
}

void Game::StartNewGame()
{
}

void Game::LoadGame(const std::string & filepath)
{
}

void Game::SaveGame(const std::string & filepath) const
{
}

const Settings& Game::GetCurrentSettings() const
{
	return m_settings;
}

bool Game::ApplySettings(const Settings & new_settings) const
{
	return false;
}
