#include "DataFile.h"
#include <fstream>
#include "Offsets.h"
using namespace std;

DataFile::DataFile()
{
	recordCount = 0;

}

DataFile::~DataFile()
{
	Clear();
}

/// <summary>
/// Adds a new record
/// </summary>
/// <param name="imageFilename">Name of the image file</param>
/// <param name="name">Name of the character</param>
/// <param name="age">Age of the character</param>
void DataFile::AddRecord(string imageFilename, string name, int age)
{
	// Load the image we are adding
	Image i = LoadImage(imageFilename.c_str());

	// Create the new record
	Record* r = new Record;
	r->image = i;
	r->name = name;
	r->age = age;

	// Add to the vector of data files
	records.push_back(r);
	// Increase the record count
	recordCount++;
}

/// <summary>
/// Return the request character
/// </summary>
/// <param name="index">Index of the character to get</param>
/// <returns>the request record at the index</returns>
DataFile::Record* DataFile::GetRecord(int index, Offsets offset)
{
	ifstream infile("npc_data.dat", ios::binary);
	if (infile.is_open())
	{

		infile.seekg(offset[index]);

		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		char* imgdata = new char[imageSize];
		infile.read(imgdata, imageSize);

		Image img = LoadImageEx((Color*)imgdata, width, height);
		char* name = new char[nameSize];
		int age = 0;

		infile.read((char*)name, nameSize);
		infile.read((char*)&age, ageSize);

		Record* r = new Record();
		r->image = img;
		r->name = string(name);
		r->age = age;

		infile.close();
		return r;
	}
	return records[index];
}


/// <summary>
/// Saves the list of vectors to a data file
/// </summary>
/// <param name="filename">Name of the file we want to save it to</param>
void DataFile::Save(string filename)
{
	// Create the file class
	ofstream outfile(filename, ios::binary);

	int recordCount = records.size();			// Get the amount of records there are
	outfile.write((char*)&recordCount, sizeof(int));			// Write how many records there are to the file

	// Loop through each record
	for (int i = 0; i < recordCount; i++)
	{		
		// Get the data of the image
		Color* imgdata = GetImageData(records[i]->image);
			
		// Get the size of each image
		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
		int nameSize = records[i]->name.length();
		int ageSize = sizeof(int);

		// Write the size of the files
		outfile.write((char*)&records[i]->image.width, sizeof(int));
		outfile.write((char*)&records[i]->image.height, sizeof(int));
		
		// Write the size of the name and the age
		outfile.write((char*)&nameSize, sizeof(int));
		outfile.write((char*)&ageSize, sizeof(int));

		// Write all the data to the file
		outfile.write((char*)imgdata, imageSize);
		outfile.write((char*)records[i]->name.c_str(), nameSize);
		outfile.write((char*)&records[i]->age, ageSize);
	}

	// Close the file
	outfile.close();
}

void DataFile::Load(string filename)
{
	Clear();

	ifstream infile(filename, ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	for (int i = 0; i < recordCount; i++)
	{		
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		char* imgdata = new char[imageSize];
		infile.read(imgdata, imageSize);

		Image img = LoadImageEx((Color*)imgdata, width, height);
		char* name = new char[nameSize];
		int age = 0;
				
		infile.read((char*)name, nameSize);
		infile.read((char*)&age, ageSize);

		Record* r = new Record();
		r->image = img;
		r->name = string(name);
		r->age = age;
		records.push_back(r);

		delete [] imgdata;
		delete [] name;
	}

	infile.close();
}

DataFile::Record* DataFile::Load(int recordIndex)
{
	ifstream infile("npc_data.dat", ios::binary);
	int recordCount = 0;

	if (infile.is_open())
	{
		
	}

	infile.close();
	return nullptr;

}

/// <summary>
/// Clears all the data in the file
/// </summary>
void DataFile::Clear()
{
	for (int i = 0; i < records.size(); i++)
	{
		delete records[i];
	}
	records.clear();
	recordCount = 0;
}

