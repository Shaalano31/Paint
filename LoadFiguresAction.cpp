#include "LoadFiguresAction.h"
#include "ApplicationManager.h"
#include <string>


LoadFiguresAction::LoadFiguresAction(ApplicationManager *pApp)
	:Action(pApp)
{
}
void LoadFiguresAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter File Name:");
	FileName = pIn->GetSrting(pOut);
}
void LoadFiguresAction::Execute()
{
	Output *pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->DeleteFigures();
	ReadActionParameters();
	InFile.open(FileName.c_str(), ios::in);
	
	if (InFile.is_open())
	{
		string Dcolor, Fcolor, FigureName;
		//color dc, fc;
		InFile >> Dcolor >> Fcolor;
		if (Dcolor == "BLACK")
			UI.DrawColor == BLACK;
		else if (Dcolor == "WHITE")
			UI.DrawColor == WHITE;
		else if (Dcolor == "RED")
			UI.DrawColor == RED;
		else if (Dcolor == "GREEN")
			UI.DrawColor == GREEN;
		else if (Dcolor == "BLUE")
			UI.DrawColor == BLUE;

		if (Fcolor == "BLACK")
			UI.FillColor == BLACK;
		else if (Fcolor == "WHITE")
			UI.FillColor == WHITE;
		else if (Fcolor == "RED")
			UI.FillColor == RED;
		else if (Fcolor == "GREEN")
			UI.FillColor == GREEN;
		else if (Fcolor == "BLUE")
			UI.FillColor == BLUE;
		else UI.IsFilled = false;


		CLine *L = NULL;
		CRectangle *R = NULL;
		CTriangle *T = NULL;
		CRhombus *Rh = NULL;
		CEllipse *E = NULL;
		string FigCount;
		InFile >> FigCount;
		int Count = stoi(FigCount);
		for(int i=0; i<Count; i++)
		{
			
			Point P1, P2,P3; GfxInfo GF;
			GF.FillClr = BLUE;
			P1.x = 600; P1.y = 600; P2.x = 200; P2.y = 300; P3.x = 555; P3.y = 700;
			
			InFile >> FigureName;
			if (FigureName=="LINE")
			{
				L = new CLine(P1, P2,GF);
				L->Load(InFile);
				L->Draw(pOut);
				pManager->AddFigure(L);
			}
			else if (FigureName == "RECT")
			{
				R = new CRectangle(P1, P2, GF);
				R->Load(InFile);
				R->Draw(pOut);
				pManager->AddFigure(R);
			}
			else if (FigureName == "ELLIPSE")
			{
				E = new CEllipse(P1, GF);
				E->Load(InFile);
				E->Draw(pOut);
				pManager->AddFigure(E);
			}
			else if (FigureName == "RHOMBUS")
			{
				Rh = new CRhombus(P1, GF);
				Rh->Load(InFile);
				Rh->Draw(pOut);
				pManager->AddFigure(Rh);
			}
			else if (FigureName == "TRIANG")
			{
				T = new CTriangle(P1,P2,P3,GF);
				T->Load(InFile);
				T->Draw(pOut);
				pManager->AddFigure(T);
			}
		}
		InFile.close();
	}
	else { pOut->PrintMessage("Error! File was not found"); }
}

LoadFiguresAction::~LoadFiguresAction()
{
}
