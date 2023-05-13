#include "CardThree.h"

CardThree::CardThree(const CellPosition &pos): Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 3; // Set the Card Number
}

CardThree:: ~CardThree(void)
{
}
void CardThree::ReadCardParameters(Grid* pGrid)
{

}
void CardThree::Apply(Grid* pGrid ,Player* pPlayer)
{

}
