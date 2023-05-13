#include "CardEleven.h"

CardEleven::CardEleven(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 11; // Set the Card Number
}

CardEleven:: ~CardEleven(void)
{
}
void CardEleven::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardEleven, Enter CardPrice : ");
	pIn->GetInteger(pOut);
	pOut->PrintMessage("New CardEleven, Enter Fees to pay by passing players : ");
	pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

}
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
}