#pragma once
#include "Card.h"
class CardTwelve :  public Card
{
public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position
	CardTwelve();
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwelve

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwelve on the passed Player

	virtual void Save(ofstream& outfile, Type gameobj);
	virtual void Load(ifstream& infile);

	virtual ~CardTwelve(); // A Virtual Destructor
};

