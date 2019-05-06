#include "GUI/SettingsDialog.h"
#include "../resource.h"

BEGIN_MESSAGE_MAP(SettingsDialog, CDialog)

	ON_COMMAND(IDC_OK, OnOK)
	ON_COMMAND(IDC_CANCEL, OnCancel)
	ON_CONTROL(BN_CLICKED, IDC_WITHTIME, OnTimerCheckBoxClick)

END_MESSAGE_MAP()

void SettingsDialog::OnTimerCheckBoxClick()
{
	CButton* button = (CButton*)(GetDlgItem(IDC_WITHTIME));
	CEdit* edit = (CEdit*)(GetDlgItem(IDC_EDIT_TIME));
	if (button->GetCheck() == BST_UNCHECKED) {
		edit->ShowWindow(SW_HIDE);
		edit->EnableWindow(0);
	}
	else {
		edit->ShowWindow(SW_SHOW);
		edit->EnableWindow();
		//TODO: Print current settings to edit
	}
}

BOOL SettingsDialog::OnInitDialog()
{

	return 0;
}

SettingsDialog::SettingsDialog()
	: CDialog(IDD_SETTINGS)
{
}

SettingsDialog::~SettingsDialog()
{
}
