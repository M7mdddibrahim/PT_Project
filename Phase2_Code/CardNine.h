#pragma once
#include "Card.h"
class CardNine : public Card
{
	//CardNine Parameter:
	int CardPrice;    // The CardPrice
	int FeesToPay;   // Fees to Pay by the Passing Players
	Player* player;

public:
	CardNine(const CellPosition& pos); // A Constructor takes card position
	CardNine();

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNine

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player
	virtual void Save(ofstream& outfile, Type gameobj);
	virtual void Load(ifstream& infile);

	virtual ~CardNine(); // A Virtual Destructor
};
