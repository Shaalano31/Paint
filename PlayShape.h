#pragma once
#include"Actions/Action.h"
#include "PlayMode.h"

class PlayShape : public PlayMode
{	//BY SHAPE

public:
	PlayShape(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PlayShape();
};
