#define _CRTDBG_MAP_ALLOC

#include <afxwin.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "SFML/Window.hpp"
#include "../resource.h"

#include "GUI/App.h"

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


	m_pgamewnd = new CWnd();
	m_pgamewnd->Create(_T("STATIC"), "DrawingContext", WS_CHILD | WS_VISIBLE, { 0, 0, 600, 450 }, m_pframe, 1000);

	sf::WindowHandle wnd = m_pgamewnd->GetSafeHwnd();

	m_pgame = new Game(wnd);
	m_pgame->Run();

	m_pMainWnd = m_pframe;
	m_pframe->ShowWindow(SW_NORMAL);
	m_pframe->UpdateWindow();
	//---------------------------------

	return TRUE;
}
