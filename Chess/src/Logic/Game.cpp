#include "Logic\Game.h"

#include "SFML/System.hpp"

extern sf::Mutex mutex;

Game::Game()
	:m_main_window(sf::VideoMode(1000, 800), "Chess Game")
{
	m_main_window.setFramerateLimit(60);
}


Game::~Game()
{
}

void Game::Run()
{


	while (true) {

		mutex.lock();
		
		
	}
}
