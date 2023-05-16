#pragma once
#include "Card.h"
#include"Ladder.h"
class CardTwo : public Card
{

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position
	CardTwo();

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
	virtual void Save(ofstream& outfile, Type gameobj);
	virtual void Load(ifstream& infile);


	virtual ~CardTwo(); // A Virtual Destructor

};

