#pragma once
#include "Card.h"
class CardSeven :  public Card
{
public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSeven 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player


	virtual ~CardSeven(); // A Virtual Destructor
};

