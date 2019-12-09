#include "Ladder.h"
#include "Player.h"
#include"Grid.h"

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell() != endCellPos.HCell() || startCellPos.GetCellNum() > endCellPos.GetCellNum())
		return;

	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

bool Ladder::IsOverlapping(GameObject* newObj)const
{
	Ladder* tst = dynamic_cast<Ladder*>(newObj);
	if (!tst)
		return 0;

	CellPosition ctst = tst->GetPosition();

	if (ctst.HCell() != this->GetPosition().HCell())
		return 0;

	int no_of_vcells = this->GetPosition().VCell() - this->endCellPos.VCell();

	for (int i = 0; i < no_of_vcells; i++)
	{
		CellPosition Flag(this->GetPosition().VCell() + i, this->GetPosition().HCell());
		int tst_vcells = tst->GetPosition().VCell();
		if (tst_vcells == Flag.VCell()) {
			return 1;
		}
	}
	return 0;
}



void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	CellPosition c2 = this->GetEndPosition();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pOut->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, c2);
	//    Review the "pGrid" functions and decide which function can be used for that

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}