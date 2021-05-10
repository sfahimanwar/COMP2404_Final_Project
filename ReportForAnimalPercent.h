#ifndef REPORTFORANIMALPERCENT_H
#define REPORTFORANIMALPERCENT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

#include "Record.h"
#include "Map.h"
#include "ReportGenerator.h"
#include "ReportData.h"

//Control object class that inherits from ReportGenerator, it computes and then generates a report
//listing the animal type percentage breakdown for Canada, and for each animal type, the percentage change from 2011 to 2016

class ReportForAnimalPercent: public ReportGenerator{
    public:
        //Constructor that takes in a CompareBehaviour object pointer parameterized for type float and then initializes reportData
        ReportForAnimalPercent(CompareBehaviour<float>*);
        //Destructor deallocates the ReportData object
        ~ReportForAnimalPercent();
        //printReport() prints out the generated report to the console and to a .txt file
        //uses a stringstream object initially output to, also uses ReportData's overloaded stream insertion operator
        virtual void printReport();
        //performs the computations for the report generation, uses the yearMap to retrieve and process records
        //clears the reportData first incase user has computed multiple times, then it retrieves the animal and year keys to iterate
        //for every animal and for both years, calculates the total number of animals in region CAN of that single animal type
        //then it calculates total number of all animal types in CAN and uses both values to calculate percent of that single animal type
        //uses the percent calculated for 2011 and 2016 to calculate percentage change, stores all 3 values in a vector of floats which is passed
        //into the formatData() method, compute() uses two helper functions for computation
        virtual void compute();

    private:
        ReportData<float>* reportData; //stores the report data which is computed by compute() and formatted by formatData()
        //formatData() takes the computed statistics - vector of floats, and uses them to populate the ReportData data member
        //also takes in a string representing the animal type and a float which represents the percent change from 2011 to 2016, and is also
        //used as a key for the ordering of the rows in ReportData. The method builds the string and then adds it to the reportData member.
        void formatData(string, float, vector<float>&);
        //helper method for the compute() method, takes in an int representing the year
        //retrieves the records for the specific year, iterates through all the retrieved records and then adds up the total number of all animals in "CAN"
        int computeTotalAnimalsForYear(int);
        //helper method for the compute() method, takes in an int representing the year and a string representing the animalType
        //retrieves the records for the specific year, iterates through all the retrieved records and then adds up the total number of a specific animal in "CAN"
        int findNumSingleAnimalForYear(int, string);

};

#endif
