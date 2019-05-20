#include "CLine.h"



CLine::CLine(Point Pp1,Point Pp2, GfxInfo FigGfxInfo):CFigure(FigGfxInfo)
{
	P1 = Pp1;
	P2 = Pp2;
}


void CLine::Draw(Output* pOut)const {
	pOut->DrawLine(P1, P2, FigGfxInfo, Selected);
}

bool CLine::SelectFigure(Point A) {
	////y = a * x + b; //   where a is slope
	//const float Precision = 0.0000000000000000000000000000000000001f;  //as float precision roundings will screw up the calculations

	//float a = (P2.y - P1.y) / (P2.x - P1.x);
	//float b = P1.y - a * P1.x;

	//SetSelected(abs(A.y - (a*A.x + b)) <= Precision);
	//return(abs(A.y - (a*A.x + b)) <= Precision);
	//
	bool betweeny;
	if (P1.y > P2.y) 
		betweeny = (A.y<=P1.y&&A.y>=P2.y);
	else if(P1.y<P2.y)
		betweeny = (A.y>=P1.y&&A.y<=P2.y);

	bool betweenx;
	if (P1.x > P2.x)
		betweenx = (A.x<P1.x&&A.x>P2.x);
	else
		betweenx = (A.x<P2.x&&A.x>P1.x);
			
		return(((A.x - P1.x) / (P2.x - A.x) == (A.y - P1.y) / (P2.y - A.y)) && betweeny&&betweenx);
	
}
GfxInfo CLine::GetGfxInfo() {
	return FigGfxInfo;
}
void CLine::Save(ofstream &OutFile)
{
	OutFile << "LINE" << '\t' << ID << '\t' << P1.x << '\t' << P1.y << '\t' << P2.x << '\t' << P2.y << '\t';
	color d2 = FigGfxInfo.DrawClr;
	if (d2 == BLACK) // If to check Drawing Color
		OutFile << "BLACK" << '\n';
	else if (d2 == WHITE)
		OutFile << "WHITE" << '\n';
	else if (d2 == RED)
		OutFile << "RED" << '\n';
	else if (d2 == GREEN)
		OutFile << "GREEN" << '\n';
	else if (d2 == BLUE)
		OutFile << "BLUE" << '\n';
	
}
void CLine::Load(ifstream &InFile)
{
	string Drawc, Fillc;
	InFile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> Drawc >> Fillc;

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
}

void CLine::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	double length = sqrt(((P2.x - P1.x)*(P2.x - P1.x)) + ((P2.y - P1.y)*(P2.y - P1.y)));
	string lnth = to_string(length / 1.00);
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
	pOut->PrintMessage("Line of ID " + id + " Starting Point is " + to_string(P1.x) + "," + to_string(P1.y) + "), Ending Point is (" + to_string(P2.x) + "," + to_string(P2.y) + ")," + " Length is" + lnth + " ,Color of Figure is: " + clrr);
}

Point CLine::Shift(Point&p, Point &p8)
{
	Output*pOut;
	Point Shiftedpoint;
	Point P4;
	P4.x = p.x - P1.x;
	P4.y = p.y - P1.y;
	Shiftedpoint.x = P2.x + P4.x;
	Shiftedpoint.y = P2.y + P4.y;
	return Shiftedpoint;
}
int CLine::FigureType() 
{
	return 2;
}