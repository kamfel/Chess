#pragma once
#include <afxwin.h>

class Game;

class SettingsDialog :
	public CDialog
{
protected:

	void OnOK() override;

	void OnTimerCheckBoxClick();

	BOOL OnInitDialog() override;

public:
	SettingsDialog();
	~SettingsDialog();
	DECLARE_MESSAGE_MAP();
};

