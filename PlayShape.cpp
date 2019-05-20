#include "PlayShape.h"
#include <stdlib.h>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "PlayColor.h"
#include <time.h>
#include <string>
#include <string.h>

PlayShape::PlayShape(ApplicationManager * pApp):PlayMode(pApp)
{

}

void PlayShape::ReadActionParameters()
{	
}

void PlayShape::Execute()
{	//Plays the game
	//Output *pOut = pManager->GetOutput();
	//Input *pIn = pManager->GetInput();

	if (CountFig == 0)
	{
		pOut->PrintMessage("There are no drawn figures");
		return;
	}
	//Generates random shape and prints the initial score
	srand(time(NULL));
	int random = rand() % CountFig;
	if (CRectangle* F = dynamic_cast<CRectangle*>(ListF[random]))
	{
		pOut->PrintMessage("Choose all Rectangles");
		Chosen = 0;
	}
	else if (CLine* F = dynamic_cast<CLine*>(ListF[random]))
	{
		pOut->PrintMessage("Choose all Lines");
		Chosen = 1;
	}
	else if (CTriangle* F = dynamic_cast<CTriangle*>(ListF[random]))
	{
		pOut->PrintMessage("Choose all Triangle");
		Chosen = 2;
	}
	else if (CRhombus* F = dynamic_cast<CRhombus*>(ListF[random]))
	{
		pOut->PrintMessage("Choose all Rhombus");
		Chosen = 3;
	}
	else if (CEllipse* F = dynamic_cast<CEllipse*>(ListF[random]))
	{
		pOut->PrintMessage("Choose all Ellipse");
		Chosen = 4;
	}
	pIn->GetPointClicked(P1.x, P1.y);
	string C = to_string(Correct);
	string IC = to_string(Incorrect);
	pOut->PrintMessage("Score: Correct:" + C + " Incorrect:" + IC);
	for (int i = 0; i < CountFig; i++)
	{	// For loop to count number of chosen figure
		CRectangle *R = dynamic_cast<CRectangle *>(ListF[i]);
		CLine *L = dynamic_cast<CLine *>(ListF[i]);
		CTriangle *T = dynamic_cast<CTriangle *>(ListF[i]);
		CRhombus *RH = dynamic_cast<CRhombus *>(ListF[i]);
		CEllipse *E = dynamic_cast<CEllipse *>(ListF[i]);
		if ((R!=NULL) && (Chosen == 0))
		{
			Count++;
		}
		else if ((L != NULL) && (Chosen == 1))
		{
			Count++;
		}
		else if ((T != NULL) && (Chosen == 2))
		{
			Count++;
		}
		else if ((RH != NULL) && (Chosen == 3))
		{
			Count++;
		}
		else if((E != NULL) && (Chosen == 4))
		{
			Count++;
		}

	}
	do
	{
		pIn->GetPointClicked(P1.x, P1.y);
		if (CFigure::InDrawingArea(P1) == 1)
		{
			if (!(pManager->GetFigure(P1)))
			{
				pOut->PrintMessage("Choose an object");
			}
			else
			{
				bool check;
				CFigure *Figure = pManager->GetFigure(P1);
				int index;
				for (int i = 0; i < CountFig; i++)
				{
					if (Figure == ListF[i])
					{
						index = i;
						break;
					}
				}
				CRectangle *R = dynamic_cast<CRectangle *>(Figure);
				CLine *L = dynamic_cast<CLine *>(Figure);
				CTriangle *T = dynamic_cast<CTriangle *>(Figure);
				CRhombus *RH = dynamic_cast<CRhombus *>(Figure);
				CEllipse *E = dynamic_cast<CEllipse *>(Figure);
				if ((R != NULL) && (Chosen == 0))
				{
					UpdateScore(1);
					//delete the selected shape here
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((L != NULL) && (Chosen == 1))
				{
					UpdateScore(1);
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((T != NULL) && (Chosen == 2))
				{
					UpdateScore(1);
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((RH != NULL) && (Chosen == 3))
				{
					UpdateScore(1);
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((E != NULL) && (Chosen == 4))
				{
					UpdateScore(1);
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else
				{
					UpdateScore(0);
					DeleteFigure(&ListF[index]);
				}
				//check if array has anymore figures from the chosen one
			}
		}
		else if(P1.x >= 2 && P1.x <= 196 && P1.y >= 2 && P1.y <= 49)
		{
			if (P1.x >= 2 && P1.x <= 49)
			{
				Correct = 0;
				Incorrect = 0;
				CountFig = pManager->GetFigureCount();
				Chosen = 0;
				ListF = new CFigure*[CountFig];
				pManager->CopyFigList(ListF);
				pManager->UpdateInterface();
				Execute();
				break;
			}
			else if (P1.x > 49 && P1.x <= 98)
			{
				break;
			}
			else if (P1.x > 98 && P1.x <= 147)
			{
				pOut->CreateDrawToolBar();
				pManager->UpdateInterface();
				break;
			}
			else if (P1.x > 147 && P1.x <= 196)
			{
				pOut->PrintMessage("Program should exit");
				break;
			}
		}
		else
		{
			pOut->PrintMessage("Out of drawing area, Re-Click");
			continue;
		}
	} while (Count > 0);
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("Game Over, Press anywhere to continue");
	pIn->GetPointClicked(P1.x, P1.y);
}


PlayShape::~PlayShape()
{
	delete *ListF;
}