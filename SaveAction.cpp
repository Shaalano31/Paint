#include "SaveAction.h"
#include "ApplicationManager.h"
#include <fstream>
#include <iostream>




SaveAction::SaveAction(ApplicationManager *pApp)
	:Action(pApp)
{
}
void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter File Name:");
	filename=pIn->GetSrting(pOut);
	pOut->PrintMessage("File Saved");
}
void SaveAction::Execute()
{
	ReadActionParameters();
	OutFile.open(filename.c_str(), ios::out);
	color dc=UI.DrawColor;
	color df = UI.FillColor;
	if (dc == BLACK)
		OutFile << "BLACK" << '\t';
	else if (dc == RED)
		OutFile << "RED" << '\t';
	else if (dc == WHITE)
		OutFile << "WHITE" << '\t';
	else if (dc == BLUE)
		OutFile << "BLUE" << '\t';
	else if (dc == GREEN)
		OutFile << "GREEN" << '\t';


		if (df == RED)
		OutFile << "RED" << '\n';
	else if (df == WHITE)
		OutFile << "WHITE" << '\n';
	else if (df == BLUE)
		OutFile << "BLUE" << '\n';
	else if (df == GREEN)
		OutFile << "GREEN" << '\n';
	else OutFile << "NOT_FILLED" << '\n';
	
		OutFile << pManager->GetFigureCount() << '\n';
			pManager->SaveAll(OutFile);
	OutFile.close();
}

SaveAction::~SaveAction()
{
}
