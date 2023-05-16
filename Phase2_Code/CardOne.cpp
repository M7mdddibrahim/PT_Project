#include "CardOne.h"
#include<fstream>

CardOne::CardOne(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}
CardOne::CardOne()
{
	cardNumber = 1;
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->PrintMessage("New CardOne: Enter its wallet amount=");
	walletAmount = pIn->GetInteger(pOut);

	while (walletAmount < 0)
	{
		pOut->PrintMessage("Please ReEnter its wallet amount= ");
		walletAmount = pIn->GetInteger(pOut);
	}

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();

}

void CardOne::Apply(Grid* pGrid, Player* Player)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, Player);

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	Player->SetWallet(Player->GetWallet() - walletAmount);
	pOut->PrintMessage("Player new wallet=" + to_string(Player->GetWallet()));
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}
void CardOne::Save(ofstream& outfile, Type gameobj)
{
	if (gameobj == Cards)
	{
		outfile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardOne::Load(ifstream& infile)
{
	int  CellposNum;
	infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}
