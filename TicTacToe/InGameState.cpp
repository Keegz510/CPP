#include "InGameState.h"
#include "PlayerController.h"
#include "GameController.h"
#include "GameOverState.h"
#include <iostream>

InGameState::InGameState()
{
	playersTurn = 1;
	player1 = new PlayerController("X", this);
	player2 = new PlayerController("O", this);
	grid = new GridController();
	Draw();

}

InGameState::~InGameState()
{
	delete grid;
	delete player1;
	delete player2;
}

void InGameState::Draw()
{
	std::string playerTurnArt1 = playersTurn == 1 ? "Player 1*" : "Player 1";
	std::string playerTurnArt2 = playersTurn == 2 ? "Player 2*" : "Player 2";
	std::cout << " ===============" << std::endl;
	std::cout << " | " << playerTurnArt1 << std::endl;
	std::cout << " | " << playerTurnArt2 << std::endl;
	std::cout << " ===============" << std::endl;
	grid->DrawGrid();
}

void InGameState::Input()
{
	if (playersTurn == 1)
	{
		player1->TakeTurn();
	}
	else
	{
		player2->TakeTurn();
	}
}

void InGameState::GameOver(bool draw)
{
	if (draw)
	{
		GameController::ChangeState(new GameOverState(GameResult::Draw));
	}
	else
	{
		if (playersTurn == 1)
		{
			GameController::ChangeState(new GameOverState(GameResult::Player1Win));
		}
		else if (playersTurn == 2)
		{
			GameController::ChangeState(new GameOverState(GameResult::Player2Win));
		}
	}
	
}
