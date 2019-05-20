#pragma once
#include "CFigure.h"
class CLine :
	public CFigure
{
private:
	Point P1;
	Point P2;
public:
	CLine(Point, Point, GfxInfo);
	virtual void Draw(Output* pOut) const;
	bool SelectFigure(Point);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &InFile);
	GfxInfo GetGfxInfo();
	void PrintInfo(Output* pOut);
	virtual Point Shift(Point&p, Point&p8);
	virtual int FigureType();
};

