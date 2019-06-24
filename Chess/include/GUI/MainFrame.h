#pragma once
#include <afx.h>
#include <afxwin.h>

/*! \brief Frame of the main window
*
* Main frame which contains handlers for menu buttons
*/
class MainFrame :
	public CFrameWnd
{
protected:
	/*! \brief Called when New Game is chosen
	*
	* Calls game object to create new game
	*/
	void OnNewGame();
	/*! \brief Called when Exit is chosen
	*
	* Posts quit message to the application
	*/
	void OnExit();
public:
	/*! \brief Default constructor
	*
	* Creates window with default values stored in Definitions.h
	*/
	MainFrame();
	~MainFrame();

	/*! \brief MFC message map declaration
	*
	* 
	*/
	DECLARE_MESSAGE_MAP();
};

