#pragma once
#include "State.h"
class ViewScoresState : public State
{
public:
	ViewScoresState();
	~ViewScoresState();

	void Draw() override;
	void Input() override;

private:
	class DyArray* profiles;
};

