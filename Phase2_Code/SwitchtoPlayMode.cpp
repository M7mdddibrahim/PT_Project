#include "SwitchtoPlayMode.h"
#include "Grid.h"
#include "Output.h"
#include"Input.h"


SwitchtoPlayMode::SwitchtoPlayMode(ApplicationManager* pApp) :Action (pApp)
{
}

SwitchtoPlayMode::~SwitchtoPlayMode()
{
}

void SwitchtoPlayMode::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Switching to play Mode: Click Anywhere to Continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void SwitchtoPlayMode::Execute()
{
	ReadActionParameters();
	pManager->GetGrid()->GetOutput()->CreatePlayModeToolBar();
}
