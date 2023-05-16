#include "CardTwelve.h"
#include <fstream>



CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 12; // Set the Card Number
}

CardTwelve::CardTwelve()
{
	cardNumber = 12;
}

CardTwelve:: ~CardTwelve(void)
{
}
void CardTwelve::ReadCardParameters(Grid* pGrid)
{

}
void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		Card::Apply(pGrid, pPlayer);
		Player* poorest = pGrid->GetPoorest();
		Card* MostExpensiveStation = pPlayer->changeOwnerships(poorest, pGrid);
		if (MostExpensiveStation != NULL)
		{
			MostExpensiveStation->changeOwner(poorest);
		}
	}
}
void CardTwelve::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardTwelve::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}