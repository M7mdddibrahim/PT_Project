#pragma once
#include "Card.h"
class CardEleven : public Card
{
	//CardEleven Parameter:
	int CardPrice;   // The CardPrice
	int FeesToPay; // Fees to Pay by the Passing Players
	Player* player;

public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position
	CardEleven();
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEleven

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEleven on the passed Player

	virtual void Save(ofstream& outfile, Type gameobj);
	virtual void Load(ifstream& infile);

	virtual ~CardEleven(); // A Virtual Destructor
};

