#pragma once
#include "Action.h"
#include "Grid.h"

class SaveGridAction :    public Action
{
    string filename; // name of file in which I'll implement save

public:
    SaveGridAction(ApplicationManager* ptr); // this is constructor
    virtual void ReadActionParameters();// in this function we read paramaters of save grid action like for example filename
    virtual void Execute(); // this function calls ReadActionParameters then calls SaveAll of each gameobj  
    virtual ~SaveGridAction(); // this is virtual distructor

};