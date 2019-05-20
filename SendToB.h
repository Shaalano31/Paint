#pragma once
#include "Actions/Action.h"
class SendToB :
	public Action
{
public:
	SendToB(ApplicationManager *);
	void ReadActionParameters();
	void Execute();
};

