#include "SaveByType.h"



SaveByType::SaveByType(ApplicationManager *pApp)
	:Action(pApp)
{
	
}
void SaveByType::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter File Name:");
	FileName = pIn->GetSrting(pOut);
	pOut->PrintMessage("Pick a Figure");
	A = pIn->GetUserAction();
}
void SaveByType::Execute()
{
	ReadActionParameters();
	outfile.open(FileName.c_str(), ios::out);
	color dc = UI.DrawColor;
	color df = UI.FillColor;
	if (dc == BLACK)
		outfile << "BLACK" << '\t';
	else if (dc == RED)
		outfile << "RED" << '\t';
	else if (dc == WHITE)
		outfile << "WHITE" << '\t';
	else if (dc == BLUE)
		outfile << "BLUE" << '\t';
	else if (dc == GREEN)
		outfile << "GREEN" << '\t';


	if (df == RED)
		outfile << "RED" << '\n';
	else if (df == WHITE)
		outfile << "WHITE" << '\n';
	else if (df == BLUE)
		outfile << "BLUE" << '\n';
	else if (df == GREEN)
		outfile << "GREEN" << '\n';
	bool check = 0;
	outfile << pManager->GetFigureCount() << '\n';
	do {
		
		switch (A)
		{
		case DRAW_LINE:

			pManager->SaveLine(outfile);
			check = 1;
			break;
		case DRAW_ELLIPSE:
			pManager->SaveEll(outfile);
			check = 1;
			break;
		case DRAW_RECT:
			pManager->SaveRec(outfile);
			check = 1;
			break;
		case DRAW_RHOMBUS:
			pManager->SaveRhom(outfile);
			check = 1;
			break;
		case DRAW_TRI:
			pManager->SaveTri(outfile);
			check = 1;
			break;
		case STATUS:
		default:check = 0;
			Output* pOut = pManager->GetOutput();
			Input *pIn= pManager->GetInput();
			pOut->PrintMessage("Error: Choose only from Figure Icons");
				A = pIn->GetUserAction();
				continue;
		}
	} while (check == 0);
	outfile.close();
}


SaveByType::~SaveByType()
{
}
