#include "DyArray.h"
#include "Profile.h"
#include <fstream>
DyArray::DyArray()
{
	maxSize = 5;
	currentSize = 0;
	this->profiles = new Profile[maxSize];
}

DyArray::DyArray(Profile* profiles)
{
	currentSize = sizeof(profiles);				// Get the size of the profile
	ResizeArray();								// Size up the array

	this->profiles = profiles;					// Assign the profiles
}

DyArray::~DyArray()
{
	delete profiles;
}

void DyArray::Add(Profile* profile)
{
	if(profile == nullptr) return;


	profiles[currentSize] = *profile;			// Add the new profile
	currentSize += 1;							// Increase the size of the array
	ResizeArray();								// resize the tree to fit all data
	SaveProfiles();
}

/// <summary>
/// Loops through the profiles and find the requested profile
/// </summary>
/// <param name="id">ID of the profile we are looking for</param>
/// <returns>The profile if found</returns>
Profile* DyArray::GetProfile(int id)
{
	for (int i = 0; i < currentSize; ++i)
	{
		if(profiles[i].GetID() == id)
			return &profiles[i];
	}
	return nullptr;
}


void DyArray::SortScoreAscending()
{
	for (int i = 0; i < currentSize - 1; ++i)
	{
		int score;
		for (int j = i; j < currentSize - 1; ++j)
		{
			if (profiles[j + 1].GetScore() > profiles[j].GetScore())
			{
				
				Profile temp = profiles[j];
				profiles[j] = profiles[j + 1];
				profiles[j + 1] = temp;
			}

		}
	}
}


void DyArray::SortByID()
{
	for (int i = 0; i < currentSize - 1; ++i)
	{
		int score;
		for (int j = i; j < currentSize - 1; ++j)
		{
			if (profiles[j + 1].GetID() > profiles[j].GetID())
			{
				Profile* temp = &profiles[j];
				profiles[j] = profiles[j + 1];
				profiles[j + 1] = *temp;
			}

		}
	}
}

void DyArray::SaveProfiles()
{
	// Open the data file storing the scores
	std::fstream file;
	file.open("profiles.dat", std::ios::out | std::ios::binary);

	// Ensures the folder is open
	if (file.is_open())
	{
		// Write the file size
		file.write((const char*)&currentSize, sizeof(int));
		// Loop through each file to load it
		for (int i = 0; i < currentSize; ++i)
		{
			profiles[i].SaveProfile(file);
		}

		file.close();
	}
}

void DyArray::LoadProfiles()
{
	// open the profiles data file
	std::ifstream file;
	file.open("profiles.dat", std::ios::in | std::ios::binary);

	// Ensure the file is open
	if (file.is_open())
	{
		// Get the amount of profiles that there is
		file.read((char*)&currentSize, sizeof(int));
		
		ResizeArray();			// Resize the array to allow for more room

		// Check if the data file isn't empty
		if (currentSize > 0)
		{
			// Create a profile for each profile in the data file
			for (int i = 0; i < currentSize; ++i)
			{
				profiles[i] = Profile(file);
			}
		}

		file.close();	
		
	}

}

void DyArray::DisplayProfiles()
{
	for (int i = 0; i < Count(); ++i)
	{
		profiles[i].Display();
	}
}

/// <summary>
/// Checks if we have a specific profile in saved
/// </summary>
/// <param name="profile">Profile we want to find</param>
/// <returns>If the array contains the profile</returns>
bool DyArray::Contains(Profile* profile)
{
	if (currentSize > 0)
	{
		for (int i = 0; i < currentSize; ++i)
		{
			if(profile->GetID() == profiles[i].GetID())
				return true;
		}
	}
	return false;
}

/// <summary>
/// Handles resize the array to that we can save the data
/// </summary>
void DyArray::ResizeArray()
{
	

	if (currentSize >= maxSize)
	{
		Profile* tempProfiles = new Profile[maxSize];
		for (int i = 0; i < sizeof(profiles); i++)
		{
			tempProfiles[i] = profiles[i];
		}

		maxSize += 20;
		profiles = new Profile[maxSize];
		for (auto i = 0; i < sizeof(tempProfiles); ++i)
		{
			profiles[i] = tempProfiles[i];
		}
	}

	
}
