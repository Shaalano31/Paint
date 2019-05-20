#include "ChangeDrawClrAction.h"
#include "ApplicationManager.h"



ChangeDrawClrAction::ChangeDrawClrAction(ApplicationManager* pApp) :Action(pApp)
{
	
}

void ChangeDrawClrAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Change Draw Border Color. Pick a Color");
	ActionType ActType = pIn->GetUserAction();
	switch (ActType)
	{
	case COL_BLACK:
		Fillcolr = BLACK;
		pOut->PrintMessage("You Picked Black.");
		break;
	case COL_WHITE:
		Fillcolr = WHITE;
		pOut->PrintMessage("You Picked White.");
		break;
	case COL_RED:
		Fillcolr = RED;
		pOut->PrintMessage("You Picked Red.");
		break;
	case COL_GREEN:
		Fillcolr = GREEN;
		pOut->PrintMessage("You Picked Green.");
		break;
	case COL_BLUE:
		Fillcolr = BLUE;
		pOut->PrintMessage("You Picked Blue.");
		break;
	}
	
}
void ChangeDrawClrAction::Execute() {
	ReadActionParameters();
	pManager->ChangeDrawColor(Fillcolr);
	pManager->GetSelectedFigure()->ChngDrawClr(Fillcolr);
}