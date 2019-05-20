#pragma once
#include "Actions/Action.h"
class Voice : public Action
{
private:
	/*int Audio;
	Point P;*/
	static bool Clicked;
public:
	Voice(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	static bool getClicked();
	~Voice();
};

