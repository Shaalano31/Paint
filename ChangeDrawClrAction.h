#pragma once
#include "Actions/Action.h"
class ChangeDrawClrAction :
	public Action
{
private:
	color Fillcolr;
public:
	ChangeDrawClrAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

