#pragma once
#include "Card.h"
class CardEleven : public Card
{
	//CardEleven Parameter:
	int CardPrice;   // The CardPrice
	int FeesToPay; // Fees to Pay by the Passing Players

public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEleven

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEleven on the passed Player


	virtual ~CardEleven(); // A Virtual Destructor
};

