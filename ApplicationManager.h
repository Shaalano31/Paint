#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
//Integrated Files
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <fstream>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	color CuttingColor; //Color of original shape
	int PreviousSelectedIndex;
	bool isitCut;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(Point) const; //Search for a figure given a point inside the figure
	CFigure *GetSelectedFigure();
	void SendTo(int state);
	CFigure *GetColoredSelectedFigure();
	int GetFigureCount();
	void ChangeFillColor(color);
	void SaveRec(ofstream &outfile);
	void SaveRhom(ofstream &outfile);
	void SaveTri(ofstream &outfile);
	void SaveLine(ofstream &outfile);
	void SaveEll(ofstream &outfile);
	void SaveAll( ofstream &OutFile);
	void DeleteFigures();
	void ChangeDrawColor(color);
	void UnSelectFigures();
	void DeleteSelectedFigures();
	int ApplicationManager::CopyFigList(CFigure **List);
	void SetClipboard(CFigure*);
	CFigure* getClipboard();
	void SetisitCut(bool x);
	bool GetisitCut();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	//CFigure**Getfiglist();
	//int getfigcount() const;
};

#endif