#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//Entity object class that represents individual census data read in from a file

class Record{
    friend ostream& operator<<(ostream&, Record&); //overloaded stream insertion operator that outputs all the record's data

    public:
        //Constructor that takes in a int for year, string for region, string fro subRegion, string for animalType, and ints for numFarms and numAnimals
        Record(int=2000, string="UNKNOWN", string="UNKNOWN", string="UNKNOWN", int=0, int=0);
        int getYear();
        string getRegion();
        string getSubregion();
        string getAnimalType();
        int getNumFarms();
        int getNumAnimals();

    private:
        int year;
        string region;
        string subRegion;
        string animalType;
        int numFarms;
        int numAnimals;
};

#endif
