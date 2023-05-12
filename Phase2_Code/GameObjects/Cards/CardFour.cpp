#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 4; // Set the Card Number
}

CardFour:: ~CardFour(void)
{
}
void CardFour::ReadCardParameters(Grid* pGrid)
{

}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

}
