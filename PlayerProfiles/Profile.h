#pragma once
#include <string>
#include <fstream>
class Profile
{
public:
	Profile();
	Profile(std::string username, int score);
	Profile(std::ifstream& file);
	~Profile();

	void Display();
 
	// Get the user data
	inline int GetID() const { return profileID; }
	inline std::string GetUsername() const { return username; }
	inline int GetScore() const { return score; }

	// Set the new data
	inline void SetID(const int id) { profileID = id; }
	inline void SetUsername(std::string newUsername) { username = newUsername;}
	inline void SetScore(const int newScore) { score = newScore; }

	// Save & load the data
	void SaveProfile(std::fstream& file);
	void LoadProfile(std::ifstream& file);
	
private:
	int profileID;
	std::string username;
	int score;
};

