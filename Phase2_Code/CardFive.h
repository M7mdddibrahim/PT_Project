#pragma once
#include "Card.h"
class CardFive :  public Card
{
public:
	CardFive(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFive 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player

	virtual ~CardFive(); // A Virtual Destructor
};
