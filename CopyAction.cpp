#include "CopyAction.h"
#include"ApplicationManager.h"

CopyAction::CopyAction(ApplicationManager *pApp):Action(pApp)
{
}
void CopyAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSelectedFigure())
		pOut->PrintMessage("The selected figure is copy, Please paste anywhere");
	else
		pOut->PrintMessage("No Figure Is Selected.");

}
void CopyAction::Execute()
{
	ReadActionParameters();
	pManager->SetClipboard(pManager->GetColoredSelectedFigure());
	pManager->SetisitCut(false);
}