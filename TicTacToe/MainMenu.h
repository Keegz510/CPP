#pragma once
#include "State.h"
class MainMenu : public State
{
public:
	MainMenu() {}
	~MainMenu() {}

	void Draw() override;				// Draws the state
	void Input() override;				// Handles the input for this state
};

