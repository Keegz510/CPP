#include "ViewScoresState.h"
#include "AppController.h"
#include "DyArray.h"
#include "Profile.h"
#include "MainMenu.h"
#include <iostream>
ViewScoresState::ViewScoresState()
{
	profiles = AppController::GetProfiles();
}

ViewScoresState::~ViewScoresState()
{
	delete profiles;
}

void ViewScoresState::Draw()
{
	// Display the header
	std::cout << "*** View Scores ***" << std::endl;
	std::cout << "============================" << std::endl;
	// Indicate how the data is layed out
	std::cout << "ID - Username - Score" << std::endl;

	// Check if we have profiles
	if (profiles->Count() > 0)
	{
		// If we have profiles loop through them and update them
		for (int i = 0; i < profiles->Count(); ++i)
		{
			profiles->GetProfile(i)->Display();
		}
	}
	else
	{
		// If there are no files indicate that
		std::cout << "No Profiles..." << std::endl;
	}
	
	// PROMPT FOR INPUT
	std::cout << "============================" << std::endl;
	std::cout << "X: Sort Score Ascending | C: Sort Score Descending | Z: Sort By Added Date | A: Main Menu" << std::endl;
	std::cout << "Enter Action: ";
	Input();
}

void ViewScoresState::Input()
{
	char input;
	std::cin >> input;

	switch (input)
	{
		case 'a':
		case 'A':
			AppController::ChangeState(new MainMenu());
			break;
		case 'x':
		case 'X':
			profiles->SortScoreAscending();
			break;
		case 'c':
		case 'C':
			profiles->SortScoreDescending();
			break;
		case 'z':
		case 'Z':
			profiles->SortByID();
			break;
	}
}

