#include "GUI/MainFrame.h"
#include "../resource.h"
#include "GUI/SettingsDialog.h"
#include <afxwin.h>

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)

	ON_COMMAND(ID_USTAWIENIA, OnSettings)
	ON_COMMAND(ID_GRA_NOWAGRA, OnNewGame)
	ON_COMMAND(ID_GRA_WCZYTAJ, OnLoadGame)
	ON_COMMAND(ID_GRA_ZAPISZ, OnSaveGame)
	ON_COMMAND(ID_GRA_ZAMKNIJ, OnExit)

END_MESSAGE_MAP()

void MainFrame::OnSettings()
{
	SettingsDialog dialog;
	dialog.DoModal();
}

void MainFrame::OnNewGame()
{
	MessageBox("nowa");
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
	PostMessage(WM_CLOSE);
}

MainFrame::MainFrame()
{
	RECT wnd_rect = { 600, 400, 1200, 900};
	Create(NULL, _T("Chess"), WS_OVERLAPPEDWINDOW, wnd_rect, nullptr, MAKEINTRESOURCE(IDR_MENU));
}


MainFrame::~MainFrame()
{
}
