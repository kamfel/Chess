#include "GUI/MainFrame.h"
#include "../resource.h"
#include "GUI/SettingsDialog.h"
#include <afxwin.h>
#include "GUI/App.h"

extern App theApp;

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)

	ON_COMMAND(ID_USTAWIENIA, OnSettings)
	ON_COMMAND(ID_GRA_NOWAGRA, OnNewGame)
	ON_COMMAND(ID_GRA_WCZYTAJ, OnLoadGame)
	ON_COMMAND(ID_GRA_ZAPISZ, OnSaveGame)
	ON_COMMAND(ID_GRA_ZAMKNIJ, OnExit)

END_MESSAGE_MAP()

//---------------------------------------
//Menu message handlers
//---------------------------------------

void MainFrame::OnSettings()
{
	SettingsDialog dialog;
	dialog.DoModal();
}

void MainFrame::OnNewGame()
{
	theApp.testdraw();
}

void MainFrame::OnLoadGame()
{
	MessageBox("wczytaj");
}

void MainFrame::OnSaveGame()
{
	MessageBox("zapisz");
}

void MainFrame::OnExit()
{
	CWnd* child = FindWindowEx(this->GetSafeHwnd(), NULL, NULL, "DrawingContext");
	child->DestroyWindow();
	PostMessage(WM_CLOSE);
}

//---------------------------------------
//End menu message handlers
//---------------------------------------

MainFrame::MainFrame()
{
	RECT wnd_rect = { 600, 400, 1210, 900};
	Create(NULL, _T("Chess"), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_BORDER | WS_MINIMIZEBOX, wnd_rect, nullptr, MAKEINTRESOURCE(IDR_MENU));
}


MainFrame::~MainFrame()
{
}
