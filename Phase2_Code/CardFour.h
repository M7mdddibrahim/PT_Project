#pragma once
#include "Card.h"
class CardFour : public Card
{
public:
	CardFour(const CellPosition& pos); // A Constructor takes card position
	CardFour();

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFour which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

	virtual void Save(ofstream& outfile, Type gameobj);
	virtual void Load(ifstream& infile);

	virtual ~CardFour(); // A Virtual Destructor
};

