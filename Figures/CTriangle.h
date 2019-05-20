#pragma once
#include "CFigure.h"
#include <cstring>
class CTriangle :
	public CFigure
{
private:
	Point P1;
	Point P2;
	Point P3;
public:
	CTriangle(Point , Point , Point , GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool SelectFigure(Point);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &InFile);
	GfxInfo GetGfxInfo();
	void PrintInfo(Output* pOut);
	virtual Point Shift(Point&p, Point&p8);
	virtual int FigureType();
};



