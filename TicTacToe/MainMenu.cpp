#include "MainMenu.h"
#include "GameController.h"
#include "InGameState.h"

void MainMenu::Draw()
{
	std::cout << "1 - New Game" << std::endl;
	std::cout << "2 - Exit" << std::endl;
	Input();
}

void MainMenu::Input()
{
	int input;
	std::cin >> input;

	input == 1 ? GameController::ChangeState(new InGameState()) : GameController::Quit();
}
