#include "SendToB.h"
#include "ApplicationManager.h"


SendToB::SendToB(ApplicationManager *pApp) :Action(pApp)
{
}


void SendToB::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
}

void SendToB::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* A = pManager->GetSelectedFigure();
	if (pManager->GetSelectedFigure()->IsSelected()) {
		pOut->PrintMessage("Bringing Selected Figure to Back.");
		pManager->SendTo(2);
		pManager->UnSelectFigures();
		
	}
	else {
		pOut->PrintMessage("No Selected Figures Found.");
	}
}