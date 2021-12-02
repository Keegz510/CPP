
#include "Profile.h"
#include <iostream>
Profile::Profile()
{
	
}

Profile::Profile(std::string username, int score)
{
	this->username = username;
	this->score = score;
}

Profile::Profile(std::ifstream& file)
{
	LoadProfile(file);

}

Profile::~Profile()
{
}

void Profile::Display()
{
	std::cout << profileID << " - " << username << " - " << score << std::endl;
}

void Profile::SaveProfile(std::fstream& file)
{
	file.write((const char*)&profileID, sizeof(int));
	file.write(username.c_str(), 3);
	file.write((const char*)&score, sizeof(int));
}

void Profile::LoadProfile(std::ifstream& file)
{
	char* nameStored = new char[3];
	file.read((char*)&profileID, sizeof(int));
	file.read(nameStored, 3);
	file.read((char*)&score, sizeof(int));	

	username.assign(nameStored, 3);				// NOT WORKING

}





