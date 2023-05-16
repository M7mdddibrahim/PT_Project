
#include "InputDiceValue.h"
#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager * pApp) : Action(pApp)
{
	int DiceValue = 0;
}

void InputDiceValue::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please, enter a dice value between 1-6");
	int DiceValue = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
	while (DiceValue > 6 || DiceValue < 1)
	{
		pOut->PrintMessage("Please, Re-enter a dice value between 1-6");
		DiceValue = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
	}
}

void InputDiceValue::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();
	if (pGrid->GetEndGame() == true)
	{
		pOut->PrintMessage("The Game is finished. Thank you ! Click to Exit");
		int x, y;
		pIn->GetPointClicked(x, y);
		pManager->ExecuteAction(EXIT);
	}
	if (CurrentPlayer->GetcheckPreventMove)
	{
		int x, y;
		pOut->PrintMessage("you are prevented from moving this turn!... Click anywhere to continue");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		CurrentPlayer->incrementTurnCount();
		pGrid->AdvanceCurrentPlayer();
		return;

	}
	if (CurrentPlayer->GetCheckPrison())
	{
		int x, y;
		pOut->PrintMessage(" You are now in prison!... Click anywhere to continue.");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();

		int PrisonedPlayerNum = CurrentPlayer->GetPrisonedPlayerNum();
		int CurrentPlayerTurnCount = CurrentPlayer->GetTurnCount();
		for (int i = CurrentPlayerTurnCount; i < 3; i++)
		{
			if (CurrentPlayer->GetPlayerNum() == PrisonedPlayerNum)
			{
				pOut->PrintMessage("You're in prison!...Click Anywhere to continue.");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				CurrentPlayer->GetTurnCount();
				pGrid->AdvanceCurrentPlayer();
				return;
			}
		}
	}
}


InputDiceValue::~InputDiceValue()
{
}
