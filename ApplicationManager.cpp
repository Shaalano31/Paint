#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "AddSelectAction.h"
#include "AddLineAction.h"
#include "AddRhombusAction.h"
#include "AddEllipseAction.h"
#include "ChangeFillClrAction.h"
#include "SaveAction.h"
#include "SaveByType.h"
#include "LoadFiguresAction.h"
#include <fstream>
#include "ChangeDrawClrAction.h"
#include "DeleteAction.h"
#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "PlayShape.h"
#include "PlayMode.h"
#include "PlayColor.h"
#include "Voice.h"
#include "SendToF.h"
#include "SendToB.h"

//FINAL FINAL
//Constructor
ApplicationManager::ApplicationManager()
{
	Clipboard = NULL;
	CuttingColor = NULL;
	PreviousSelectedIndex = 0;
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}

////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			if (Voice::getClicked() == 1)
			{
				PlaySound(TEXT("Voices/Rect.wav"), NULL, SND_SYNC);
			}
			pAct = new AddRectAction(this);
			break;
		case DRAW_LINE:
			if (Voice::getClicked() == 1)
				PlaySound(TEXT("Voices/Line.wav"), NULL, SND_SYNC);
			pAct = new AddLineAction(this);
			break;
		case DRAW_RHOMBUS:
			if (Voice::getClicked() == 1)
				PlaySound(TEXT("Voices/Rhombus.wav"), NULL, SND_SYNC);
			pAct = new AddRhombusAction(this);
			break;
		case DRAW_ELLIPSE:
			if (Voice::getClicked() == 1)
				PlaySound(TEXT("Voices/Ellipse.wav"), NULL, SND_SYNC);
			pAct = new AddEllipseAction(this);
			break;
		case DRAW_TRI:
			if (Voice::getClicked() == 1)
				PlaySound(TEXT("Voices/Triangle.wav"), NULL, SND_SYNC);
			pAct = new AddTriAction(this);
			break;
		case SELECT_FIGURE:
			pAct = new AddSelectAction(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawClrAction(this);
			break;
		case CHNG_FILL_CLR:	
			pAct = new ChangeFillClrAction(this);
			break;
		case TO_PLAY:
			UpdateInterface();
			pOut->ClearStatusBar();
			pOut->CreatePlayToolBar();
			break;
		case COLOR:
			UpdateInterface();
			pAct = new PlayColor(this);
			break;
		case SHAPE:
			UpdateInterface();
			pAct = new PlayShape(this);
			break;
		case TO_DRAW:
			pOut->ClearStatusBar();
			pOut->CreateDrawToolBar();
			break;
		case COPY:
			pAct = new CopyAction(this);
			break;
		case CUT:
			pAct = new CutAction(this);
			break;
		case DEL:
			pAct = new DeleteAction(this);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case SAVE_BY_TYPE:
			pAct = new SaveByType(this);
			break;
		case LOAD:
			pAct = new LoadFiguresAction(this);
			break;
		case VOICE:
			pAct = new Voice(this);
			break;
		case FRONT:
			pAct = new SendToF(this);
			break;
		case BACK:
			pAct = new SendToB(this);
			break;
		case EXIT:
			pOut->PrintMessage("Program is exiting now");
			///create ExitAction here
			break;	
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
int ApplicationManager::GetFigureCount()
{ 
	return FigCount; 
}
void ApplicationManager::ChangeFillColor(color c) {
	UI.FillColor = c;
	UI.IsFilled = true;
}
void ApplicationManager::ChangeDrawColor(color c) {
	UI.DrawColor = c;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::UnSelectFigures() {
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
			FigList[i]->SetSelected(false);
	}
}
CFigure *ApplicationManager::GetFigure(Point P) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	CFigure* TopFig =nullptr;
	for (int i = 0; i < FigCount; i++)
	{	
		if (FigList[i]->SelectFigure(P))
			TopFig = FigList[i];
	}

	if (TopFig == nullptr)
		return NULL;
	else
		return TopFig;
}

