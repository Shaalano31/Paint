#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <fstream>
#include <iostream>
class SaveByType :public Action
{
	string FileName;
	ofstream outfile;
	ActionType A;
	
	
public:
	
	SaveByType(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SaveByType();
};

