#pragma once
#include "SFML/Window.hpp"

class Game;
enum COLOUR;

/*! \brief Class for handling events
*
*/
class EventHandler
{
private:
	
	sf::Window& m_window; ///< Window which the event queue is associated with

 
	sf::Event m_event; ///< Currently handled event

	/*! \brief Handles mouse button events
	*
	* Checks if click was made on the board and then tries to click or move piece
	* \param board Board which the game is played on
	* \param player_colour Colour of player clicking
	* \return true if game can switch to next player; false otherwise
	*/
	bool HandleMouseButtonPressed(Board& board, COLOUR player_colour);

public:
	EventHandler() = delete;
	EventHandler(sf::Window& window);

	~EventHandler();

	/*! \brief Handles all events in the event queue
	*
	* \param board Board which the game is played on
	* \param player_colour Colour of current player
	* \return true if game can switch to next player; false otherwise
	*/
	bool HandleEvents(Board& board, COLOUR player_colour);
};

