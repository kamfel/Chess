#include "GUI/SettingsDialog.h"
#include "Logic/Game.h"
#include "../resource.h"
#include <regex>
#include "GUI/App.h"

extern App theApp;

BEGIN_MESSAGE_MAP(SettingsDialog, CDialog)

	ON_COMMAND(IDC_OK, OnOK)
	ON_COMMAND(IDC_CANCEL, OnCancel)
	ON_CONTROL(BN_CLICKED, IDC_WITHTIME, OnTimerCheckBoxClick)

END_MESSAGE_MAP()

void SettingsDialog::OnOK()
{
	//Get handles of dialogbox's controls
	CButton* button = (CButton*)(GetDlgItem(IDC_WITHTIME));
	CEdit* edit = (CEdit*)(GetDlgItem(IDC_EDIT_TIME));

	//Check if the button was checked
	bool on_time = button->GetCheck() == BST_CHECKED;

	//If the button isn't checked there isn't anything else to check
	if (!on_time) CDialog::OnOK();

	//Get time from edit control
	CString string;
	edit->GetWindowText(string);

	//Content of edit control should be properly formatted
	std::regex regex_time("[0-9][0-9]:[0-9][0-9]");

	if (!std::regex_match(string.GetString(), regex_time)) {
		//Podany czas jest nieprawid³owy
		MessageBox("Niepoprawny czas. Powinien byæ formatu mm:ss", "B³¹d", MB_OK);

		//Okno dialogowe nie zostanie zamkniête
		return;
	}

	//Extract time from string
	int minutes = -1;
	int seconds = -1;
	sscanf_s(string.GetString(), "%d:%d", &minutes, &seconds);

	//Apply new settings
	Settings settings(on_time, minutes * 60 + seconds);
	theApp.GetGame()->ApplySettings(settings);

	//Zakmniêcie okna dialogowego
	CDialog::OnOK();
}

void SettingsDialog::OnTimerCheckBoxClick()
{
	//Get handles of dialogbox's controls
	CButton* button = (CButton*)(GetDlgItem(IDC_WITHTIME));
	CEdit* edit = (CEdit*)(GetDlgItem(IDC_EDIT_TIME));

	//When time checbox is clicked the user should be able to input time
	if (button->GetCheck() == BST_UNCHECKED) {
		edit->ShowWindow(SW_HIDE);
		edit->EnableWindow(0);
	}
	else {

		edit->ShowWindow(SW_SHOW);
		edit->EnableWindow();
	}
}

BOOL SettingsDialog::OnInitDialog()
{
	CButton* button = (CButton*)(GetDlgItem(IDC_WITHTIME));
	CEdit* edit = (CEdit*)(GetDlgItem(IDC_EDIT_TIME));
	edit->SetLimitText(5);

	//Set edit contol content to current time
	Settings cur_settings = theApp.GetGame()->GetCurrentSettings();
	long long time_int_seconds = static_cast<long long>(cur_settings.GetTimeAmountForPlayers().asSeconds());
	CTimeSpan timespan(time_int_seconds);
	CString string = timespan.Format("%M:%S");
	edit->SetWindowText(string);

	//Should edit control be visible
	//By default it is not visible
	if (cur_settings.IsTimeOn()) {
		button->SetCheck(BST_CHECKED);
		edit->ShowWindow(SW_SHOW);
		edit->EnableWindow();
	}
	return TRUE;
}

SettingsDialog::SettingsDialog()
	: CDialog(IDD_SETTINGS)
{
}

SettingsDialog::~SettingsDialog()
{
}
