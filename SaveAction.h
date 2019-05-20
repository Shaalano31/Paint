#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include <fstream>

class SaveAction : public Action
{
	string filename;
	ofstream OutFile;
	
public:
	SaveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SaveAction();
};

