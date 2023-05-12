#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 7; // Set the Card Number
}

CardSeven:: ~CardSeven(void)
{
}
void CardSeven::ReadCardParameters(Grid* pGrid)
{

}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

}