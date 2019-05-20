#include "AddSelectAction.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddSelectAction::AddSelectAction(ApplicationManager* pApp):Action(pApp)
{
}
void AddSelectAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select A Figure ");
	while (true) {
		pIn->GetPointClicked(P.x, P.y);
		if (P.x >= 2 && P.x <= 1250 && P.y >= 2 && P.y <= 49) 
		{
			pOut->PrintMessage("Outside of Drawing Area, Re-Click!");
			continue;
		}
		if (P.x >= 245 && P.x <= 294 && P.y >=2  && P.y <= 49) 
		{
			UnSelect();
			pOut->PrintMessage("Unselecting");
			break;
		}
		CFigure* fptr = pManager->GetFigure(P);
		if (pManager->GetFigure(P)) {
			if (fptr->IsSelected())
			{									//if already a selected figure, unselect it
				UnSelect();
				pOut->PrintMessage("Unselecting");
				break;
			}
			else if (!fptr->IsSelected())
			{
				UnSelect();						//so no multiple selects occur
				pManager->GetFigure(P)->SetSelected(true);
				pManager->GetFigure(P)->PrintInfo(pOut);
				break;
			}
		}
		else {
			UnSelect();
			pOut->PrintMessage("No Figure is selected");
			break;
		}

	}
}
	void AddSelectAction::Execute() {
		ReadActionParameters();
}
void AddSelectAction::UnSelect() {
	pManager->UnSelectFigures();
}

/*void AddSelectAction::SelectionCheck(CFigure *p) {
	if (p->IsSelected) 
		p->SetSelected(false);
	else
		p->SetSelected(true);	
}*/