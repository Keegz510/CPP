#pragma once
class Profile;
class DyArray
{
public:
	DyArray();
	DyArray(Profile* profiles);
	~DyArray();

	inline int Count() const { return currentSize; }

	void Add(Profile* profile);
	Profile* GetProfile(int id);

	// === SORTING === //
	void SortScoreAscending();
	void SortByID();

	// === SAVE & LOAD === //
	void SaveProfiles();
	void LoadProfiles();

	// === DISPLAYING === //
	void DisplayProfiles();


	bool Contains(Profile* profile);
	

private:
	Profile* profiles;
	int maxSize;
	int currentSize;

	void ResizeArray();

};

