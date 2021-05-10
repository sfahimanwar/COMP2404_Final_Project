#include <iostream>
using namespace std;

#include "Record.h"

Record::Record(int year, string region, string subRegion, string animalType, int numFarms, int numAnimals) {
    this->year = year;
    this->region = region;
    this->subRegion = subRegion;
    this->animalType = animalType;
    this->numFarms = numFarms;
    this->numAnimals = numAnimals;
}

int Record::getYear() {
    return year;
}

string Record::getRegion() {
    return region;
}

string Record::getSubregion() {
    return subRegion;
}

string Record::getAnimalType() {
    return animalType;
}

int Record::getNumAnimals() {
    return numAnimals;
}

int Record::getNumFarms() {
    return numFarms;
}

ostream& operator<<(ostream& output, Record& r){
    output << "Year: " << r.year << "   Region: " << r.region <<  "   Subregion: " << r.subRegion <<  "   Animal Type: " << r.animalType << "   Number of farms: " << r.numFarms << "   Number of animals: " << r.numAnimals << endl;
    return output;
}