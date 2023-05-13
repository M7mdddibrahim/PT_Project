#pragma once
#include "Action.h"
class CopyCardAction : public Action
{
	CellPosition CardPosition;
public:
	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CopyCardAction();
};

