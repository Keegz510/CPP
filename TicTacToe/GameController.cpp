#include "GameController.h"
#include "State.h"
#include "MainMenu.h"
#include <iostream>

State* GameController::currentState = nullptr;
bool GameController::isRunning = false;


GameController::GameController()
{
}

GameController::~GameController()
{
	delete currentState;
}

void GameController::Init()
{
	isRunning = true;
	currentState = new MainMenu();
}

void GameController::Update()
{
	// Loop while the application is running
	while (isRunning)
	{
		system("cls");
		// Ensure the current state is valid 
		if (currentState != nullptr) 
		{
			// Draw the state & Get the input
			currentState->Draw();
			currentState->Input();
		}
		else
		{
			// Quit the game if it's running
			std::cout << "Error Running Game..../n Now quitting";
			isRunning = false;
		}
	}
}


