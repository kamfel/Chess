#pragma once
#include "GUI/MainFrame.h"
#include "Logic/Game.h"
#include <afxwin.h>

class App : 
	public CWinApp
{
private:
	MainFrame* m_pframe;
	CWnd* m_pgamewnd;
	Game* m_pgame;

	bool m_finished;
public:
	App();
	~App();

	Game* GetGame() { return m_pgame; }

	BOOL InitInstance();

	BOOL OnIdle(LONG iCount) override;
};