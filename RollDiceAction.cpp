#include "RollDiceAction.h"
#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	
	
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if(pGrid->GetEndGame())
	{ }
	else
	{

	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

	// 3- Get the "current" player from pGrid
	Player * pPlayer = pGrid->GetCurrentPlayer();
	// 4- Move the currentPlayer using function Move of class player
	pPlayer->Move(pGrid, diceNumber);

	Ladder* l = pPlayer->GetCell()->HasLadder();
	Snake* s = pPlayer->GetCell()->HasSnake();
	Card* c = pPlayer->GetCell()->HasCard();
	if (l != NULL)
	{
		pOut->PrintMessage("You have reached a ladder. Click to continue");
		pIn->GetCellClicked();
		l->Apply(pGrid, pPlayer);
	}
	else if(s != NULL)
	{
		pOut->PrintMessage("You have reached a Sanke. Click to continue");
		pIn->GetCellClicked();
		s->Apply(pGrid, pPlayer);
	}
	else if(c != NULL)
	{
		pOut->PrintMessage("You have reached a CARD. Click to continue");
		pIn->GetCellClicked();
		c->Apply(pGrid, pPlayer);
	}
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

RollDiceAction::~RollDiceAction()
{
}
