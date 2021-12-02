#include "NewProfileState.h"
#include "Profile.h"
#include "DyArray.h"
#include "MainMenu.h"
#include "AppController.h"

#include <iostream>
NewProfileState::NewProfileState()
{
	profile = new Profile();
}

NewProfileState::~NewProfileState()
{
	delete profile;
}

void NewProfileState::Draw()
{
	// Display the scene header
	std::cout << "*** New Profile ***" << std::endl;
	std::cout << "============================" << std::endl;
	// Prompt for input
	std::cout << "Enter Username: ";
	Input();
	// Prompt for input
	std::cout << std::endl;
	std::cout << "Enter New Score: ";
	Input();

	// Create the new profile
	CreateProfile();
	// Return to the main menu once profile has been added
	AppController::ChangeState(new MainMenu());
}

void NewProfileState::Input()
{
	// Determine what field we are adding to and update the profile
	if (!bEnteredUsername)
	{
		char* username = new char[3];
		std::cin >> username;
		profile->SetUsername(username);
		bEnteredUsername = true;
	}
	else
	{
		int score;
		std::cin >> score;
		int newID = AppController::GetProfiles()->Count();
		// Update the profile
		profile->SetScore(score);
		profile->SetID(newID);

	}
}

void NewProfileState::CreateProfile()
{
	AppController::GetProfiles()->Add(profile);
}
