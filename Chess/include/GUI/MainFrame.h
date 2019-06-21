#pragma once
#include <afx.h>
#include <afxwin.h>
class MainFrame :
	public CFrameWnd
{
protected:
	void OnNewGame();
	void OnExit();
public:
	MainFrame();
	~MainFrame();

	DECLARE_MESSAGE_MAP();
};

