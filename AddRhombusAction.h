#pragma once
#include "Actions/Action.h"

class AddRhombusAction :
	public Action
{
private:
	Point P;
	GfxInfo RhombusGfxInfo;
public:
	AddRhombusAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	
};

