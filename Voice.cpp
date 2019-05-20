#include "Voice.h"
#include "ApplicationManager.h"

bool Voice::Clicked = 0;
Voice::Voice(ApplicationManager *pApp):Action(pApp)
{
}

bool Voice::getClicked()
{
	return Clicked;
}

void Voice::ReadActionParameters()
{
	/*Input *pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
	if (!(CFigure::InDrawingArea(P)))
	{
		if (P.x > 2 && P.x <= 53)
			Audio = 0;
		else if (P.x > 53 && P.x <= 106)
			Audio = 1;
		else if (P.x > 53 && P.x <= 159)
			Audio = 2;
		else if (P.x > 159 && P.x <= 212)
			Audio = 3;
		else if (P.x > 212 && P.x <= 265)
			Audio = 4;
	}*/
}

void Voice::Execute()
{
	Output *pOut = pManager->GetOutput();
	if (Clicked == false)
	{
		Clicked = true;
		pOut->PrintMessage("Voice is activated");
	}
	else if (Clicked == true)
	{
		Clicked = false;
		pOut->PrintMessage("Voice is deactivated");
	}
}

Voice::~Voice()
{
}
