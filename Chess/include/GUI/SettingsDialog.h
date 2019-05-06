#pragma once
#include <afxwin.h>
class SettingsDialog :
	public CDialog
{
protected:
	void OnTimerCheckBoxClick();
	BOOL OnInitDialog();
public:
	SettingsDialog();
	~SettingsDialog();
	DECLARE_MESSAGE_MAP();
};

