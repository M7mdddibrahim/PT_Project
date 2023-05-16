#include "CardFour.h"
#include<fstream>

CardFour::CardFour(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 4; // Set the Card Number
}
CardFour::CardFour()
{
	cardNumber = 4;
}

CardFour:: ~CardFour(void)
{
}
void CardFour::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card Four. Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You are prevented from rolling next turn. Click to continue");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pPlayer->setpreventroll(true);
}
void CardFour::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardFour::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}