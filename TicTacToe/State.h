#pragma once
#include <iostream>
class State
{
public:
	State()
	{}
	~State()
	{}

	virtual void Draw()
	{
		system("CLS");				// Clear the console
	}

	virtual void Input() = 0;
};