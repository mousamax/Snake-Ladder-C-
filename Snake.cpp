#include "Snake.h"
#include "Player.h"
#include"Grid.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos),ObjType(snake)
{
	if (startCellPos.HCell() != endCellPos.HCell() || startCellPos.GetCellNum() < endCellPos.GetCellNum())
		return;

	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	CellPosition c2 = this->GetEndPosition();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	//Output* pOut = new Output;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, c2);
	//    Review the "pGrid" functions and decide which function can be used for that

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& OutFile, GOType Type)
{
	if (Type == ObjType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << temp.GetCellNum() << "\t" << endCellPos.GetCellNum() << endl;

	}
	else { return; }
}

void Snake::Load(ifstream& Infile, GOType Type)
{
}

Snake::~Snake()
{
}