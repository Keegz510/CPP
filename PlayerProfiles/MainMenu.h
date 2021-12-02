#pragma once
#include "State.h"
class MainMenu : public State
{
public:
	MainMenu();
	~MainMenu();

	virtual void Draw() override;
	virtual void Input() override;
};

