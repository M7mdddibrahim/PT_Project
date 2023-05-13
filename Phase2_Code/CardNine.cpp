#include "CardNine.h"
#include"ApplicationManager.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 9; // Set the Card Number
}

CardNine:: ~CardNine(void)
{
}
void CardNine::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardNine, Enter CardPrice : ");
	pIn->GetInteger(pOut);
	pOut->PrintMessage("New CardNine, Enter Fees to pay by passing players : ");
	pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);


}
