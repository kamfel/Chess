#pragma once
#include "SFML/System/Time.hpp"
#include "GUI/SettingsDialog.h"

class Settings
{
private:
	bool m_highlight = 0;
	bool m_piece_size = 0;
	bool m_time_on = 0;
	sf::Time m_time = sf::Time::Zero;
public:
	Settings();
	Settings(bool highlight, bool piece_size, bool time_on, sf::Time time);
	~Settings();

	void ApplyChanges(const Settings& settings);

	friend SettingsDialog;
};

