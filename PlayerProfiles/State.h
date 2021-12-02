#pragma once
class State
{
public:
	State() {}
	~State() {}

	virtual void Draw() = 0;			// Handles displaying the state
	virtual void Input() = 0;			// Handles user input

private:

};

