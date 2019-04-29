#pragma once
#include "GUIBase.h"
class Label :
	public GUIBase
{
public:
	Label();
	virtual ~Label();

	virtual void OnClick() override {
		int a = 1;
		int b = 2;
	}
};

