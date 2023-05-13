#include "CardTen.h"

CardTen::CardTen(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 10; // Set the Card Number
}

CardTen:: ~CardTen(void)
{
}
void CardTen::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardTen, Enter CardPrice : ");
	pIn->GetInteger(pOut);
	pOut->PrintMessage("New CardTen, Enter Fees to pay by passing players : ");
	pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

}
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
}