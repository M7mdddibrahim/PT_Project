#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 9; // Set the Card Number
}

CardNine:: ~CardNine(void)
{
}
void CardNine::ReadCardParameters(Grid* pGrid)
{

}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

}
