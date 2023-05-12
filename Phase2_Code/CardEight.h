#pragma once
#include "Card.h"
class CardEight :  public Card
{
	//CardEight Parameter:
	int TheAmountOfCoins;   // The Amount of Coins needed to get out of the prison

public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEight 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player


	virtual ~CardEight(); // A Virtual Destructor
};

