
#include "Snake.h"
#include "Player.h"
#include"Grid.h"

Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if(startCellPos.HCell() != endCellPos.HCell() ||  startCellPos.GetCellNum() < endCellPos.GetCellNum())
		return;

	this->endCellPos = endCellPos;
	
	///TODO: Do the needed validation
	
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position,endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	CellPosition c2=this->GetEndPosition();

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer,c2);
	pGrid->UpdateInterface();
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}


bool Snake::IsOverlapping(GameObject * newObj)const
{

	Snake* tst=dynamic_cast<Snake*>(newObj);
	if (!tst)
		return 0;
	
	if (this->GetPosition().HCell() != tst->GetPosition().HCell())
		return 0;

	for (int i = 0; i < 10; i++)
	{	
		for (int j = tst->GetEndPosition().VCell(); j > tst->GetPosition().VCell(); j--)
		{
			for (int k = this->GetEndPosition().VCell(); k > GetPosition().VCell(); k--)
			{
				if (k==j)
					return 1;
			}  // the cell already contains a game object
		}
		}
	return 0;
}




