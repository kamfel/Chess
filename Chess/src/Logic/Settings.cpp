#include "Logic/Settings.h"
#include <Windows.h>
#include "../resource.h"
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML\System\Time.hpp"

Settings::Settings()
{
}

Settings::Settings(bool time_on, long long time_in_seconds)
	:m_time_on(time_on), m_time(sf::seconds(static_cast<float>(time_in_seconds)))
{
	
}


Settings::~Settings()
{
}