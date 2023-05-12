#pragma once
#include "Card.h"
class CardNine :  public Card
{
	//CardNine Parameter:
	int CardPrice;   // The CardPrice
	int FeesToPay; // Fees to Pay by the Passing Players

public:
	CardNine(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNine

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player


	virtual ~CardNine(); // A Virtual Destructor
};

