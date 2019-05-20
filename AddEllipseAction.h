#pragma once
#include "Actions/Action.h"
class AddEllipseAction :
	public Action
{
private:
	Point P;
	GfxInfo EllipGfxInfo;
public:
	AddEllipseAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

