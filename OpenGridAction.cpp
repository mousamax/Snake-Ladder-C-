#include "OpenGridAction.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp),SaveGridAction(pApp)
{
	
}

void OpenGridAction::ReadActionParameters()
{
	save.open("Grid.txt", ios::app);
	pOpen.open("Grid.txt");
	Grid* pGrid = Action::pManager->GetGrid();
	SaveGridAction::ReadActionParameters();
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = Action::pManager->GetGrid();
	pOpen >> NofLadders;
	for (int i = 0; i < NofLadders; i++)
	{
		Ladder* pLadder;
		CellPosition start1;
		CellPosition end1;
		pLadder = new Ladder(start1, end1);
		pLadder->Load(pOpen, ladder,start1,end1);
		delete pLadder;
		pLadder = new Ladder(start1, end1);
		pGrid->AddObjectToCell(pLadder);
		pGrid->GetOutput()->DrawLadder(start1, end1);
	}
	pOpen >> NofSnakes;
	for (int i = 0; i < NofSnakes; i++)
	{
		Snake* pSnake;
		CellPosition start1;
		CellPosition end1;
		pSnake = new Snake(start1, end1);
		pSnake->Load(pOpen, snake, start1, end1);
		delete pSnake;
		pSnake = new Snake(start1, end1);
		pGrid->AddObjectToCell(pSnake);
		pGrid->GetOutput()->DrawSnake(start1, end1);
	}
	pOpen >> NofCards;
	for (int i = 0; i < NofCards; i++)
	{
		int x;
		Card* pCard;
		CellPosition start1;
		CellPosition end1;
		pCard = new Card(start1);
		pCard->Load(pOpen, card, start1,end1);
		x = pCard->GetCardNumber();
		pCard = new Card(start1);
		pCard->SetCardNumber(x);
		pGrid->AddObjectToCell(pCard);
		
		pGrid->GetOutput()->DrawCell(start1,pCard->GetCardNumber());
	}

}
