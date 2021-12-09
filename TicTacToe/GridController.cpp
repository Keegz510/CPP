#include "GridController.h"
#include "PlayerController.h"
#include "InGameState.h"
#include <iostream>

GridController::GridController(InGameState* state)
{
	this->state = state;
	for (auto x = 0; x < 3; x++)
	{
		for (auto y = 0; y < 3; y++)
		{
			grid[x][y] = "-";
		}
	}

	// === Upper case validation === //
	validInput[0] = "Q"; validInput[1] = "W"; validInput[2] = "E";
	validInput[3] = "A"; validInput[4] = "S"; validInput[5] = "D";
	validInput[6] = "Z"; validInput[7] = "X"; validInput[8] = "C";
	// === Lower case validation === //
	validInput[9] = "q"; validInput[10] = "w"; validInput[11] = "e";
	validInput[12] = "a"; validInput[13] = "s"; validInput[14] = "d";
	validInput[15] = "z"; validInput[16] = "x"; validInput[17] = "c";

}

void GridController::DrawGrid()
{
	std::cout << grid[0][0] << " " << grid[0][1] << " " << grid[0][2] << std::endl;
	std::cout << grid[1][0] << " " << grid[1][1] << " " << grid[1][2] << std::endl;
	std::cout << grid[2][0] << " " << grid[2][1] << " " << grid[2][2] << std::endl;
}

bool GridController::AddObjectToGrid(const PlayerController* player, GridPosition pos)
{
	// Ensure that the placement is within the bounds of the array
	if(pos.x > 3 || pos.y > 3) 
		return false;


	// Check if the grid position is empty and can be added,
	// If it is than add the object and return true
	if (grid[pos.x][pos.y] != "X" && grid[pos.x][pos.y] != "O")
	{
		grid[pos.x][pos.y] = player->GetObject();
		state->SwitchTurn();
		return true;
	}

	// If we hit this return state the object was not added due
	// to invalid placement
	return false;
}

bool GridController::ValidateInput(std::string input)
{
	for (auto i = 0; i < 18; i++)
	{
		if(input == validInput[i])
			return true;
	}
	return false;
}

GridPosition GridController::GetGridPosition(const std::string input)
{

	for (auto i = 0; i < 18; ++i)
	{
		// Pre-define the grid position
		auto xPos = 0;
		auto yPos = i;

		// If the position is greater than 8 take 9 away from the index
		if(yPos >= 9) yPos -= 9;
		
		
		// Check how many more we need to tae from the index to get the full position
		if (yPos > 2 && yPos < 5)
		{
			yPos -= 3;
		}
		else if (yPos > 4 && yPos < 6)
		{
			yPos -= 6;
		}
		else if (yPos > 5)
		{
			yPos -= 6;
		}
		
		

		if (input == validInput[i])
		{
			
			if ((i >= 0 && i < 3) || (i >= 9 && i < 12))
			{
				xPos = 0;
			}
			else if ((i <= 3 && i < 6) || i <= 12 && i < 15)
			{
				xPos = 1;
			}
			else
			{
				xPos = 2;
			}

			if (input == "s")
				xPos -= 1;

			return GridPosition(xPos, yPos);
		}
	}

	return GridPosition(-1, -1);
}

bool GridController::CheckIfWin(const PlayerController* player, int x, int y, CheckWinDirection direction)
{
	auto pObject = player->GetObject();				// The players object we are checking

	GridPosition checkPoint1;
	GridPosition checkPoint2;

	if (direction == CheckWinDirection::Across)
	{
		// Set the checkpoints of the grid positions
		checkPoint1 = GridPosition(x + 1, y + 0);
		checkPoint2 = GridPosition(y + 2, y + 0);
	}
	else if (direction == CheckWinDirection::Down)
	{
		checkPoint1 = GridPosition(x, y + 1);
		checkPoint2 = GridPosition(x, y + 2);
	}
	else if (direction == CheckWinDirection::DiaganolLeft)
	{
		checkPoint1 = GridPosition(x + 1, y + 1);
		checkPoint2 = GridPosition(x + 2, y + 2);
	}
	else
	{
		checkPoint1 = GridPosition(x - 1, y - 1);
		checkPoint2 = GridPosition(x - 2, y - 2);
	}

	// Ensure the points we are checking are within array bounds
	if(checkPoint1.x > 2 || checkPoint1.y > 2 || checkPoint1.x < 0 || checkPoint1.y < 0)
		return false;
	if(checkPoint2.x > 2 || checkPoint2.y > 2 || checkPoint2.x < 0 || checkPoint2.y < 0)
		return false;

	// Check each grid checkpoint plus the current position are equal
	if (grid[x][y] == pObject 
	&& grid[checkPoint1.x][checkPoint1.y] == pObject 
	&& grid[checkPoint2.x][checkPoint2.y] == pObject)
		return true;
		
	
	return false;
}

bool GridController::CheckRowWin(const PlayerController* player)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if(CheckIfWin(player, x, y, CheckWinDirection::Across))
				return true;
		}
	}
	return false;
}

bool GridController::CheckColWin(const PlayerController* player)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if(CheckIfWin(player, x, y, CheckWinDirection::Down))
				return true;
		}
	}
	return false;
}

bool GridController::CheckDiagLeft(const PlayerController* player)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (CheckIfWin(player, x, y, CheckWinDirection::DiaganolLeft))
				return true;
		}
	}
	return false;
}

bool GridController::CheckDiagRight(const PlayerController* player)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (CheckIfWin(player, x, y, CheckWinDirection::DiaganolRight))
				return true;
		}
	}
	return false;
}

bool GridController::CheckDraw()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if(grid[x][y] == "-")
				return false;
		}
	}
	return true;
}



