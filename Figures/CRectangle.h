#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point P1;	
	Point P3;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool SelectFigure(Point);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &InFile);
	GfxInfo GetGfxInfo();
	void PrintInfo(Output* pOut);
	virtual Point Shift(Point&p, Point&p8);
	virtual int FigureType();
};

#endif