#pragma once
#include "Board.h"
#include <string>
#include "SFML/Graphics/RenderWindow.hpp"
#include "GraphicsHolder.h"

enum COLOUR;

/*! \brief Main class of the game
*
* Provides methods to interact with the game
*/
class Game
{
private:

	GraphicsHolder m_textures; ///< Conatiner holding textures for the game

	sf::RenderWindow m_main_window; ///< Window which the game will render to

	Board m_board; ///< Board containing information about the board and pieces

	COLOUR m_has_move; ///< The player which has move

	bool m_is_check; ///< True if previous move checked the player

	bool m_is_locked = false; ///<Lock game when checkmate or stalemate

public:
	/*! \brief Constructor
	*
	* \exception std::exception May throw if textures weren't loaded properly
	*
	* \param wndhandle Handle to window in which the game is played
	*/
	Game(sf::WindowHandle& wndhandle);
	~Game();

	/*! \brief Check if game was finished
	*
	* Checks if game was finished by stalemate or checkmate
	* \return true if game was finished; false otherwise
	*/
	bool IsGameFinished() { return m_is_locked; }

	/*! \brief Starts a new game
	*
	* Previous game state is discarded
	*/
	void StartNewGame();

	/*! \brief Calls game event handler
	*
	* Checks if game was finished by stalemate or checkmate
	*/
	void CallEventHandler();

	/*! \brief Draws chess game to window associated with the game; also flips display buffers
	*
	*/
	void Draw();
};

