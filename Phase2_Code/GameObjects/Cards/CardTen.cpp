#include "CardTen.h"

CardTen::CardTen(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 10; // Set the Card Number
}

CardTen:: ~CardTen(void)
{
}
void CardTen::ReadCardParameters(Grid* pGrid)
{

}
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{

}