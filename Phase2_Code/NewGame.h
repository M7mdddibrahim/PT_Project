#pragma once
#include "Action.h"
class NewGame : public Action
{
	public:

		NewGame(ApplicationManager* pApp);  // Constructor

		// ============ Virtual Functions ============

		virtual void ReadActionParameters() ; // Reads parameters required for action to execute 
		// (code depends on action type so virtual)

		virtual void Execute() ;  // Executes action (code depends on action type so virtual)

		virtual ~NewGame();  // Virtual Destructor
	
};

