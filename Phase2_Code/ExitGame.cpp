#include "ExitGame.h"
#include "Grid.h"
#include "Output.h"
#include"Input.h"
#include <string.h>
#include <iostream>


ExitGame::ExitGame(ApplicationManager* pApp) : Action(pApp)
{
}

ExitGame::~ExitGame()
{
}

void ExitGame::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//pOut->PrintMessage("Exitting Game: Click Anywhere to Continue...");
	//int x, y;
	//pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Sure? You want to Exit the Game? if YES then write Y if NO Write any other letter ");
	string s = pIn->GetSrting(pOut);
	std::cout << s;
	if (s == "Y" || s == "y")
	{
		pOut->PrintMessage("Thank You for Staying!");
	}
	else
	{
		pOut->ClearStatusBar();
		pOut->ClearGridArea();
		//ActionType pAct = EXIT;
		pManager->ExecuteAction(EXIT);
	}
}

void ExitGame::Execute()
{
	ReadActionParameters();
	
}