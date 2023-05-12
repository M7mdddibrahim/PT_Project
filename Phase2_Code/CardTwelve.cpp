#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) //Set the Cell Position of the Card
{
	cardNumber = 12; // Set the Card Number
}

CardTwelve:: ~CardTwelve(void)
{
}
void CardTwelve::ReadCardParameters(Grid* pGrid)
{

}
void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{

}