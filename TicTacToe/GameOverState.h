#pragma once
#include "State.h"

enum class GameResult
{
	Player1Win,
	Player2Win,
	Draw
};

class GameOverState : public State
{
public:
	GameOverState(GameResult result);
	~GameOverState();

	void Draw() override;
	void Input() override;

private:
	GameResult result;
	
};

