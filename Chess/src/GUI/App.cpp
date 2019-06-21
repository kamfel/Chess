#define _CRTDBG_MAP_ALLOC

#include <afxwin.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "SFML/Window.hpp"
#include "../resource.h"

#include "GUI/App.h"
#include "Definitions.h"
#include "GUI/GameWnd.h"

App theApp;

App::App()
{
}

App::~App()
{
	delete m_pgamewnd;
	delete m_pgame;
}

BOOL App::InitInstance()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Initialize common control classes
	INITCOMMONCONTROLSEX commctl;
	commctl.dwSize = sizeof(INITCOMMONCONTROLSEX);
	commctl.dwICC = ICC_STANDARD_CLASSES;
	InitCommonControlsEx(&commctl);
	//---------------------------------

	//Create and show main frame
	m_pframe = new MainFrame();
	if (!m_pframe) return FALSE;


	m_pgamewnd = new GameWnd();
	m_pgamewnd->Create("#32769", "DrawingContext", WS_CHILD | WS_VISIBLE, { 0, 0, CHESS_MAIN_WINDOW_SIZE_X - 20, CHESS_MAIN_WINDOW_SIZE_Y - 40 }, m_pframe, 1000);

	sf::WindowHandle wnd = m_pgamewnd->GetSafeHwnd();

	m_pgame = new Game(wnd);

	m_pMainWnd = m_pframe;
	m_pframe->ShowWindow(SW_NORMAL);
	m_pframe->UpdateWindow();
	//---------------------------------

	return TRUE;
}

BOOL App::OnIdle(LONG iCount)
{
	m_pgame->CallEventHandler();
	m_pgame->Draw();

	if (m_pgame->IsGameFinished() && m_finished) {
		m_pframe->MessageBox("Koniec gry", "Koniec", MB_OK);
		m_finished = false;
	}

	return CWinApp::OnIdle(iCount);
}
