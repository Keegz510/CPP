#pragma once
#include <string>


#pragma region Forward Declarations

class PlayerController;
class InGameState;

#pragma endregion

struct GridPosition
{
public:
	GridPosition()
	{}
	GridPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x;
	int y;


};

enum class CheckWinDirection
{
	Across,
	Down,
	DiaganolRight,
	DiaganolLeft
};

class GridController
{
public:
	std::string grid[3][3];

	GridController(InGameState* state);
	~GridController(){}

	// Draws the grid object
	void DrawGrid();
	// Adds an object to the grid and returns if it's valid to place
	bool AddObjectToGrid(const PlayerController* player, GridPosition pos);

	bool ValidateInput(std::string input);
	
	GridPosition GetGridPosition(const std::string input);			// Returns where to place the tic tac toe object

	// === CHECKING DIRECTIONS FOR A WIN === //
	bool CheckIfWin(const PlayerController* player, int x, int y, CheckWinDirection direction);
	bool CheckRowWin(const PlayerController* player);
	bool CheckColWin(const PlayerController* player);
	bool CheckDiagLeft(const PlayerController* player);
	bool CheckDiagRight(const PlayerController* player);
	bool CheckDraw();			
	

private:
	std::string validInput[18];				// Array of valid inputs
	InGameState* state;			// Reference to the in game state
};

