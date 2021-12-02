#include "EditProfileState.h"
#include "AppController.h"
#include "DyArray.h"
#include "MainMenu.h"
#include "Profile.h"

#include <iostream>

EditProfileState::EditProfileState()
{
	profiles = AppController::GetProfiles();
	currentState = ProfileState::ViewProfiles;
}

EditProfileState::~EditProfileState()
{
	delete profiles;
	delete viewingProfile;
}

void EditProfileState::Draw()
{
	// === OUTPUT HEADER === //
	std::cout << "*** View & Edit Profiles ***" << std::endl;
	std::cout << "============================" << std::endl;
	// Determine what we need to display on the screen
	switch (currentState)
	{
		case ProfileState::EditProfile:
			DrawEditProfile();
			break;
		case ProfileState::ViewProfiles:
			DrawAllProfiles();
			break;
		case ProfileState::ViewSingleProfile:
			DrawSingleProfile();
			break;

			
	}
}

void EditProfileState::DrawAllProfiles()
{
	if (profiles != nullptr)
	{
		// Check if there are profiles
		if (profiles->Count() > 0)
		{
			// Print all the profiles to the screen
			for (int i = 0; i < profiles->Count(); ++i)
			{
				profiles->GetProfile(i)->Display();
			}
		}
		else
		{
			// Indicate to the user that there are no profiles to show
			std::cout << "No Profiles..." << std::endl;
		}
	}

	int lastIndex = profiles->Count() + 1;			// Get the number we want to enter to return to the main menu screen

	// Prompt user input
	std::cout << "Enter ID to edit profile or enter " << lastIndex << " to return: ";
	ViewProfileInput(lastIndex);
}

void EditProfileState::ViewProfileInput(int returnIndex)
{
	// Get the user input
	int input;
	std::cin >> input;
	
	// Check what the input is
	if (input == returnIndex)
	{
		// Return the user back to the main menu
		AppController::ChangeState(new MainMenu());
	}
	else
	{
		// Get the profile & dislay it
		viewingProfile = profiles->GetProfile(input);
		currentState = ProfileState::ViewSingleProfile;
	}
}


void EditProfileState::DrawSingleProfile()
{
	if (viewingProfile != nullptr)
	{
		// Display the user profile
		std::cout << "ID: " << viewingProfile->GetID() << std::endl;
		std::cout << "Username: " << viewingProfile->GetUsername() << std::endl;
		std::cout << "Score: " << viewingProfile->GetScore() << std::endl;

		// Prompt user for input
		std::cout << "1: Username | 2: Edit Score | 3: Return: ";
		SingleProfileInput();
	}
	else
	{
		currentState = ProfileState::ViewSingleProfile;
	}
}

void EditProfileState::SingleProfileInput()
{
	// Get the user inut
	int input;
	std::cin >> input;

	// Determine if we are using a field or updating a user
	// Depending on the input determine what we want to edit
	switch (input)
	{
		case 1:
			FieldEditting = EditState::Username;
			currentState = ProfileState::EditProfile;
			break;
		case 2:
			FieldEditting = EditState::Score;
			currentState = ProfileState::EditProfile;
			break;
		case 3:
			currentState = ProfileState::ViewProfiles;
			break;
	}
}

void EditProfileState::DrawEditProfile()
{
	// Determines what we are editing and prompts the user for input
	if (FieldEditting == EditState::Score)
	{
		std::cout << "Enter New Score:";
		EditProfileInput();
	}
	else
	{
		std::cout << "Enter new Username: ";
		EditProfileInput();
	}
}

void EditProfileState::EditProfileInput()
{
	// Determine what we are editting and update the profile
	if (FieldEditting == EditState::Score)
	{
		int input;
		std::cin >> input;

		viewingProfile->SetScore(input);
	}
	else
	{
		std::string input;
		std::cin >> input;

		viewingProfile->SetUsername(input);
	}

	// Return to the view profile screen
	currentState = ProfileState::ViewProfiles;
	viewingProfile = nullptr;
}

void EditProfileState::Input()
{
	// LEFT BLANK AS USING INDVIVUAL INPUT FUNCTIONS
}

