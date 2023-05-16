#include <iostream>
using namespace std;
#include "OpenGridAction.h"
#include "Grid.h"
#include<fstream>
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "Snake.h"
#include "Ladder.h"
#include "Input.h"
#include "output.h"
// this is the constructor for the OpenGridAction class, which takes a pointer to the ApplicationManager as a parameter
OpenGridAction::OpenGridAction(ApplicationManager* ptr) :Action(ptr) 
{

}
// this function prompts the user to enter the name of the file to open and stores it in the 'filename' member variable
void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("To save enter file's name ");
	filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}
// this function executes the action by reading the grid data from the file and loads it into the Grid object
void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ifstream infile;
	string file = filename + ".text";
	infile.open(file);

	int NumberOfLadders, NumberOfSnakes, NumberOfCards;



	if (!infile.is_open())
	{
		pGrid->PrintErrorMessage(" This File doesn't exist. Click to continue ... ");
		return;
	}
	CellPosition FirstCellInTheGrid(1);
	if (pGrid->GetNextLadder(FirstCellInTheGrid) || pGrid->GetNextSnake(FirstCellInTheGrid) || pGrid->GetNextCard(FirstCellInTheGrid))
	{
		pGrid->CleanGrid();
	}
	infile >> NumberOfLadders;
	GameObject* pNewObject;
	for (int i = 0; i < NumberOfLadders; i++)
	{
		pNewObject = new Ladder();
		pNewObject->Load(infile);
		pGrid->AddObjectToCell(pNewObject);
	}
	infile >> NumberOfSnakes;
	for (int i = 0; i < NumberOfSnakes; i++)
	{
		pNewObject = new Snake();
		pNewObject->Load(infile);
		pGrid->AddObjectToCell(pNewObject);
	}
	infile >> NumberOfCards;
	for (int i = 0; i < NumberOfCards; i++)
	{
		int CardNumber;
		infile >> CardNumber;
		switch (CardNumber)
		{
		case 1:
			pNewObject = new CardOne();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 2:
			pNewObject = new CardTwo();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 3:
			pNewObject = new CardThree();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 4:
			pNewObject = new CardFour();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 5:
			pNewObject = new CardFive();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 6:
			pNewObject = new CardSix();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 7:
			pNewObject = new CardSeven();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 8:
			pNewObject = new CardEight();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 9:
			pNewObject = new CardNine();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 10:
			pNewObject = new CardTen();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 11:
			pNewObject = new CardEleven();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 12:
			pNewObject = new CardTwelve();
			pNewObject->Load(infile);
			pGrid->AddObjectToCell(pNewObject);
			break;

		}
	}
	infile.close();
}

OpenGridAction::~OpenGridAction() //this is destructor
{
}