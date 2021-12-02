#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
public:
	struct Record {
		Image image;
		string name;
		int age;
	};

private:
	int recordCount;				// Total amount of records
	std::vector<Record*> records;	// delete this vector. Load only the required record 



public:
	DataFile();
	~DataFile();

	// Add a new record
	void AddRecord(string imageFilename, string name, int age);
	// Get a record
	Record* GetRecord(int index);

	// Return how many records there are
	int GetRecordCount() { return recordCount; };

	// Save the record
	void Save(string filename);
	// Load the record
	void Load(string filename);
	// Loads a single file
	Record* Load(int recordIndex);

private:
	void Clear();

};

