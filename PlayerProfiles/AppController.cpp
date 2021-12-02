#include "AppController.h"
#include "State.h"
#include "MainMenu.h"
#include "DyArray.h"
#include <iostream>
bool AppController::isRunning = false;
bool AppController::hasQuit = false;
State* AppController::activeState = nullptr;
DyArray* AppController::profiles = nullptr;


void AppController::Init()
{
	isRunning = true;			// Set the application to running
	activeState = new MainMenu();			// Set the main menu as the active state
	LoadProfiles();						// Handle Writing the files
}

void AppController::Draw()
{
	system("CLS");				// Clear the screen

	// display the base header
	std::cout << "*** Acrade Score Manager ***" << std::endl;
	std::cout << "============================" << std::endl;
	// Display the active state
	activeState->Draw();
}

void AppController::Update()
{
	// update the game
	while (isRunning)
	{
		Draw();
	}
}

void AppController::LoadProfiles()
{
	profiles = new DyArray();
	profiles->LoadProfiles();
}

void AppController::Quit()
{
	profiles->SaveProfiles();

	hasQuit = true;
	isRunning = false;
	
}
