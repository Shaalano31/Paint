#pragma once
#include "Actions/Action.h"
class AddSelectAction :
	public Action
{
private:
	Point P;
public:
	AddSelectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void UnSelect();
	virtual void Execute();
	//void SelectionCheck(CFigure* c);
};

