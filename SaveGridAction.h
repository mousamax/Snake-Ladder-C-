#pragma once
#include "Grid.h"
#include "fstream"
#include "Action.h"

class SaveGridAction:public Action
{
	ofstream save;
	int NofLadders;
	int NofSnakes;
	int NofCards;
public:
	SaveGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

