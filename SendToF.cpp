#include "SendToF.h"
#include "ApplicationManager.h"


SendToF::SendToF(ApplicationManager *pApp):Action(pApp)
{
}


void SendToF::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
}

void SendToF::Execute() {
	Output* pOut= pManager->GetOutput();
	CFigure* A = pManager->GetSelectedFigure();
	if (pManager->GetSelectedFigure()->IsSelected()) {
		pOut->PrintMessage("Bringing Selected Figure to Front.");
		pManager->SendTo(1);
		pManager->UnSelectFigures();
	}
	else {
		pOut->PrintMessage("No Selected Figures Found.");
	}
}