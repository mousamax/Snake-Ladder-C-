#include "CardFourteen.h"

CardFourteen::CardFourteen(const CellPosition &pos)
	 :Card(pos)
{
	cardNumber=14;
}

void CardFourteen::ReadCardParameters(Grid *pGrid)
{
	//TODO

	//1- Get Pointers to input and output
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	//2- Read Integers from user indicating CardPrice and Fees
	pOut->PrintMessage("Enter Card Price");
	 int a=pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter Card Fees:");
	int b=pIn->GetInteger(pOut);
	if(a>0){
		CardPrice=a;}
	if(b>0){Fees=b;}
	//3- clear status bar
	pOut->ClearStatusBar();

}

void CardFourteen::Apply(Grid *pGrid,Player *pPlayer)
{
	
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	if(Isbought==false)
	{
		pOut->PrintMessage("Buy Card? y/n");
		string x=pIn->GetSrting(pOut);
		if(x=="y" || x=="Y")
		{
			if(pPlayer->GetWallet()>=CardPrice)
				{
				
					Isbought=true;
					pPlayer->SetWallet(pPlayer->GetWallet()-Fees);
					pOut->PrintMessage("Card Successfully Bought");
					pOut->ClearStatusBar();
					pPlayer=pOwner;
				}
			else
			{
				pOut->PrintMessage("Sorry, your current wallet is less than the card price");
				pOut->ClearStatusBar();
			}
		}
	}
	if(Isbought==true)
	{
		if(pPlayer!=pOwner)
		{
			if(pPlayer->GetWallet()>Fees)
			{
				pPlayer->SetWallet(pPlayer->GetWallet()-Fees);
				pOut->PrintMessage("Fees Successfully paid");
				pOut->ClearStatusBar();
				
			}

		}
		else
		{
			pOut->PrintMessage("You don't have enough coins to pay the fees");
			pOut->ClearStatusBar();
		}
	}
}