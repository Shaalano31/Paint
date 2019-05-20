#pragma once
#include "Actions/Action.h"
#include <fstream>
#include "Figures/CEllipse.h"
#include "Figures/CLine.h"
#include "Figures/CRectangle.h"
#include "Figures/CRhombus.h"
#include "Figures/CTriangle.h";

class LoadFiguresAction :
	public Action
{
	string FileName;
	ifstream InFile;
public:
	LoadFiguresAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~LoadFiguresAction();
};

