#include "PlayColor.h"
#include <stdlib.h>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include <time.h>
#include <string>
#include <string.h>


PlayColor::PlayColor(ApplicationManager * pApp):PlayMode(pApp)
{

}

void PlayColor::ReadActionParameters()
{

}

void PlayColor::Execute()
{
	//Plays the game
	//Output *pOut = pManager->GetOutput();
	//Input *pIn = pManager->GetInput();
	if (CountFig == 0)
	{
		pOut->PrintMessage("There are no drawn figures");
		return;
	}
	//Generates random color and prints the initial score
	srand(time(NULL));
	int random = rand() % CountFig;
	GfxInfo Gfx = ListF[random]->GetGfxInfo();
	color Color = Gfx.FillClr;
	if (Color == BLACK) // run time error
	{
		pOut->PrintMessage("Choose all Black figures");
		Chosen = 0;
	}
	else if (Color == WHITE)
	{
		pOut->PrintMessage("Choose all White figures");
		Chosen = 1;
	}
	else if (Color == RED)
	{
		pOut->PrintMessage("Choose all Red figures");
		Chosen = 2;
	}
	else if (Color == BLUE)
	{
		pOut->PrintMessage("Choose all Blue figures");
		Chosen = 3;
	}
	else if (Color == GREEN)
	{
		pOut->PrintMessage("Choose all Green figures");
		Chosen = 4;
	}
	else
	{
		pOut->PrintMessage("Choose all non filled figures");
		Chosen = 5;
	}
	pIn->GetPointClicked(P1.x, P1.y);
	string C = to_string(Correct);
	string IC = to_string(Incorrect);
	pOut->PrintMessage("Score: Correct:" + C + " Incorrect:" + IC);
	for (int i = 0; i < CountFig; i++)
	{	//For loop to count number of chosen color
		if ((ListF[i]->GetGfxInfo().FillClr == BLACK) && Chosen == 0)
		{
			Count++;
		}
		if ((ListF[i]->GetGfxInfo().FillClr == WHITE) && Chosen == 1)
		{
			Count++;
		}
		if ((ListF[i]->GetGfxInfo().FillClr == RED) && Chosen == 2)
		{
			Count++;
		}
		if ((ListF[i]->GetGfxInfo().FillClr == BLUE) && Chosen == 3)
		{
			Count++;
		}
		if ((ListF[i]->GetGfxInfo().FillClr == GREEN) && Chosen == 4)
		{
			Count++;
		}
		if (((ListF[i]->GetGfxInfo().FillClr == LIGHTGOLDENRODYELLOW) && (Chosen == 5)))
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
				if ((Figure->GetGfxInfo().FillClr == BLACK) && (Chosen == 0))
				{
					UpdateScore(1);
					//delete the selected shape here
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((Figure->GetGfxInfo().FillClr == WHITE) && (Chosen == 1))
				{
					UpdateScore(1);
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((Figure->GetGfxInfo().FillClr == RED) && (Chosen == 2))
				{
					UpdateScore(1);
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((Figure->GetGfxInfo().FillClr == BLUE) && (Chosen == 3))
				{
					UpdateScore(1);
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((Figure->GetGfxInfo().FillClr == GREEN) && (Chosen == 4))
				{
					UpdateScore(1);
					DeleteFigure(&ListF[index]);
					Count--;
				}
				else if ((Figure->GetGfxInfo().FillClr == LIGHTGOLDENRODYELLOW) && (Chosen == 5))
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
			}
		}
		else if (P1.x >= 2 && P1.x <= 196 && P1.y >= 2 && P1.y <= 49)
		{
			if (P1.x >= 2 && P1.x <= 49)
			{
				break;
			}
			else if (P1.x > 49 && P1.x <= 98)
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

PlayColor::~PlayColor()
{
}
