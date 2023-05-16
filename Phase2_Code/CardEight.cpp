#include "CardEight.h"
#include<fstream>

CardEight::CardEight(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 8; // Set the Card Number
}
CardEight::CardEight()
{
	cardNumber = 8;
}

CardEight:: ~CardEight(void)
{
}
void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card Eight. Click to continue");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Enter the fees to get out of prison");
	TheAmountOfCoins = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached card Eight do you want to pay the " + to_string(TheAmountOfCoins) + "fees? 1 to pay 2 to stay in prison for 3 rounds:");
	int answer = 0;
	answer = pIn->GetInteger(pOut);
	while (answer != 1 && answer != 2)
	{
		pOut->PrintMessage("Choose 1 to pay 2 to stay in prison for 3 rounds");
	}
	if (answer == 1)
	{
		if (pPlayer->GetWallet() < TheAmountOfCoins)
		{
			pOut->PrintMessage("You dont have enough money");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->PrintMessage("You wont play for tree rounds");
			pPlayer->setpreventroll3(true);
		}
		else
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - TheAmountOfCoins);
			pOut->PrintMessage("You got out of prison");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->PrintMessage("your new wallet=" + to_string(pPlayer->GetWallet()));
			pIn->GetPointClicked(x, y);
		}
	}
	else
	{
		pOut->PrintMessage("You wont play for three rounds");
		pPlayer->setpreventroll3(true);
	}
}

void CardEight::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardEight::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}
