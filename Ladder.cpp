
#include "Ladder.h"
#include "Player.h"
#include"Grid.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if(startCellPos.HCell() != endCellPos.HCell() ||  startCellPos.GetCellNum() > endCellPos.GetCellNum() )
		return;

	this->endCellPos = endCellPos;
	
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

bool Ladder::IsOverlapping(GameObject * newObj)const
{
	Ladder* tst=dynamic_cast<Ladder*>(newObj);
	if (!tst)
		return 0;
	
	if (this->GetPosition().HCell() != tst->GetPosition().HCell())
		return 0;

	for (int i = 0; i < 10; i++)
	{	
		for (int j = tst->GetEndPosition().VCell(); j < tst->GetPosition().VCell(); j++)
		{
			for (int k = this->GetEndPosition().VCell(); k < GetPosition().VCell(); k++)
			{
				if (k==j)
					return 1;
			}  // the cell already contains a game object
		}
		}
	return 0;
}
	

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	CellPosition c2=this->GetEndPosition();

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer,c2);
	pGrid->UpdateInterface();
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}

