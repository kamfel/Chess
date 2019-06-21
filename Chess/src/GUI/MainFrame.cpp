#include "GUI/MainFrame.h"
#include "../resource.h"
#include "GUI/SettingsDialog.h"
#include <afxwin.h>
#include "GUI/App.h"
#include "Definitions.h"

extern App theApp;

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)

	ON_COMMAND(ID_GRA_NOWAGRA, OnNewGame)
	ON_COMMAND(ID_GRA_ZAMKNIJ, OnExit)

END_MESSAGE_MAP()

//---------------------------------------
//Menu message handlers
//---------------------------------------

void MainFrame::OnNewGame()
{
	theApp.GetGame()->StartNewGame();
}

void MainFrame::OnExit()
{
	PostMessage(WM_CLOSE);
}

//---------------------------------------
//End menu message handlers
//---------------------------------------

MainFrame::MainFrame()
{
	RECT wnd_rect = { 200, 200, 200 + CHESS_MAIN_WINDOW_SIZE_X, 200 + CHESS_MAIN_WINDOW_SIZE_Y};
	Create(NULL, _T("Chess"), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_BORDER | WS_MINIMIZEBOX, wnd_rect, nullptr, MAKEINTRESOURCE(IDR_MENU));
}


MainFrame::~MainFrame()
{
}
