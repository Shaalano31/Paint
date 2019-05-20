#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class PasteAction:public Action {
private:
	Point P;
public:
	PasteAction(ApplicationManager*pManager);
	virtual void Execute();
	virtual void ReadActionParameters();
};