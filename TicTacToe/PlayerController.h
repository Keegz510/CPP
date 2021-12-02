#pragma once
#include <string>

#pragma region Forward Declaration

class InGameState;

#pragma endregion
class PlayerController
{
public:
	PlayerController(std::string ticTacToeObject, InGameState* state);			// Default constructor
	~PlayerController();				// Default deconstructor

	std::string GetObject() const { return tttObject; }			// Returns the tic tac toe object

	void TakeTurn();			// Handles the player placing an object

private:
	std::string tttObject;

	InGameState* state;					// Reference to the in game state

	
};

