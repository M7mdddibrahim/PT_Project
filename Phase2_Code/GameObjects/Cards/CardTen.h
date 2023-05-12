#pragma once
#include "Card.h"
class CardTen : public Card
{
	//CardTen Parameter:
	int CardPrice;   // The CardPrice
	int FeesToPay; // Fees to Pay by the Passing Players

public:
	CardTen(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTen

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTen on the passed Player


	virtual ~CardTen(); // A Virtual Destructor
};

