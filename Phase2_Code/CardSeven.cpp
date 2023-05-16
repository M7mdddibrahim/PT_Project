#include "CardSeven.h"
#include<fstream>

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 7; // Set the Card Number
}

CardSeven::CardSeven()
{
	cardNumber = 7;
}

CardSeven:: ~CardSeven(void)
{
}
void CardSeven::ReadCardParameters(Grid* pGrid)
{

}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	CellPosition firstcell(1);

	if (pGrid->getNextPlayer(pPlayer->GetCell()->GetCellPosition()))
		pGrid->UpdatePlayerCell(pGrid->getNextPlayer(pPlayer->GetCell()->GetCellPosition()), firstcell);
}
void CardSeven::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardSeven::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}