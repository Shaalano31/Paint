#include "CTriangle.h"



CTriangle::CTriangle(Point Pp1,Point Pp2,Point Pp3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = Pp1;
	P2 = Pp2;
	P3 = Pp3;
	FigGfxInfo.FillClr = FigureGfxInfo.FillClr;
	FigGfxInfo.isFilled = FigureGfxInfo.isFilled;
}

void CTriangle::Draw(Output* pOut)const {
	pOut->DrawTri(P1,P2,P3,FigGfxInfo,Selected);
}
void CTriangle::Save(ofstream &OutFile)
{
	OutFile << "TRIANG" << '\t' << ID << '\t' << P1.x << '\t' << P1.y << '\t' << P2.x << '\t' << P2.y << '\t' << P3.x << '\t' << P3.y << '\t';
	color dd = FigGfxInfo.DrawClr;
	color ff = FigGfxInfo.FillClr;
	if (dd == BLACK) // If to check Drawing Color
		OutFile << "BLACK" << '\t';
	else if (dd == WHITE)
		OutFile << "WHITE" << '\t';
	else if (dd == RED)
		OutFile << "RED" << '\t';
	else if (dd == GREEN)
		OutFile << "GREEN" << '\t';
	else if (dd == BLUE)
		OutFile << "BLUE" << '\t';

	if (ff == BLACK) // If to check Drawing Color
		OutFile << "BLACK" << '\n';
	else if (ff == WHITE)
		OutFile << "WHITE" << '\n';
	else if (ff == RED)
		OutFile << "RED" << '\n';
	else if (ff == GREEN)
		OutFile << "GREEN" << '\n';
	else if (ff == BLUE)
		OutFile << "BLUE" << '\n';
	else
		OutFile << "NOT_FILLED" << '\n';
}
void CTriangle::Load(ifstream &InFile)
{
	string Drawc, Fillc;
	InFile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >>P3.y >> Drawc >> Fillc;

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
	else if (Drawc == "RED")
		FigGfxInfo.FillClr = RED;
	else if (Fillc == "GREEN")
		FigGfxInfo.FillClr = GREEN;
	else if (Fillc == "BLUE")
		FigGfxInfo.FillClr = BLUE;
	else if (Fillc == "WHITE")
		FigGfxInfo.FillClr = WHITE;
}
bool CTriangle::SelectFigure(Point A) {
	double Area = abs((P1.x)*(P2.y - P3.y) +(P2.x)*(P3.y-P1.y)+(P3.x)*(P1.y-P2.y))/2;
	double Area1= abs((A.x)*(P2.y - P3.y) + (P2.x)*(P3.y - A.y) + (P3.x)*(A.y - P2.y)) / 2;
	double Area2= abs((A.x)*(P1.y - P3.y) + (P1.x)*(P3.y - A.y) + (P3.x)*(A.y - P1.y)) / 2;
	double Area3= abs((A.x)*(P1.y - P2.y) + (P1.x)*(P2.y - A.y) + (P2.x)*(A.y - P1.y)) / 2;
	return (Area >= Area1 + Area2 + Area3);
}
GfxInfo CTriangle::GetGfxInfo() {
	return FigGfxInfo;
}

void CTriangle::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	double Area = abs((P1.x)*(P2.y - P3.y) + (P2.x)*(P3.y - P1.y) + (P3.x)*(P1.y - P2.y)) / 2;
	string area = to_string(Area/1.00);
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
	pOut->PrintMessage("Triangle of ID " + id + " Vertices are P1(" + to_string(P1.x) + "," + to_string(P1.y) + ") " + " P2(" + to_string(P2.x) + ", " + to_string(P2.y) + ") " + " P3(" + to_string(P3.x) + ", " + to_string(P3.y) + ") " + " ,Color of Figure is: " + clrr);
}

Point CTriangle::Shift(Point&p, Point &p8)
{
	Point P4; // delta
	P4.x = p.x - P1.x;
	P4.y = p.y - P1.y;
	Point Shiftedpoint;
	Shiftedpoint.x = P4.x + P2.x;
	Shiftedpoint.y = P4.y + P2.y;
	p8;
	p8.x = P4.x + P3.x;
	p8.y = P4.y + P3.y;
	return Shiftedpoint;
}
int CTriangle::FigureType() 
{
	return 5;
}