#pragma once

#include "Action.h"

class DeleteAction : public Action
{
	CellPosition Cellposition;
	bool checkdelete;
public:

	DeleteAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads DeleteGameObject action parameters (Cellposition)

	virtual void Execute(); // delete the game object in the cell that the user chooses.

	virtual ~DeleteAction(); // Virtual Destructor
};