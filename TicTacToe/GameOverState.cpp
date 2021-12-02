#include "GameOverState.h"
#include "GameController.h"
#include "InGameState.h"
#include "MainMenu.h"

GameOverState::GameOverState(GameResult res)
{
	result = res;
}

GameOverState::~GameOverState()
{
}

void GameOverState::Draw()
{
	if (result == GameResult::Draw)
	{
		std::cout << "===== DRAW! =====" << std::endl;
	}
	else if (result == GameResult::Player1Win)
	{
		std::cout << "===== PLAYER 1 WINS! =====" << std::endl;
	}
	else
	{
		std::cout << "===== PLAYER 2 WINS! =====" << std::endl;
	}

	std::cout << "Would you like to play again? (y/n): ";
	Input();
}

void GameOverState::Input()
{
	std::string input;
	std::cin >> input;
	if (input == "y")
	{
		GameController::ChangeState(new InGameState());
	}
	else
	{
		GameController::ChangeState(new MainMenu());
	}
}
