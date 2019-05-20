#pragma once
#include "Actions\Action.h"
#include "Figures\CRectangle.h"
#include "Figures\CLine.h"
#include "Figures\CTriangle.h"
#include "Figures\CRhombus.h"
#include "Figures\CEllipse.h"

class PlayMode : public Action
{
protected:
	int Correct, Incorrect, CountFig, Chosen, Count;
	Point P1;
	CFigure **ListF;
	Output* pOut;
	Input* pIn;
public:
	PlayMode(ApplicationManager * pApp);
	virtual void ReadActionParameters() = 0;
	virtual void Execute() = 0;
	void UpdateScore(bool);
	void DeleteFigure(CFigure **Figure);
	~PlayMode();
};

