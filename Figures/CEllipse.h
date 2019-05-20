#pragma once
#include "CFigure.h"
#include <fstream>
class CEllipse :
	public CFigure
{
private:
	Point P;
public:
	CEllipse(Point,GfxInfo);
	virtual void Draw(Output* pOut) const;
	bool SelectFigure(Point);
	GfxInfo GetGfxInfo();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &InFile);
	void PrintInfo(Output* pOut);
	virtual Point Shift(Point&p, Point&p8);
	virtual int FigureType();
};

