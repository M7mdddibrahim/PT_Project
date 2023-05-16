#include "CardTwo.h"
#include<fstream>

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 2; // Set the Card Number
}
CardTwo::CardTwo()
{
	cardNumber = 2;
 }

CardTwo :: ~CardTwo(void)
{
}
void CardTwo::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card Two .Click to continue");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}
void CardTwo::Apply(Grid* pGrid, Player* Player)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, Player);
	Ladder* laddr = pGrid->GetNextLadder(Player->GetCell()->GetCellPosition().GetCellNum());

	if (laddr == NULL)
	{
		pOut->PrintMessage("There are no ladders ahead.Click to continue");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		return;
	}
	CellPosition ladderStart = laddr->GetPosition();
	pOut->PrintMessage("Go to the next ladder.Click to continue");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pGrid->UpdatePlayerCell(Player, ladderStart);
}

void CardTwo::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardTwo::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}