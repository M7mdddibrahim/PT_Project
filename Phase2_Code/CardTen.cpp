#include "CardTen.h"
#include <fstream>

CardTen::CardTen(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 10; // Set the Card Number
	player = NULL;
}

CardTen::CardTen()
{
	cardNumber = 10;
}

CardTen:: ~CardTen(void)
{
}
void CardTen::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardTen, Enter CardPrice : ");
	pIn->GetInteger(pOut);
	pOut->PrintMessage("New CardTen, Enter Fees to pay by passing players : ");
	pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

}
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	if (player == NULL)
	{
		pOut->PrintMessage("Do you want to buy card ten? y/n");
		string c = pIn->GetSrting(pOut);
		if (c == "y")
		{
			if (CardPrice > pPlayer->GetWallet())
			{
				pGrid->PrintErrorMessage("You Do not have enough money to buy card ten! click to continue....");
				int x = 0; int y = 0;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
			if (CardPrice < pPlayer->GetWallet())
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				pGrid->PrintErrorMessage("Your wallet value is" + to_string(pPlayer->GetWallet() - CardPrice));
				int x = 0; int y = 0;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}

		}
		if (c == "n")
		{
			int x = 0; int y = 0;
			pIn->GetPointClicked(x, y);
		}
		if (c != "y" && c != "n")
		{
			pOut->PrintMessage("Error! Please enter y or n...");
			c = pIn->GetSrting(pOut);
		}
	}
	if (player != NULL)
	{
		pGrid->PrintErrorMessage("This player already has a game object! click to continue....");
		int x = 0; int y = 0;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	if (pPlayer->GetPlayerNum() != player->GetPlayerNum())
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - FeesToPay);
		player->SetWallet(player->GetWallet() + FeesToPay);
		pGrid->PrintErrorMessage("Your new wallet value" + to_string(pPlayer->GetWallet()));
		int x = 0; int y = 0;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}

}
void CardTen::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardTen::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}