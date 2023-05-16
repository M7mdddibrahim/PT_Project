#pragma once
#include "Card.h"
class CardThree : public Card
{
public:
	CardThree(const CellPosition& pos); // A Constructor takes card position
	CardThree();

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThree 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	virtual void Save(ofstream& outfile, Type gameobj);
	virtual void Load(ifstream& infile);


	virtual ~CardThree(); // A Virtual Destructor
};

