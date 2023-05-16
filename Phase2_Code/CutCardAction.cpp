#include "CutCardAction.h"
#include"Output.h"
#include"Input.h"
#include"Card.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Cut Card Action, Click to Continue...");
	int x = 0; int y = 0;
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Click on the Source Cell");
	CutCard = pIn->GetCellClicked();
	if (!(CutCard.IsValidCell()))
	{
		pOut->PrintMessage("Please click on another cell");
		CutCard = pIn->GetCellClicked();
	}
	pOut->ClearStatusBar();
}

void CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	bool a = pGrid->GetCard(CutCard);
	if (a)
	{
		pGrid->SetClipboard(pGrid->GetCard(CutCard));
		pGrid->RemoveObjectFromCell(CutCard);

	}
	if (!a)
	{
		pGrid->PrintErrorMessage("Cut Card Operation can not be done.....");
	}
	pOut->ClearStatusBar();

}
