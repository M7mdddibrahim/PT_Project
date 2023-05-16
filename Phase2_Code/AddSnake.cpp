#include "AddSnake.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnake::AddSnake(ApplicationManager* pApp) : Action(pApp)
{
	draws = true;
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnake::~AddSnake()
{
}

void AddSnake::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	if (endPos.GetCellNum() > startPos.GetCellNum())
	{
		pGrid->PrintErrorMessage(" Error End cell cannot be larger than start cell. ");
		pOut->ClearStatusBar();
		draws = false;
		return;
	}
	if (endPos.HCell() != startPos.HCell())
	{
		pGrid->PrintErrorMessage(" Error End cell  are not in the same column of start cell. ");
		pOut->ClearStatusBar();
		draws = false;
		return;
	}
	if (endPos.VCell() == startPos.VCell())
	{
		pGrid->PrintErrorMessage(" Error End cell and start cell are in the same Row .");
		pOut->ClearStatusBar();
		draws = false;
		return;
	}
	if (endPos.IsValidCell() == false)
	{
		pGrid->PrintErrorMessage(" Error The end cell is invalid! Click to continue .");
		pOut->ClearStatusBar();
		draws = false;
		return;
	}
	if (startPos.IsValidCell() == false)
	{
		pGrid->PrintErrorMessage(" Error The start cell is invalid! Click to continue.");
		pOut->ClearStatusBar();
		draws = false;
		return;
	}



	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnake::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (draws = true)
	{
		// Create a Ladder object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);

		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	}

}