void ApplicationManager::SendTo(int state) {
	//state = 1 to bring to front, 2 to back
	CFigure* F;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigCount > 1) {
			if (FigList[i]->IsSelected()) {
				if (state == 1) {
					F = FigList[i];
					FigList[i] = FigList[FigCount - 1];
					FigList[FigCount - 1] = F;
					/*F = nullptr;
					delete F;*/
				}
				else if (state == 2) {
					F = FigList[i];
					FigList[i] = FigList[0];
					FigList[0] = F;
					/*F = nullptr;
					delete F;*/
				}
			}
		}
		else
			pOut->PrintMessage("No More than 1 Figure.");
	}
	UpdateInterface();
}
int ApplicationManager::CopyFigList(CFigure **List)
{
	for (int i = 0; i < FigCount; i++)
	{
		List[i] = FigList[i];
	}
	return FigCount;
}

CFigure *ApplicationManager::GetSelectedFigure() {
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
			return FigList[i];
	}
}
CFigure *ApplicationManager::GetColoredSelectedFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			if (CuttingColor == NULL) {
				CuttingColor = FigList[i]->GetGfxInfo().FillClr; 
				PreviousSelectedIndex = i;
			}
			else{
				FigList[PreviousSelectedIndex]->ChngFillClr(CuttingColor);
				CuttingColor = FigList[i]->GetGfxInfo().FillClr;
				PreviousSelectedIndex = i;
			}

			return FigList[i];
		}
			
	}
}
void ApplicationManager::SetClipboard(CFigure* C)
{
	if (Clipboard != NULL)
	{
		Clipboard->ChngFillClr(CuttingColor);
	}
	Clipboard = NULL;
	Clipboard = C;
}

CFigure* ApplicationManager::getClipboard()
{
	return Clipboard;
}
void ApplicationManager::SetisitCut(bool x)
{
	isitCut = x;
}
bool ApplicationManager::GetisitCut()
{
	return isitCut;
}

void ApplicationManager::SaveAll(ofstream &OutFile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}
void ApplicationManager::SaveLine(ofstream &outfile)
{
	pOut->PrintMessage("You picked Line");
	for (int i = 0; i < FigCount; i++)
	{
		if (CLine*L = dynamic_cast<CLine*>(FigList[i]))
			L->Save(outfile);
	}
}
void ApplicationManager::SaveEll(ofstream &outfile)
{
	pOut->PrintMessage("You picked Ellipse");
	for (int i = 0; i < FigCount; i++)
	{
		if (CEllipse*E = dynamic_cast<CEllipse*>(FigList[i]))
			E->Save(outfile);
	}
}
void ApplicationManager::SaveRec(ofstream &outfile)
{
	pOut->PrintMessage("You picked Rectangle");
	for (int i = 0; i < FigCount; i++)
	{
		if (CRectangle*R = dynamic_cast<CRectangle*>(FigList[i]))
			R->Save(outfile);
	}
}
void ApplicationManager::SaveRhom(ofstream &outfile)
{
	pOut->PrintMessage("You picked Rhombus");
	for (int i = 0; i < FigCount; i++)
	{
		if (CRhombus*RH = dynamic_cast<CRhombus*>(FigList[i]))
			RH->Save(outfile);
	}
}
void ApplicationManager::SaveTri(ofstream &outfile)
{
	pOut->PrintMessage("You picked Triangle");
	for (int i = 0; i < FigCount; i++)
	{
		if (CTriangle*T = dynamic_cast<CTriangle*>(FigList[i]))
			T->Save(outfile);
	}
}
void ApplicationManager::DeleteFigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete[] FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	SelectedFig = NULL;
	Clipboard = NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for (int i = 0; i < FigCount; i++)
		if (pOut == NULL)
			return;
		else
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
void ApplicationManager::DeleteSelectedFigures() 
{
	int count = 0;
	bool found = false;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected()) 
		{
			FigList[i]->SetSelected(false);
			count = i;
			found = true;
			break;


		}
	}
	if (found) 
	{
		for (int j = count; j < FigCount - 1; j++)
		{
			FigList[j] = FigList[j + 1];
		}
		FigList[FigCount] = NULL;
		FigCount--;
		
		pOut->ClearDrawArea();
		UpdateInterface();
		pOut->ClearStatusBar();
		pOut->CreateDrawToolBar();
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
/*CFigure** ApplicationManager::Getfiglist() {
	return this->FigList;
}
int ApplicationManager::getfigcount() const {
	return FigCount;
}/**/
