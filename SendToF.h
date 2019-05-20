#pragma once
#include "Actions/Action.h"
class SendToF :
	public Action
{
public:
	SendToF(ApplicationManager *);
	void ReadActionParameters();
	void Execute();
};