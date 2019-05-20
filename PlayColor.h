#pragma once
#include "PlayMode.h"

class PlayColor : public PlayMode
{
public:
	PlayColor(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PlayColor();
};

