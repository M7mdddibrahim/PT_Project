#include "SwitchtoDesignMode.h"
#include "Grid.h"
#include "Output.h"
#include"Input.h"

SwitchtoDesignMode::SwitchtoDesignMode(ApplicationManager* pApp) : Action(pApp)
{

}

SwitchtoDesignMode::~SwitchtoDesignMode()
{

}

void SwitchtoDesignMode::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Switching to Design Mode: Click Anywhere to Continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void SwitchtoDesignMode::Execute()
{
	ReadActionParameters();
	pManager->GetGrid()->GetOutput()->CreateDesignModeToolBar();
}