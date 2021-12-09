#include "PlayerController.h"
#include "InGameState.h"
#include "GridController.h"
#include "GameController.h"
#include "GameOverState.h"
#include <iostream>
PlayerController::PlayerController(std::string ticTacToeObject, InGameState* state)
{
	this->tttObject = ticTacToeObject;
	this->state = state;
}

PlayerController::~PlayerController()
{
	delete state;
}

void PlayerController::TakeTurn()
{
	
	std::string input;
	std::cout << "Enter Placement: ";
	std::cin >> input;

	GridController* grid = state->GetGrid();

	while (true)
	{
		if (grid->ValidateInput(input))
		{
			
			grid->AddObjectToGrid(this, state->GetGrid()->GetGridPosition(input));
			if (grid->CheckColWin(this) || grid->CheckDiagLeft(this) || grid->CheckDiagRight(this) || grid->CheckRowWin(this))
			{
				state->GameOver();
			}
			else if (grid->CheckDraw())
			{
				state->GameOver(true);
			}
			
			break;
		}
	}
	
}




