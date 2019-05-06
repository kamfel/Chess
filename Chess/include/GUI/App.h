#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <afxwin.h>

class App : 
	public CWinApp
{
private:
	MainFrame* m_pframe;
public:
	~App();

	BOOL InitInstance();
};