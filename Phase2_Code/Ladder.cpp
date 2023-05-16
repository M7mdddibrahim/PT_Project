#include "Ladder.h"
#include<fstream>

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Ladders)
	{
		outfile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
}

void Ladder::Load(ifstream& Infile) 
{
	int StartCellNum, EndCellNum;
	Infile >> StartCellNum >> EndCellNum;
	CellPosition SartCell(StartCellNum);
	CellPosition EndCell(EndCellNum);
	position = SartCell;
	endCellPos = EndCell;
}

Ladder::~Ladder()
{
}