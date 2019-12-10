#include "SaveGridAction.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp):Action(pApp),save("Grid.txt")
{
	
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	NofLadders = pGrid->numofladders();
	NofSnakes = pGrid->numofSnakes();
	NofCards = pGrid->numofCards();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	save << NofLadders << endl;
	pGrid->SaveAll(save, ladder);
	save << NofSnakes << endl;
	pGrid->SaveAll(save, snake);
	save << NofCards << endl;
	pGrid->SaveAll(save, card);
	save.close();
		
}
