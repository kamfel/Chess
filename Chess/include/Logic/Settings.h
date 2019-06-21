#pragma once
#include "SFML/System/Time.hpp"
#include "GUI/SettingsDialog.h"

class Settings
{
private:
	bool m_time_on = 0;
	sf::Time m_time = sf::Time::Zero;
public:
	Settings();
	Settings(bool time_on, long long time_in_seconds);
	~Settings();

	bool IsTimeOn() const { return m_time_on; }
	sf::Time GetTimeAmountForPlayers() const { return m_time; }
};

