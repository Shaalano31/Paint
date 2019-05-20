#include "CRectangle.h"

CRectangle::CRectangle(Point Pp1, Point Pp2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = Pp1;
	P3 = Pp2;
	FigGfxInfo.FillClr = FigureGfxInfo.FillClr;
	FigGfxInfo.isFilled = FigureGfxInfo.isFilled;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(P1, P3, FigGfxInfo, Selected);
}
void CRectangle::Save(ofstream &OutFile)
{
	OutFile << "REC" << '\t' << ID << '\t' << P1.x << '\t' << P1.y << '\t' << P3.x << '\t' << P3.y << '\t';
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
void CRectangle::Load(ifstream &InFile)
{
	string Drawc, Fillc;
	InFile >> ID >> P1.x >> P1.y >> P3.x >> P3.y >> Drawc >> Fillc;

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
	{
		FigGfxInfo.FillClr = BLACK; FigGfxInfo.isFilled = true;
	}
	else if (Fillc == "RED")
	{FigGfxInfo.FillClr = RED;  FigGfxInfo.isFilled = true;}
	else if (Fillc == "GREEN")
	{
		FigGfxInfo.FillClr = GREEN;  FigGfxInfo.isFilled = true;
	}
	else if (Fillc == "BLUE")
	{
		FigGfxInfo.FillClr = BLUE;
		FigGfxInfo.isFilled = true;
	}
	else if (Fillc == "WHITE")
	{
		FigGfxInfo.FillClr = WHITE;
		FigGfxInfo.isFilled = true;
	}
}
bool CRectangle::SelectFigure(Point A) 
{
	return ((A.x >= P1.x) && (A.x <= P3.x) && (A.y >= P1.y) && (A.y <= P3.y));
	/*Point P2;
	Point P4;
		P2.x = P3.x; P2.y = P1.y;
		P4.x = P1.x; P4.y = P3.y;
		double Area = abs((((P1.x)*(P2.y - P3.y) + (P2.x)*(P3.y - P1.y) + (P3.x)*(P1.y - P2.y)) / 2)) +
			abs((((P1.x)*(P4.y - P3.y) + (P4.x)*(P3.y - P1.y) + (P4.x)*(P1.y - P4.y)) / 2));
		double Area1 = abs((A.x)*(P2.y - P3.y) + (P2.x)*(P3.y - A.y) + (P3.x)*(A.y - P2.y)) / 2;
		double Area2 = abs((A.x)*(P4.y - P3.y) + (P4.x)*(P3.y - A.y) + (P3.x)*(A.y - P4.y)) / 2;
		double Area3 = abs((A.x)*(P1.y - P2.y) + (P1.x)*(P2.y - A.y) + (P2.x)*(A.y - P1.y)) / 2;
		double Area4 = abs((A.x)*(P4.y - P1.y) + (P4.x)*(P1.y - A.y) + (P1.x)*(A.y - P4.y)) / 2;
		SetSelected(Area >= Area1 + Area2 + Area3 + Area4);
		return(Area >= Area1 + Area2 + Area3 + Area4);*/		
}
GfxInfo CRectangle::GetGfxInfo() {
	return FigGfxInfo;
}

void CRectangle::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	string length = to_string(abs(P1.y - P3.y));
	string width  = to_string(abs(P1.x - P3.x)); 
	string area = to_string(abs(P1.y - P3.y)*abs(P1.x - P3.x));
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
	pOut->PrintMessage("Rectange of ID " + id + " ,Length of " + length + " ,Width of " + width + " ,Area Of " + area + " ,Color of Figure is: " + clrr);
}

Point CRectangle::Shift(Point&p, Point &p8) {
	//Output*pOut = NULL;
	Point Shiftedpoint;
	Point P4;
	P4.x = p.x - P1.x;
	P4.y = p.y - P1.y;
	Shiftedpoint.x = P3.x + P4.x;
	Shiftedpoint.y = P3.y + P4.y;
	return Shiftedpoint;
}
int CRectangle::FigureType() {
	return 3;
}