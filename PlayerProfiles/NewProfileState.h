#pragma once
#include "State.h"

class Profile;

class NewProfileState : public State
{
public:
	NewProfileState();
	~NewProfileState();

	void Draw() override;
	void Input() override;

private:
	Profile* profile;				// Referennce to the new profile we are creating

	bool bEnteredUsername;

	void CreateProfile();
};

