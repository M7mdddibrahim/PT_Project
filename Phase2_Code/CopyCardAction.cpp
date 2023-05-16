#include "CopyCardAction.h"
#include"Output.h"
#include"Input.h"
#include"Card.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	pManager = pApp;
}

CopyCardAction::~CopyCardAction()
{
}


void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Copy Card Action, Click to continue....");
	int x = 0; int y = 0;
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Click on the Source Cell");
	CopyCard = pIn->GetCellClicked();
	if (!(CopyCard.IsValidCell()))
	{
		pOut->PrintMessage("Please click on another cell");
		CopyCard = pIn->GetCellClicked();
	}
	pOut->ClearStatusBar();

}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	bool a = pGrid->GetCard(CopyCard);
	if (a)
	{
		pGrid->SetClipboard(pGrid->GetCard(CopyCard));
	}
	if (!a)
	{
		pGrid->PrintErrorMessage("Copy Card Operation can not be done...");
	}
	pGrid->UpdateInterface();


}
