#include "AddEllipseAction.h"
#include "AddLineAction.h"
#include "ApplicationManager.h"
#include "Figures/CEllipse.h"
#include "GUI/Output.h"
#include "GUI/Input.h"


AddEllipseAction::AddEllipseAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddEllipseAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Ellipse: Click at first Point");
	while(1) //while loop to check if the point is inside the drawing area
	{
	pIn->GetPointClicked(P.x, P.y);
	if (CEllipse::InDrawingArea(P) == 0) 
		pOut->PrintMessage("Out of Drawing Area, Re-click the point!");
	else
		break;
	}
	
	EllipGfxInfo.isFilled = UI.IsFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
void AddEllipseAction::Execute() {
	ReadActionParameters();
	CEllipse* E = new CEllipse(P, EllipGfxInfo);
	pManager->AddFigure(E);
	E->SetID(pManager->GetFigureCount());
}