#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include"Card.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager == pApp;
}
void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the Source Cell");
	pIn->GetCellClicked();

	pOut->ClearStatusBar();

}
void CopyCardAction::Execute()
{
	/*Grid* pGrid = pManager->GetGrid();
	Card* pCard
	pCard->GetCardNumber();
	pGrid->SetClipboard(pCard);
	if(pCard == NULL)
	{
		pGrid->PrintErrorMessage("Error! Cel Can not be copied ");
	}*/
	
}
 CopyCardAction :: ~CopyCardAction()
{

}