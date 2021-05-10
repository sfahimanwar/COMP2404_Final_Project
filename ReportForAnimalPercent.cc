#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "ReportForAnimalPercent.h"

ReportForAnimalPercent::ReportForAnimalPercent(CompareBehaviour<float> *c) {
    reportData = new ReportData<float>(c);
}

ReportForAnimalPercent::~ReportForAnimalPercent(){
    delete reportData;
}

void ReportForAnimalPercent::formatData(string animal, float change, vector<float>& computations) {
    stringstream ss;
    ss << right << setw(15) << animal;
    for(int i = 0; i < computations.size(); ++i){
        if(i == (computations.size() - 1)){
            ss << right << setw(15) << std::fixed << setprecision(1) << std::showpos << computations[i];
        }else{
            ss << right << setw(15) << std::fixed << setprecision(1) << computations[i];
        }
    }
    reportData->add(change, ss.str());
}

void ReportForAnimalPercent::printReport() {
    stringstream ss;
    ss << "                   PERCENTAGE CHANGE OF ANIMALS (2011-2016)" << endl;
    ss << "                   ----------------------------------------" << endl;
    ss << "              " << right << setw(16) << "2011"
                           << right << setw(16) << "2016"
                           << right << setw(16) << "Change"
                           << endl;
    ss << *reportData;
    string output = ss.str();
    cout << output;
    ofstream outfile("ReportForAnimalPercent.txt", ios::out);
    if(!outfile){
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    outfile << output;
    outfile.close();
}

int ReportForAnimalPercent::computeTotalAnimalsForYear(int year) {
    vector<Record*>& yearRecords = yearMap[year];
    float total = 0;
    for(int i = 0; i < yearRecords.size(); ++i){
        if(yearRecords[i]->getRegion() == "CAN"){
            total += yearRecords[i]->getNumAnimals();
        }
    }
    return total;
}

int ReportForAnimalPercent::findNumSingleAnimalForYear(int year, string animal) {
    vector<Record*>& yearRecords = yearMap[year];
    for(int i = 0; i < yearRecords.size(); ++i){
        if(yearRecords[i]->getRegion() == "CAN" && animal == yearRecords[i]->getAnimalType()){
            return yearRecords[i]->getNumAnimals();
        }
    }
    return 0;
}

void ReportForAnimalPercent::compute() {
    reportData->clear();
    vector<string>& animalKeys = animalMap.getKeyCollection();
    vector<int>& yearKeys = yearMap.getKeyCollection();
    for(int i = 0; i < animalKeys.size(); ++i){
        vector<float> computations;
        for(int j = 0; j < yearKeys.size(); ++j){
            int numSingleAnimal = findNumSingleAnimalForYear(yearKeys[j], animalKeys[i]);
            int totalAnimals = computeTotalAnimalsForYear(yearKeys[j]);
            float percent = ((float)numSingleAnimal/(float)totalAnimals)*100;
            computations.push_back(percent);
        }
        float percentChange = computations[1] - computations[0];
        computations.push_back(percentChange);
        formatData(animalKeys[i], percentChange, computations);
    }
}
