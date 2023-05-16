#include "DeleteAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
	checkdelete = true; // deleting intializes with true
	// Initializes the pManager pointer of Action with the passed pointer
}

DeleteAction::~DeleteAction()
{
}

void DeleteAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete Game Object:");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Click on the card or on the start of ladder or snake");
	Cellposition = pIn->GetCellClicked();
	if (Cellposition.IsValidCell() == false)
	{
		pGrid->PrintErrorMessage(" The selected cell is invalid! Click to continue ...");
		pOut->ClearStatusBar();
		checkdelete = false;
		return;
	}

	if (!pGrid->GetGameObject(Cellposition))
	{
		pGrid->PrintErrorMessage(" There is no Object in the cell! Click to continue ...");
		pOut->ClearStatusBar();
		checkdelete = false;
		return;
	}


	pOut->ClearStatusBar();
}

void DeleteAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters(); // Reading the Parameters 
	if (checkdelete == true)
	{
		if (pGrid->GetGameObject(Cellposition))
		{
			pGrid->RemoveObjectFromCell(Cellposition); // Removing the selcted object from the cell
			return;
		}
	}
}

