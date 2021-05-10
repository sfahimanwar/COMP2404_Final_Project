#ifndef REPORTFORREGIONPERCENT_H
#define REPORTFORREGIONPERCENT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

#include "Record.h"
#include "Map.h"
#include "ReportGenerator.h"
#include "ReportData.h"

//Control object class that inherits from ReportGenerator, it computes and then generates a report
//listing the regional percentage breakdown of farms that hosted animals of each type in 2016

class ReportForRegionPercent: public ReportGenerator{
    public:
        //Constructor takes in a CompareBehaviour object pointer parameterized for type float and then initializes the reportData member
        ReportForRegionPercent(CompareBehaviour<float>*);
        //Destructor deallocates the ReportDate object
        ~ReportForRegionPercent();
        //printReport() prints out the generated report to the console and to a .txt file
        //uses a stringstream object initially output to, also uses ReportData's overloaded stream insertion operator
        virtual void printReport();
        //performs the computations for the report generation, uses the regionMap to retrieve and process records
        //clears the reportData first incase user has computed multiple times, then it retrieves the region Map's and animal Map's keys for iteration
        //calls a helper method to calculate total farms for all regions combined in 2016 which is used later in all computations
        //the method iterates through every region except "CAN" and for every animal calculates number of farms for that single region and also all regions combined
        //uses 4 helper methods throughout the method, also for each region computes percentage of total farms it has compared to all regions which is used as key for the reportData
        //Stores all computations in a vector of floats, the region as a string, the total percentage and the vector of floats is passed to the formatData() method
        virtual void compute();

    private:
        //stores the report data which is computed by compute() and formatted by formatData()
        ReportData<float>* reportData;
        //formatData() takes in a string representing the region, float representing the total percentage and a vector of floats containing
        //the computations fromm the compute() method, uses the total percent as a key for the ordering of rows in the reportData.
        void formatData(string, float, vector<float>&);
        //helper method for the compute() method, takes in a string representing an animal and a reference to a vector of Record pointers representing
        //the records of a certain region. The method iterates through all the region's records and finds the number of farms hosting that animal type in 2016
        int computeNumFarmsForRegionForSingleAnimal(string, vector<Record*>&);
        //helper method for the compute() method, takes in a single string representing an animal, it then uses the animalMap to retrieve the records
        //for that specific animal. It iterates through all of the records and adds up the total number of farms in 2016 hosting that animal in all regions
        int computeTotalFarmsForSingleAnimal(string);
        //helper method for the compute() method, computes total number of farms for all regions for all animals in 2016
        int computeFarmsForAllRegions();
        //helper method for the compute() method, takes in a reference to a vector of Record pointers for a specific region
        //iterates through the records and adds up all the farms for all animals for that single region in 2016
        int computeFarmsForSingleRegion(vector<Record*>&);

};

#endif
