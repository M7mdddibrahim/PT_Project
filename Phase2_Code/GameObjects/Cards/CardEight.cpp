#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 8; // Set the Card Number
}

CardEight:: ~CardEight(void)
{
}
void CardEight::ReadCardParameters(Grid* pGrid)
{

}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

}
