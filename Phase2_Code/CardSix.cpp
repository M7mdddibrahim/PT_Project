#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 6; // Set the Card Number
}

CardSix:: ~CardSix(void)
{
}
void CardSix::ReadCardParameters(Grid* pGrid)
{

}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

}
