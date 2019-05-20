#include "CEllipse.h"
# define PI           3.14159265358979323846
#include <fstream>
#include "../GUI/Input.h"
#include "../ApplicationManager.h"


CEllipse::CEllipse(Point Pp1,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P = Pp1;
	FigGfxInfo.FillClr = FigureGfxInfo.FillClr;
	FigGfxInfo.isFilled = FigureGfxInfo.isFilled;
}

void CEllipse::Draw(Output* pOut)const {
	pOut->DrawEllipse(P,FigGfxInfo, Selected);
}

bool CEllipse::SelectFigure(Point A) {
	float Area = (((A.x - P.x)*(A.x - P.x)) / (145*145)) + (((A.y - P.y)*(A.y - P.y)) / (71*71));
		return(Area <= 1);
}
GfxInfo CEllipse::GetGfxInfo() { 
	return FigGfxInfo;
}
void CEllipse::Save(ofstream &OutFile)
{
	OutFile << "ELLIPSE" << '\t' << ID << '\t' << P.x << '\t' << P.y << '\t';
	color d = FigGfxInfo.DrawClr;
	color f = FigGfxInfo.FillClr;
	if (d == BLACK) // If to check Drawing Color
		OutFile << "BLACK" << '\t';
	else if (d == WHITE)
		OutFile << "WHITE" << '\t';
	else if (d == RED)
		OutFile << "RED" << '\t';
	else if (d == GREEN)
		OutFile << "GREEN" << '\t';
	else if (d == BLUE)
		OutFile << "BLUE" << '\t';

	if (f == BLACK) //If to check Filling Color
		OutFile << "BLACK" << '\n';
	else if (f == WHITE)
		OutFile << "WHITE" << '\n';
	else if (f == RED)
		OutFile << "RED" << '\n';
	else if (f == GREEN)
		OutFile << "GREEN" << '\n';
	else if (f == BLUE)
		OutFile << "BLUE" << '\n';
	else 
		OutFile << "NOT_FILLED" << '\n';

}
void CEllipse::Load(ifstream &InFile)
{
	string Drawc , Fillc ;
	InFile >> ID >> P.x >> P.y >> Drawc >> Fillc;

	if (Drawc == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (Drawc == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (Drawc == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (Drawc == "BLUE")
		FigGfxInfo.DrawClr = BLUE;
	else if (Drawc == "WHITE")
		FigGfxInfo.DrawClr = WHITE;



	if (Fillc == "BLACK")
		FigGfxInfo.FillClr = BLACK;
	else if (Fillc == "RED")
		FigGfxInfo.FillClr = RED;
	else if (Fillc == "GREEN")
		FigGfxInfo.FillClr = GREEN;
	else if (Fillc == "BLUE")
		FigGfxInfo.FillClr = BLUE;
	else if (Fillc == "WHITE")
		FigGfxInfo.FillClr = WHITE;

}
void CEllipse::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	string Area =to_string((PI*100*50)/1.00);
	string clrr;
	if (FigGfxInfo.FillClr == BLACK)
		clrr = "Black";
	else if (FigGfxInfo.FillClr == RED)
		clrr = "Red";
	else if (FigGfxInfo.FillClr == GREEN)
		clrr = "Green";
	else if (FigGfxInfo.FillClr == BLUE)
		clrr = "Blue";
	else if (FigGfxInfo.FillClr == WHITE)
		clrr = "White";
	else
		clrr = "UnColored";
	pOut->PrintMessage("Ellipse with id Of " + id + ", The two radii are 100,50 , Area is " + Area+" ,Center is ("+to_string(P.x)+","+to_string(P.y)+")"+" ,Color of Figure is: "+clrr);
}

Point CEllipse::Shift(Point&p, Point &p8) 
{
	Point P;
	P.x = 0;
	P.y = 0;
	return P;
}
int CEllipse::FigureType() 
{
	return 1;
}