#include <afxwin.h>
#include "GUI/App.h"
#include "GUI/MainFrame.h"
#include "../resource.h"
#include <memory>

App theApp;

App::~App()
{
	delete m_pframe;
}

BOOL App::InitInstance()
{
	//Initialize common control classes
	INITCOMMONCONTROLSEX commctl;
	commctl.dwSize = sizeof(INITCOMMONCONTROLSEX);
	commctl.dwICC = ICC_STANDARD_CLASSES;
	InitCommonControlsEx(&commctl);
	//---------------------------------

	//Create and show main frame
	m_pframe = new MainFrame();
	if (!m_pframe) return FALSE;

	m_pMainWnd = m_pframe;
	m_pframe->ShowWindow(SW_NORMAL);
	m_pframe->UpdateWindow();
	//---------------------------------

	return TRUE;
}
