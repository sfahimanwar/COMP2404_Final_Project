#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "ReportForHighestSubregion.h"

ReportForHighestSubregion::ReportForHighestSubregion(CompareBehaviour<int> *c) {
    reportData = new ReportData<int>(c);
}

ReportForHighestSubregion::~ReportForHighestSubregion(){
    delete reportData;
}

void ReportForHighestSubregion::formatData(string region, string subRegion, int numAnimals) {
    stringstream ss;
    ss << "           " << left << setw(10) << region;
    ss << left << setw(30) << subRegion;
    ss << right << setw(15) << numAnimals;

    reportData->add(numAnimals, ss.str());
}


void ReportForHighestSubregion::printReport() {
    stringstream ss;
    ss << "           SUBREGION WITH THE MOST HORSE/PONIES BY REGION IN 2016" << endl;
    ss << "           -------------------------------------------------------" << endl;
    ss << *reportData;
    string output = ss.str();
    cout << output;
    ofstream outfile("ReportForHighestSubregion.txt", ios::out);
    if(!outfile){
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    outfile << output;
    outfile.close();
}

void ReportForHighestSubregion::compute() {
    reportData->clear();
    vector<string>& regionKeys = regionMap.getKeyCollection();

    for(int i = 0; i < regionKeys.size(); ++i){
        if(regionKeys[i] != "CAN"){
            int max;
            string subregion = findSubRegionWithMax(regionKeys[i], max);
            formatData(regionKeys[i], subregion, max);
        }
    }
}

string ReportForHighestSubregion::findSubRegionWithMax(string region, int &max) {
    max = 0;
    string subRegion = "";
    vector<Record*>& horsesAndPonies = animalMap["Horses-Ponies"];
    for(int i = 0; i < horsesAndPonies.size(); ++i){
        if(region == horsesAndPonies[i]->getRegion() && horsesAndPonies[i]->getSubregion() != "All" && horsesAndPonies[i]->getYear() == 2016){
            if(horsesAndPonies[i]->getNumAnimals() > max){
                max = horsesAndPonies[i]->getNumAnimals();
                subRegion = horsesAndPonies[i]->getSubregion();
            }
        }
    }
    return subRegion;
}