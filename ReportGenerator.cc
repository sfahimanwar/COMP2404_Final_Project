#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "ReportGenerator.h"

vector<Record*> ReportGenerator::primaryCollection;
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;

void ReportGenerator::cleanup() {
    for(int i = 0; i < primaryCollection.size(); ++i){
        delete primaryCollection[i];
    }
}

void ReportGenerator::loadData() {
    int year, numFarms, numAnimals;
    string region, subRegion, animalType;

    ifstream infile("farms.dat", ios::in);

    if(!infile){
        cout << "Error: Could not open file" << endl;
        exit(1);
    }

    while(infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals){
        primaryCollection.push_back(new Record(year, region, subRegion, animalType, numFarms, numAnimals));
    }

    for(int i = 0; i < primaryCollection.size(); ++i){
        yearMap.add(primaryCollection[i]->getYear(), primaryCollection[i]);
        regionMap.add(primaryCollection[i]->getRegion(), primaryCollection[i]);
        animalMap.add(primaryCollection[i]->getAnimalType(), primaryCollection[i]);
    }

}

ReportGenerator::~ReportGenerator() {}