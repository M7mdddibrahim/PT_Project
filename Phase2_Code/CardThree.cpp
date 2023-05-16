#include "CardThree.h"
#include<fstream>

CardThree::CardThree(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 3; // Set the Card Number
}
CardThree::CardThree()
{
	cardNumber = 3;
}

CardThree:: ~CardThree(void)
{
}
void CardThree::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card Three. Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You are given another dice roll. Click to continue");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pPlayer->setroll(true);
}
void CardThree::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardThree::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}
