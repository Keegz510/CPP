#include <raylib.h>
#include <fstream>

class Offsets
{

public:
    int operator[](int i) {
        return offsets[i];
    }

    ~Offsets() {
        delete[] offsets;
    }

    Offsets(const char* filename) {
        std::ifstream file("npc_data.dat", std::ios::binary);

        //Read number of records
        file.read((char*)&numberOfRecords, sizeof(int));

        //Allocate dynamic array for the offsets
        offsets = new int[numberOfRecords];

        //First offset is one int in.
        offsets[0] = sizeof(int);

        //Puts the read head at the beginning of the first record
        file.seekg(sizeof(int));

        for (int i = 1; i < numberOfRecords; ++i)
        {
            //Make some temp variable;
            int width;
            int height;
            int nameSize;

            //Read in the variable length info
            file.read((char*)&width, sizeof(int));
            file.read((char*)&height, sizeof(int));
            file.read((char*)&nameSize, sizeof(int));

            //Calculate total size of a record
            int sizeOfRecord =
                sizeof(int) + //image width
                sizeof(int) + //image height
                sizeof(int) + //length of the name
                sizeof(int) + //length of age
                sizeof(Color) * width * height + //image data
                nameSize + //name data
                sizeof(int); //age data

            offsets[i] = offsets[i - 1] + sizeOfRecord;
            file.seekg(offsets[i]);
        }
    }

private:
    int* offsets;
    int numberOfRecords;
};