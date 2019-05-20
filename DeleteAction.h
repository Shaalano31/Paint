#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
class DeleteAction :public Action {
private:
	Point P1;
public:
	DeleteAction(ApplicationManager*pmanager);
	virtual void Execute();
	virtual void ReadActionParameters();
};