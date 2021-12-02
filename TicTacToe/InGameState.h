#pragma once
#include "State.h"
#include "GridController.h"
#include <string>

#pragma region Forward Declarations

class PlayerController;

#pragma endregion

class InGameState : public State
{
public:
	InGameState();
	~InGameState();

	virtual void Draw() override;				// Handles drawing the state
	virtual void Input();						// Handles input for the state

	inline GridController* GetGrid() { return grid; }				// Returns the tic tac toe grid

	inline void SwitchTurn() { playersTurn = playersTurn == 1 ? 2 : 1; }			// inline method to switch the state

	void GameOver(bool draw = false);				// Handles the game being over

public:
	// Reference to the players
	PlayerController* player1;
	PlayerController* player2;

	int playersTurn;					// Which players turn it is
	
	// Grid Object
	GridController* grid;				// Reference to the player
};

