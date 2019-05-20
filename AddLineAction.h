#pragma once
#include "Actions/Action.h"
class AddLineAction:public Action
{
private:
	Point P1;
	Point P2;
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

