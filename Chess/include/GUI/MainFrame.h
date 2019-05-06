#pragma once
#include <afx.h>
#include <afxwin.h>
class MainFrame :
	public CFrameWnd
{
protected:
	void OnSettings();
	void OnNewGame();
	void OnLoadGame();
	void OnSaveGame();
	void OnExit();
public:
	MainFrame();
	~MainFrame();
	DECLARE_MESSAGE_MAP();
};

