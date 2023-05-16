#pragma once
#include "Action.h"
class OpenGridAction :   public Action
{
    // this string member variable holds the name of the file to open
    string filename;

public:
    // this is the constructor for the OpenGridAction class which takes a pointer to the ApplicationManager as a parameter
    OpenGridAction(ApplicationManager* ptr);
    // in this function we read paramaters of open grid action like for example filename
   virtual void ReadActionParameters(); 
   // This function executes the action by reading the grid data from the file and loads it into the Grid object
   virtual void Execute();
    virtual ~OpenGridAction();//this is desrtuctor

}; 

