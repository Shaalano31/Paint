#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	while (1) {
		pIn->GetPointClicked(P1.x, P1.y);
		if (CRectangle::InDrawingArea(P1) == 0)
			pOut->PrintMessage("Out of Drawing Area, Re-click!");
		else
			break;
	}
	pOut->PrintMessage("New Rectangle: Click at Second corner");
	while (1) {
		pIn->GetPointClicked(P2.x, P2.y);
		if (CRectangle::InDrawingArea(P2) == 0)
			pOut->PrintMessage("Out of Drawing Area, Re-click!");
		else
			break;
	}
	RectGfxInfo.isFilled = UI.IsFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);
	

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	R->SetID(pManager->GetFigureCount());
}
