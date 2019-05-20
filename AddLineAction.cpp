#include "AddLineAction.h"
#include "ApplicationManager.h"
#include "Figures/CLine.h"
#include "GUI/Output.h"
#include "GUI/Input.h"


AddLineAction::AddLineAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddLineAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Line: Click at first Point");
	while (1) {
		pIn->GetPointClicked(P1.x, P1.y);
		if (CLine::InDrawingArea(P1) == 0)
			pOut->PrintMessage("Out of Drawing Area, Re-click!");
		else
			break;
	}
		pOut->PrintMessage("New Line: Click at second Point");
	while (1) {
		pIn->GetPointClicked(P2.x, P2.y);
		if (CLine::InDrawingArea(P2) == 0)
			pOut->PrintMessage("Out of Drawing Area, Re-click!");
		else
			break;
	}

	LineGfxInfo.isFilled = UI.IsFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
void AddLineAction::Execute() {
	ReadActionParameters();

	CLine* L = new CLine(P1, P2, LineGfxInfo);
	pManager->AddFigure(L);
	L->SetID(pManager->GetFigureCount());
}



