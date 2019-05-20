#pragma once
#include "Actions/Action.h"
class ChangeFillClrAction :
	public Action
{
private:
	
	color Fillcolr;
public:
	ChangeFillClrAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

