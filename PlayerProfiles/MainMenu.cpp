#include "MainMenu.h"
#include "NewProfileState.h"
#include "ViewScoresState.h"
#include "AppController.h"
#include "EditProfileState.h"
#include <iostream>
MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Draw()
{
	std::cout << "*** Main Menu ***" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "1 - Add New Score" << std::endl;
	std::cout << "2 - View Scores" << std::endl;
	std::cout << "3 - Edit Score" << std::endl;
	std::cout << "4 - Exit" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "Enter a number to continue: ";
	Input();
}

void MainMenu::Input()
{
	int input;
	bool isValid = false;
	do
	{
		std::cin >> input;
		std::cout << std::endl;
		if (input < 5)
		{
			isValid = true;
		}
	} while(!isValid);

	switch (input)
	{
		case 1:
			AppController::ChangeState(new NewProfileState());
			break;
		case 2:
			AppController::ChangeState(new ViewScoresState);
			break;
		case 3:
			AppController::ChangeState(new EditProfileState);
			break;
		case 4:
			AppController::Quit();
			break;
		default:
			std::cout << "Errorr with input closing application";
			AppController::Quit();
			break;
	}
}
