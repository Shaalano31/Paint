#include "AddRhombusAction.h"
#include "AddLineAction.h"
#include "ApplicationManager.h"
#include "Figures/CRhombus.h"
#include "GUI/Output.h"
#include "GUI/Input.h"



AddRhombusAction::AddRhombusAction(ApplicationManager* pApp):Action(pApp)
{
}
void AddRhombusAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Rhombus: Click at first Point");
	while (1) //while loop to check if the point is inside the drawing area
	{
		pIn->GetPointClicked(P.x, P.y);
		Point TopCorner;
		TopCorner.x = P.x;
		TopCorner.y = P.y - 200;
		if ((CRhombus::InDrawingArea(P) == 0) && (TopCorner.y <= 50)) {
			pOut->PrintMessage("Out of Drawing Area, Re-click the point!");
		}
		else
			break;
	}
	RhombusGfxInfo.isFilled = UI.IsFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RhombusGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombusGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddRhombusAction::Execute() {
	ReadActionParameters();
	CRhombus* Rh = new CRhombus(P, RhombusGfxInfo);
	pManager->AddFigure(Rh);
	Rh->SetID(pManager->GetFigureCount());
}

