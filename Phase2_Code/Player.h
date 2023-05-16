#pragma once

#include "Grid.h"
#include "Cell.h"
#include "CardNine.h"
class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	bool checkRoll = false; //to check if the the player have another roll
	bool preventroll = false; //to check if the the player have blocked roll
	bool preventroll3 = false; //to check if the the player have blocked roll for 3 round
	int count3round;
	CardNine* ownedcities[3];
	int countcities;
bool CheckAnotherRoll;
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount
	int GetPlayerNum();

	int getjustRolledDiceNum();     //A getter for dice no.

	
	void SetStepCount(int x);

	void SetTurnCount(int x);

	///TODO: You can add setters and getters for data members here (if needed)
	void setCheckAnotherRoll(bool state);
	bool getCheckAnotherRoll();
	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	Player* GetPoor(Player* p2);
	Card* changeOwnerships(Player* p1, Grid* pGrid);
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)
	void setroll(bool s); //set the roll true or false for cards 3
	bool getcheckroll();
	void setpreventroll(bool s); //set the roll true or false for cards 4
	bool getpreventroll();
	void setpreventroll3(bool s); //set the roll true or false for cards 8
	bool getpreventroll3();
};

