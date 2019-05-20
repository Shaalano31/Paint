#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.FillClr = Fclr;
	FigGfxInfo.isFilled = true;
}
color CFigure::GetFillClr() {
	return UI.FillColor;

}
void CFigure::SetID(int id) {
	ID = id;
}
bool CFigure::InDrawingArea(Point P)
{
	return (P.x >= 5 && P.x <= 1250 && P.y >= 50 && P.y <= 600);
}

