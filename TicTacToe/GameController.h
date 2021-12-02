#pragma once
class State;

class GameController
{
public:
	GameController();
	~GameController();

	static void Update();
	static void Init();
	static void ChangeState(State* newState) { currentState = newState; }

	static void Quit() { isRunning = false; }

private:
	static State* currentState;
	static bool isRunning;
};

