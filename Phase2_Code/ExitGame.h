#pragma once
#include "Action.h"
class ExitGame :    public Action
{
public:

	ExitGame(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters() ; // Reads parameters required for action to execute 
	// (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)

	virtual ~ExitGame();  // Virtual Destructor

};
