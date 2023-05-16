#include "SaveGridAction.h"
#include <fstream>

SaveGridAction::SaveGridAction(ApplicationManager* ptr) :Action(ptr) 
{
	pManager = ptr;// this initializes pManager with ptr of Action passed
}

void SaveGridAction::ReadActionParameters() 
{                                    // identify pointer to input and output classes
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("To save enter file's name ");//takes gameobj's paramater (name of file)
	filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar(); // this clears status bar after using it at the end of function
}

void SaveGridAction::Execute()
{                          //reads action parameters
	ReadActionParameters();
	ofstream outfile;       // open the output file with the given name
	string file = filename + ".text";
	outfile.open(file);
	// get the Grid pointer from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	// save the number of ladders to the file
	outfile << pGrid->GetNumberOfLadders() << endl;
	pGrid->SaveAll(outfile, Ladders);
	// save the number of snakes to the file
	outfile << pGrid->GetNumberOfSnakes() << endl;
	pGrid->SaveAll(outfile, Snakes);
	//save the number of cards to the file
	outfile << pGrid->GetNumberOfCards() << endl;
	pGrid->SaveAll(outfile, Cards);
	// close the output file
	outfile.close();
}

SaveGridAction::~SaveGridAction() //destructor
{
}
