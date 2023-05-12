#include "CardEleven.h"

CardEleven::CardEleven(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 11; // Set the Card Number
}

CardEleven:: ~CardEleven(void)
{
}
void CardEleven::ReadCardParameters(Grid* pGrid)
{

}
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{

}