#include<iostream>
#include"DeleteAction.h"
#include"ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager*pmanager) :Action(pmanager) 
{

}
void DeleteAction::Execute() 
{
	Input*pln = pManager->GetInput();
	Output*pOut = pManager->GetOutput();
	pOut->PrintMessage("Delete Action Pressed.");
	//pln->GetPointClicked(P1.x, P1.y);
	
	//CFigure*figure= pManager->GetFigure(P1);
	//if (pManager->GetFigure(P1) != NULL) {
		//pOut->ClearDrawArea();
		pManager->DeleteSelectedFigures();
		
		
		
		
	//}
}
	/*int c = pManager->DeleteSelectedFigures();
	if (c != pManager->GetFigureCount() - 1){
		for (int i = c;i < pManager->GetFigureCount()-1;i++) {
			{
				pManager->Getfiglist()[i] = pManager->Getfiglist()[i + 1];
			}
		}
		pManager->Getfiglist()[pManager->GetFigureCount()] = NULL;
	}
	pManager->UpdateInterface();
	pOut->ClearDrawArea();*/


void DeleteAction::ReadActionParameters() {
	int x = 0;
}