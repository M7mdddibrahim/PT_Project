#include "CardFive.h"
#include "Ladder.h"
#include "Snake.h"
#include <fstream>


CardFive::CardFive(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 5; // Set the Card Number
}

CardFive::CardFive()
{
	cardNumber = 5;
}

CardFive:: ~CardFive(void)
{
}
void CardFive::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You Stood on Card Five!, Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Ladder* NextLadder = pGrid->GetNextLadder(position.GetCellNum());
	Snake* NextSnake = pGrid->GetNextSnake(position.GetCellNum());
	
	pOut->PrintMessage("Move Backword the same number of steps that you just rolled. Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pPlayer->Move(pGrid, (pPlayer->getjustRolledDiceNum())*-1);

	if (position.GetCellNum() == NextLadder->GetEndPosition().GetCellNum())
	{
		pOut->PrintMessage("Now you will move up the ladder. Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	else if (position.GetCellNum() == NextSnake->GetEndPosition().GetCellNum())
	{
		pOut->PrintMessage("Now you will move down the Snake. Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
}
void CardFive::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardFive::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}