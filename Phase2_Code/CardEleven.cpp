#include "CardEleven.h"
#include <fstream>

CardEleven::CardEleven(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 11; // Set the Card Number
	player = NULL;
}

CardEleven::CardEleven()
{
	cardNumber = 11;
}

CardEleven:: ~CardEleven(void)
{
}
void CardEleven::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardEleven, Enter CardPrice : ");
	pIn->GetInteger(pOut);
	pOut->PrintMessage("New CardEleven, Enter Fees to pay by passing players : ");
	pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

}
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	if (player == NULL)
	{
		pOut->PrintMessage("Do you want to buy card eleven? y/n");
		string c = pIn->GetSrting(pOut);
		if (c == "y")
		{
			if (CardPrice > pPlayer->GetWallet())
			{
				pGrid->PrintErrorMessage("You Do not have enough money to buy card eleven! click to continue....");
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

void CardEleven::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardEleven::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}