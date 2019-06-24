#pragma once
#include "GUI/MainFrame.h"
#include "Logic/Game.h"
#include <afxwin.h>

/*! \brief Main application class
 *
 *  Class which represents the application. Contains all methods required for starting the application
 */
class App : 
	public CWinApp
{
private:

	MainFrame* m_pframe; ///< Pointer to the main frame of GUI

	CWnd* m_pgamewnd; ///< Pointer to window containing the chess game

	Game* m_pgame; ///< Pointer to game object, which GUI interacts with

	bool m_finished; ///< Boolean true when game has finished because of checkmate or stalemate
public:
	App();
	~App();

	/*! \brief Get pointer to game object
	*
	* \return Pointer to object which represents the game
	*/
	Game* GetGame() { return m_pgame; }

	/*! \brief Function called at application startup; equivalent to main
	*
	* Sets up windows and game object at startup
	* \return TRUE if initialisation was succesful
	*/
	BOOL InitInstance();

	/*! \brief Function called when GUI is idling
	*
	* Calls event handler for chess core and calls drawing method for the game
	* \return FALSE if no more idle processing time is needed
	*/
	BOOL OnIdle(LONG iCount) override;
};