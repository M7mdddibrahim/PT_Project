#pragma once
#include "Card.h"
class CardTwo :  public Card
{

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
	

	virtual ~CardTwo(); // A Virtual Destructor

};

