#pragma once
#include "Card.h"
class CardSix : public Card
{
	// CardSix Parameters:
	CellPosition CelltoMoveto; // the wallet value to decrease from the player

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position
	CardSix();
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
	
	virtual void Save(ofstream& outfile, Type gameobj);
	virtual void Load(ifstream& infile);

	virtual ~CardSix(); // A Virtual Destructor
};

