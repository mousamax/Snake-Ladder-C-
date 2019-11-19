#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (const int v,const int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
		vCell = -1; 
		hCell = -1; 
		SetVCell(v);
		SetHCell(h);

}

CellPosition::CellPosition (const int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v>=0 && v<NumVerticalCells){                   // It returns true, if the parameter is valid and the setting is applied, 
		   vCell=v;
		   return 1;
	   }else{
		   return 0;
	}		

}

bool CellPosition::SetHCell(int h){ // The setter of hCell (the setter here sets only if the "h" is in grid range)
	if (h>=0 && h<NumHorizontalCells){                   // It returns true, if the parameter is valid and the setting is applied, 
			 hCell=h;
		   return 1;
	   }else{
		   return 0;
	}							  // It returns true, if the parameter is valid and the setting is applied, 
	}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell()const
{
	///TODO: Implement this function as described in the .h file
	if (hCell>=0 && hCell<NumHorizontalCells &&  vCell>=0 && vCell<NumVerticalCells ) {
		return true;
	}
	else return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	int CellNum=0;
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it
	int v=cellPosition.VCell();
	int h=cellPosition.HCell();  //4,5
	///TODO: Implement this function as described in the .h file
	v=NumVerticalCells-1-v;
	CellNum=(NumVerticalCells*v)+1+h;

	return CellNum; 
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	int v=0; int h=0;
	for (int i = 0; i < NumVerticalCells; i++)
	{
		if ((cellNum>=((NumHorizontalCells*i)+1)) && (cellNum <= (NumHorizontalCells+(NumHorizontalCells*i)))){
			v=i;
			h=cellNum-(NumHorizontalCells*i+1);
			v=NumVerticalCells-1-v;
			break;
		}
	}
   
	position.SetHCell(h);
	position.SetVCell(v);
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it

	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file
	int CellNum=0;
	CellNum=GetCellNum();
	CellNum+=addedNum;
	if (CellNum > 99)
		CellNum=99;

	GetCellPositionFromNum(CellNum);

	// Note: this function updates the data members (vCell and hCell) of the calling object

}