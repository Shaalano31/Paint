#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



AddTriAction::AddTriAction(ApplicationManager *pApp):Action(pApp)
{

}

void AddTriAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	while (1) {
		pIn->GetPointClicked(P1.x, P1.y);
		if (CTriangle::InDrawingArea(P1) == 0)
			pOut->PrintMessage("Out of Drawing Area, Re-click!");
		else
			break;
	}
	pOut->PrintMessage("New Triangle: Click at Second corner");
	while (1) {
		pIn->GetPointClicked(P2.x, P2.y);
		if (CTriangle::InDrawingArea(P2) == 0)
			pOut->PrintMessage("Out of Drawing Area, Re-click!");
		else
			break;
	}
	pOut->PrintMessage("New Triangle: Click at third corner");
	while (1) {
		pIn->GetPointClicked(P3.x, P3.y);
		if (CTriangle::InDrawingArea(P3) == 0)
			pOut->PrintMessage("Out of Drawing Area, Re-click!");
		else
			break;
	}
	TriGfxInfo.isFilled = UI.IsFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriAction::Execute() {
	ReadActionParameters();
	
	CTriangle* T = new CTriangle(P1,P2,P3,TriGfxInfo);

	pManager->AddFigure(T);
	T->SetID(pManager->GetFigureCount());

}
