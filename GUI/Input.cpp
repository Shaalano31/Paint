#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_LINE: return DRAW_LINE;
			case ITM_RECT: return DRAW_RECT;
			case ITM_TRI: return DRAW_TRI;
			case ITM_RHO: return DRAW_RHOMBUS;
			case ITM_ELL: return DRAW_ELLIPSE;
			case ITM_SELECT: return SELECT_FIGURE;
			case ITM_CHANGEFILL_COLOR: return CHNG_FILL_CLR;
			case ITM_CHANGEDRAW_COLOR: return CHNG_DRAW_CLR;
			case ITM_BLACK:return COL_BLACK;
			case ITM_WHITE: return COL_WHITE;
			case ITM_RED:return COL_RED;
			case ITM_GREEN:return COL_GREEN;
			case ITM_BLUE:return COL_BLUE;
			case ITM_DELETE: return DEL;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_GRAPH: return SAVE;
			case ITM_TYPE: return SAVE_BY_TYPE;
			case ITM_LOADGRAPH: return LOAD;
			case ITM_SWITCH: return TO_PLAY;
			case ITM_VOICE: return VOICE;
			case ITM_FRONT: return FRONT;
			case ITM_BACK: return BACK;
			case ITM_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	
		//GUI is in PLAY mode
	{
		UI.InterfaceMode = MODE_PLAY;
		{	//[1] If user clicks on the Toolbar
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_PLAY_TYPE: return SHAPE;
				case ITM_PLAY_COLOR: return COLOR;
				case ITM_DRAWSWITCH:return TO_DRAW;
				case ITM_PLAYEXIT: return EXIT;
				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return PLAYING_AREA;	//just for now. This should be updated 
			}

			//[3] User clicks on the status bar
			return STATUS;
			///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//just for now. This should be updated
		}
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
