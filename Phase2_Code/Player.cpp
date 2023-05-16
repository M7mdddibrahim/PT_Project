#include "Player.h"
#include"Grid.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::setroll(bool s)
{
	checkRoll = s;
}
void Player::setpreventroll(bool s)
{
	preventroll = s;
}

bool Player::getpreventroll()
{
	return preventroll;
}

bool Player::getcheckroll()
{
	return checkRoll;
}

void Player::setpreventroll3(bool s)
{
	preventroll3 = s;
}

bool Player::getpreventroll3()
{
	return false;
}

bool Player::getpreventroll3()
{
	return preventroll3;
}

void Player:: SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}
 int Player::getjustRolledDiceNum()
{
	return justRolledDiceNum;
}
int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
int Player::GetPlayerNum() 
{
	return playerNum;
}

void Player::SetStepCount(int x)
{
	stepCount = (x > 0) ? x : 0;
}

void Player::SetTurnCount(int x)
{
	turnCount = (x < 3 && x > -1) ? x : 0;
}

void Player::setCheckAnotherRoll(bool state)
{
	CheckAnotherRoll = state;
}
bool Player::getCheckAnotherRoll()
{
	return CheckAnotherRoll;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();

	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	int x,y;
	turnCount++;
	
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	 //  if  turn count reached 3 then set the wallet value and dont move 
	if (this->turnCount == 3)
	{
		this->SetWallet((this->GetWallet() )+ (10 * diceNumber));
		turnCount = 0;
		return;
	}

	//  if player have zero money ||OR|| his got his wallet to be zero(in the prevented card action) so that he might get his recharge 
	if ((this->GetWallet()<=0)||(diceNumber==0))
	{
		if (this->turnCount == 3)
		{
			this->SetWallet((this->GetWallet()) + (10 * diceNumber));
			turnCount = 0;
		}
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = this->GetCell()->GetCellPosition();
	pos.AddCellNum(diceNumber);

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	
	pGrid->UpdatePlayerCell(this, pos);
	// 6- Apply() the game object of the reached cell (if any)
	CellPosition checkpos;
	CellPosition tempcellpos;
	bool checkapply = true;
	CurrentPlayer->setCheckAnotherRoll(false);
	while ((pGrid->GetGameObject(checkpos)))
	{
		if (checkapply)
		{
			tempcellpos= checkpos;
			pGrid->GetGameObject(checkpos)->Apply(pGrid, CurrentPlayer);
			checkpos = CurrentPlayer->GetCell()->GetCellPosition();
			checkapply = false;
		}
		else if ((pGrid->GetGameObject(checkpos)) != (pGrid->GetGameObject(tempcellpos)))
		{
			tempcellpos = checkpos;
			pGrid->GetGameObject(checkpos)->Apply(pGrid, CurrentPlayer);
			checkpos = CurrentPlayer->GetCell()->GetCellPosition();
		}
		else if ((pGrid->GetGameObject(checkpos)) == (pGrid->GetGameObject(tempcellpos)))
		{
			break;
		}
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (pos.GetCellNum() == 99)
	{
		pGrid->SetEndGame(true);
	}
}
Player* Player::GetPoor(Player* p2)
{
	if (wallet > (p2->wallet))
		return p2;
	else
		return this;
}
Card* Player::changeOwnerships(Player* p1, Grid* pGrid)
{

	CardNine* tempptr = NULL;
	int price = -1;
	int mostexpensiveindex = 0;
	for (int i = 0; i < 3; i++)
	{
		if (ownedcities[i] != NULL && ownedcities[i].CardPrice() > price)
		{
			price = ownedcities[i].CardPrice();
			tempptr = ownedcities[i];
			mostexpensiveindex = i;
		}
	}

	if (tempptr != NULL)
	{
		pGrid->PrintErrorMessage("Most expensive city of current player will be given to poorest player, click to continue");
		p1->ownedcities[mostexpensiveindex] = tempptr;//ownership moved to passed player
		ownedcities[mostexpensiveindex] = NULL; //Drops the most expensive city to current player
		countcities--;
		p1->countcities++;
	}
	else
	{
		pGrid->PrintErrorMessage("No exchange of cities, current player has no cities to exchange, click to continue");

	}
	return tempptr;

}
void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}