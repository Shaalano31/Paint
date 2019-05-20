#include "CRhombus.h"



CRhombus::CRhombus(Point Pp,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P = Pp; 
	FigGfxInfo.FillClr = FigureGfxInfo.FillClr;
	FigGfxInfo.isFilled = FigureGfxInfo.isFilled;
}

void CRhombus::Draw(Output* pOut)const{
	pOut->DrawRhombus(P, FigGfxInfo, Selected);
}
void CRhombus::Save(ofstream &OutFile)
{
	OutFile << "RHOMBUS" << '\t' << ID << '\t' << P.x << '\t' << P.y << '\t';
	color d1 = FigGfxInfo.DrawClr;
	color f1 = FigGfxInfo.FillClr;
	if (d1 == BLACK) // If to check Drawing Color
		OutFile << "BLACK" << '\t';
	else if (d1 == WHITE)
		OutFile << "WHITE" << '\t';
	else if (d1 == RED)
		OutFile << "RED" << '\t';
	else if (d1 == GREEN)
		OutFile << "GREEN" << '\t';
	else if (d1 == BLUE)
		OutFile << "BLUE" << '\t';

	if (f1 == BLACK) // If to check Filling Color
		OutFile << "BLACK" << '\n';
	else if (f1 == WHITE)
		OutFile << "WHITE" << '\n';
	else if (f1 == RED)
		OutFile << "RED" << '\n';
	else if (f1 == GREEN)
		OutFile << "GREEN" << '\n';
	else if (f1 == BLUE)
		OutFile << "BLUE" << '\n';
	else 
		OutFile << "NOT_FILLED" << '\n';
}
void CRhombus::Load(ifstream &InFile)
{
	string Drawc, Fillc;
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
bool CRhombus::SelectFigure(Point A){
	Point P1; P1.x = P.x + 100; P1.y = P.y;
	Point P2; P2.x = P.x - 100; P2.y = P.y;
	Point P3; P3.x = P.x; P3.y = P.y + 200;
	Point P4; P4.x = P.x; P4.y = P.y - 200;
double Area = abs((((P1.x)*(P2.y - P3.y) + (P2.x)*(P3.y - P1.y) + (P3.x)*(P1.y - P2.y)) / 2) + 
				(((P1.x)*(P4.y - P3.y) + (P4.x)*(P3.y - P1.y) + (P4.x)*(P1.y - P4.y)) / 2));
double Area1 = abs((A.x)*(P2.y - P3.y) + (P2.x)*(P3.y - A.y) + (P3.x)*(A.y - P2.y)) / 2;
double Area2 = abs((A.x)*(P4.y - P3.y) + (P4.x)*(P3.y - A.y) + (P3.x)*(A.y - P4.y)) / 2;
double Area3 = abs((A.x)*(P1.y - P2.y) + (P1.x)*(P2.y - A.y) + (P2.x)*(A.y - P1.y)) / 2;
double Area4 = abs((A.x)*(P4.y - P1.y) + (P4.x)*(P1.y - A.y) + (P1.x)*(A.y - P4.y)) / 2;
return(Area >= Area1 + Area2 + Area3 + Area4);
	///*float Area = (abs((A.x) / 100)) + (abs((A.y) / 200));
	//if (Area <= 1.0) {
	//	SetSelected(true);
	//	return true;
	//}
	//return false;*/
}
GfxInfo CRhombus::GetGfxInfo() {
	return FigGfxInfo;
}
void CRhombus::PrintInfo(Output* pOut) {
	string id = to_string(ID);
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
	pOut->PrintMessage("Rhombus of ID " + id + " ,Center is (" + to_string(P.x) +","+ to_string(P.y)+") Two diagonals are 200,400" + " ,Color of Figure is: " + clrr);
}

Point CRhombus::Shift(Point&p, Point &p8) 
{
	Point Shiftedpoint;
	Shiftedpoint.x = 0;
	Shiftedpoint.y = 0;
	return Shiftedpoint;
}
int CRhombus::FigureType() 
{
	return 4;
}