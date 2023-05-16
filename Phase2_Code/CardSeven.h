#pragma once
#include "Card.h"
class CardSeven :  public Card
{
public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position
	CardSeven();
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSeven 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player

	virtual void Save(ofstream& outfile, Type gameobj);
	virtual void Load(ifstream& infile);

	virtual ~CardSeven(); // A Virtual Destructor
};

