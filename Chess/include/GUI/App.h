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
public:
	App();
	~App();

	BOOL InitInstance();
	void testdraw() { m_pgame->Run(); }
};