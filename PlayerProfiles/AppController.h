#pragma once


class State;
class DyArray;

class AppController
{
public:
	static void Init();
	static void Draw();
	static void Update();
	static void Quit();

	static DyArray* GetProfiles() { return profiles; }

	static void ChangeState(State* state) { activeState = state; }

	static bool hasQuit;

private:

	static void LoadProfiles();
	

	static bool isRunning;
	
	static State* activeState;

	static DyArray* profiles;

	
	
};

