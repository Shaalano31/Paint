#include "CutAction.h"
#include "ApplicationManager.h"
#include "PasteAction.h"
CutAction::CutAction(ApplicationManager *pApp):Action(pApp)
{}
void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSelectedFigure())
		pOut->PrintMessage("The selected figure is cut, Please paste anywhere");
	else
		pOut->PrintMessage("No Figure Is Selected.");
}
void CutAction::Execute()
{
	ReadActionParameters();
	pManager->SetClipboard(pManager->GetColoredSelectedFigure());
	pManager->GetSelectedFigure()->ChngDrawClr(GREY);
	pManager->GetSelectedFigure()->ChngFillClr(GREY);
	pManager->SetisitCut(true);
}
