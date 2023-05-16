#include "CardSix.h"
#include "Ladder.h"
#include "Snake.h"
#include <fstream>

CardSix::CardSix(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 6; // Set the Card Number
}

CardSix::CardSix()
{
	cardNumber = 6;
}

CardSix:: ~CardSix(void)
{
}
void CardSix::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You Stood on Card Six!, Click to continue...");
	CelltoMoveto = pIn->GetCellClicked();
	pOut->ClearStatusBar();
	while (CelltoMoveto.IsValidCell() == false || CelltoMoveto.GetCellNum() == 99)
	{
		if (CelltoMoveto.GetCellNum() == 99)
		{
			pOut->PrintMessage("Cell-to-move-to can't be the last cell, Please re-enter a valid special Cell to move to ...");
			CelltoMoveto = pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
		else
		{
			pOut->PrintMessage("This cell is invalid! Pleasee re-enter a valid special Cell to move to ...");
			CelltoMoveto = pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
	}
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Ladder* NextLadder = pGrid->GetNextLadder(CelltoMoveto);
	Snake* NextSnake = pGrid->GetNextSnake(CelltoMoveto);
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
void CardSix::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardSix::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}