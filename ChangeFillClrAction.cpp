#include "ChangeFillClrAction.h"
#include"ApplicationManager.h"



ChangeFillClrAction::ChangeFillClrAction(ApplicationManager* pApp):Action(pApp)
{
}


void ChangeFillClrAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Change Fill Color. Pick a Color");

	switch (pIn->GetUserAction())
	{
	case COL_BLACK:
		pOut->PrintMessage("You Picked Black.");
	Fillcolr = BLACK;
	
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
void ChangeFillClrAction::Execute() {
	ReadActionParameters();
	pManager->ChangeFillColor(Fillcolr);
	pManager->GetSelectedFigure()->ChngFillClr(Fillcolr);
}