#include "PasteCardAction.h"
#include"Output.h"
#include"Input.h"
#include"Card.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

PasteCardAction:: ~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Paste Card Action, Click to Continue...");
	int x = 0; int y = 0;
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Click on the Destination Cell");
	PasteCard = pIn->GetCellClicked();
	if (!(PasteCard.IsValidCell()))
	{
		pOut->PrintMessage("Please click on another cell");
		PasteCard = pIn->GetCellClicked();
	}
	if (PasteCard.GetCellNum() == 1)
	{
		pOut->PrintMessage("You Can not add game object to the first cell, Click to continue...");
		int x = 0; int y = 0;
		pIn->GetPointClicked(x, y);
		PasteCard = pIn->GetCellClicked();

	}
	if (PasteCard.GetCellNum() == 99)
	{
		pOut->PrintMessage("You Can not add gane object to the last cell, Click to continue...");
		int x = 0; int y = 0;
		pIn->GetPointClicked(x, y);
		PasteCard = pIn->GetCellClicked();
	}
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	bool c = pGrid->GetCard(PasteCard);
	if (c)
	{
		pGrid->PrintErrorMessage("This cell already has card, Click on another cell...");
		int x = 0; int y = 0;
		pIn->GetPointClicked(x, y);
		PasteCard = pIn->GetCellClicked();
	}
	bool l = pGrid->GetLadder(PasteCard);
	if (l)
	{
		pGrid->PrintErrorMessage("This cell aLready has ladder, Click on another cell...");
		int x = 0; int y = 0;
		pIn->GetPointClicked(x, y);
		PasteCard = pIn->GetCellClicked();
	}
	bool s = pGrid->GetSnake(PasteCard);
	if (s)
	{
		pGrid->PrintErrorMessage("ThiS cell already has snake, Click on another cell..");
		int x = 0; int y = 0;
		pIn->GetPointClicked(x, y);
		PasteCard = pIn->GetCellClicked();
	}
	if ((!c) && (!l) && (!s))
	{
		Card* DestinationCell;
		DestinationCell = pGrid->GetClipboard();
		PasteCard = pGrid->AddObjectToCell(DestinationCell);
	}
	pGrid->UpdateInterface();



}
