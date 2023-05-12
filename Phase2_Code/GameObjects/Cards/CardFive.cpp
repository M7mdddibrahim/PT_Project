#include "CardFive.h"

CardFive :: CardFive(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 5; // Set the Card Number
}

CardFive:: ~CardFive(void)
{
}
void CardFive::ReadCardParameters(Grid* pGrid)
{

}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

}
