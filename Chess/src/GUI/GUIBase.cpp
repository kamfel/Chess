#include "GUI\GUIBase.h"



GUIBase::GUIBase()
{
}


GUIBase::~GUIBase()
{
}

void GUIBase::SetOnClickCallback(void* callback_fun)
{
	int x = 1;
	OnClickCallback = (void (*)(...))callback_fun;
	OnClickCallback(x);
}
