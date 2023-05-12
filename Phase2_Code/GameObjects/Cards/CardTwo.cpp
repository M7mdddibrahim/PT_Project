#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 2; // Set the Card Number
}

CardTwo :: ~CardTwo(void)
{
}
void CardTwo::ReadCardParameters(Grid* pGrid)
{

}
void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

}
