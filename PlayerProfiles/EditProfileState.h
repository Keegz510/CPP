#pragma once
#include "State.h"

enum class ProfileState
{
	ViewProfiles,
	ViewSingleProfile,
	EditProfile
};

enum class EditState
{
	Username,
	Score
};

class EditProfileState : public State
{
public:
	EditProfileState();
	~EditProfileState();

	void Draw() override;
	void Input() override;

private:
	
	// === DRAW THE STATES === //
	void DrawAllProfiles();
	void DrawSingleProfile();
	void DrawEditProfile();

	// === INPUT FOR THE STATES === //
	void ViewProfileInput(int returnIndex);
	void SingleProfileInput();
	void EditProfileInput();
	
	class DyArray* profiles;
	class Profile* viewingProfile;
	ProfileState currentState;					// Current state of this view

	EditState FieldEditting;

};

