#include "PlayMode.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"


PlayMode::PlayMode(ApplicationManager * pApp):Action(pApp)
{
	Correct = 0;
	Incorrect = 0;
	CountFig = pManager->GetFigureCount();
	Chosen = 0;
	Count = 0;
	ListF = new CFigure*[CountFig];
	pManager->CopyFigList(ListF);
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void PlayMode::UpdateScore(bool Pick)
{
	Output* pOut = pManager->GetOutput();
	switch (Pick)
	{
	case 1:
		Correct++;
		break;
	case 0:
		Incorrect++;
		break;
	}
	string C = to_string(Correct);
	string IC = to_string(Incorrect);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Score: Correct:" + C + " Incorrect:" + IC);
}

void PlayMode::DeleteFigure(CFigure **Figure)
{
	Output *pOut = pManager->GetOutput();
	CFigure *Temp = *Figure;
	*Figure = ListF[CountFig - 1];
	ListF[CountFig - 1] = Temp;
	CountFig--;
	pOut->ClearDrawArea();
	for (int i = 0; i < CountFig; i++)
		ListF[i]->Draw(pOut);
}
PlayMode::~PlayMode()
{
	for (int i = 0; i < CountFig; i++)
		delete ListF[i];
	delete pIn;
	delete pOut;
}
