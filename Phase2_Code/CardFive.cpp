#include "CardFive.h"



CardFive::CardFive(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 5; // Set the Card Number
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
	pOut->PrintMessage("Move Backword the same number of steps that you just rolled. Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pPlayer->Move(pGrid, (pPlayer->getjustRolledDiceNum())*-1);

}
