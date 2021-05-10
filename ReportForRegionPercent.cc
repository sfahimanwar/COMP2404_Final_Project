#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "ReportForRegionPercent.h"

ReportForRegionPercent::ReportForRegionPercent(CompareBehaviour<float>* c) {
    reportData = new ReportData<float>(c);
}

ReportForRegionPercent::~ReportForRegionPercent(){
    delete reportData;
}
void ReportForRegionPercent::printReport() {
    stringstream ss;
    ss << "                                                                       PERCENTAGE OF FARMS BY REGION IN 2016                                       " << endl;
    ss << "                                                                       -------------------------------------                                       " << endl;
    ss << "     "   <<right<<setw(15)<< "Horses/Ponies"
                        <<right<<setw(15)<<"Goats"
                        <<right<<setw(15)<<"   Llamas Alpacas"
                        <<right<<setw(15)<<"Rabbits"
                        <<right<<setw(15)<<"  Bison/Buffalo"
                        <<right<<setw(15)<<"Elk/Wapiti"
                        <<right<<setw(15)<<"   Domestic Deer"
                        <<right<<setw(15)<<"Wild Boars"
                        <<right<<setw(15)<<"Mink"
                        <<right<<setw(15)<<"Totals"
                        <<endl;
    ss << *reportData;
    string output = ss.str();
    cout << output;
    ofstream outfile("ReportForRegionPercent.txt", ios::out);
    if(!outfile){
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    outfile << output;
    outfile.close();
}

void ReportForRegionPercent::compute() {
    reportData->clear();
    vector<string>& regionKeys = regionMap.getKeyCollection();
    int totalFarmsForAllAnimals = computeFarmsForAllRegions();
    vector<string>& animalKeys = animalMap.getKeyCollection();
    for(int i = 0; i < regionKeys.size(); ++i){
        if(regionKeys[i] != "CAN"){
            vector<float> computations;
            vector<Record*>& regionRecords = regionMap[regionKeys[i]];
            for(int i = 0; i < animalKeys.size(); ++i){
                int farmsForSingleAnimalInRegion = computeNumFarmsForRegionForSingleAnimal(animalKeys[i], regionRecords);
                int totalFarmsForSingleAnimal = computeTotalFarmsForSingleAnimal(animalKeys[i]);
                float percent;
                if(totalFarmsForSingleAnimal == 0){
                    percent = 0;
                }else{
                    percent = ((float)farmsForSingleAnimalInRegion/(float)totalFarmsForSingleAnimal)*100;
                }
                computations.push_back(percent);
            }
            int totalFarmsForSingleRegion = computeFarmsForSingleRegion(regionRecords);
            float total = ((float)totalFarmsForSingleRegion/(float)totalFarmsForAllAnimals)*100;
            computations.push_back(total);
            formatData(regionKeys[i], total, computations);
        }
    }
}

void ReportForRegionPercent::formatData(string region, float total, vector<float>& computations) {
    stringstream ss;
    ss << left << setw(15) << region;
    for(int i = 0; i < computations.size(); ++i){
        ss << left << setw(15) << std::fixed << setprecision(1) << computations[i];
    }
    reportData->add(total, ss.str());
}

int ReportForRegionPercent::computeNumFarmsForRegionForSingleAnimal(string animal, vector<Record *>& regionRecords) {
    for(int i = 0; i < regionRecords.size(); ++i){
        if(regionRecords[i]->getSubregion() == "All" && regionRecords[i]->getYear() == 2016 && animal == regionRecords[i]->getAnimalType()){
            return regionRecords[i]->getNumFarms();
        }
    }
    return 0;
}

int ReportForRegionPercent::computeTotalFarmsForSingleAnimal(string animal) {
    vector<Record*>& animalRecords = animalMap[animal];
    int total = 0;
    for(int i = 0; i < animalRecords.size(); ++i){
        if(animalRecords[i]->getRegion() != "CAN" && animalRecords[i]->getSubregion() == "All" && animalRecords[i]->getYear() == 2016){
            total += animalRecords[i]->getNumFarms();
        }
    }
    return total;
}

int ReportForRegionPercent::computeFarmsForAllRegions() {
    vector<Record*>& recordsFrom2016 = yearMap[2016];
    int total = 0;
    for(int i = 0; i < recordsFrom2016.size(); ++i){
        if(recordsFrom2016[i]->getRegion() != "CAN" && recordsFrom2016[i]->getSubregion() == "All"){
            total += recordsFrom2016[i]->getNumFarms();
        }
    }
    return total;
}

int ReportForRegionPercent::computeFarmsForSingleRegion(vector<Record *>& regionRecords) {
    int total = 0;
    for(int i = 0; i < regionRecords.size(); ++i){
        if(regionRecords[i]->getSubregion() == "All" && regionRecords[i]->getYear() == 2016){
            total += regionRecords[i]->getNumFarms();
        }
    }
    return total;
}

