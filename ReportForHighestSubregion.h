#ifndef REPORTFORHIGHESTSUBREGION_H
#define REPORTFORHIGHESTSUBREGION_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

#include "Record.h"
#include "Map.h"
#include "ReportGenerator.h"
#include "ReportData.h"

//Control object class that inherits from ReportGenerator, it computes and then generates a report
//listing the sub-region, within each region, that hosted the highest number of horses and ponies in 2016

class ReportForHighestSubregion: public ReportGenerator{
    public:
        //Constructor that takes in a CompareBehaviour object pointer parameterized for type int and then initializes reportData
        ReportForHighestSubregion(CompareBehaviour<int>*);
        //Destructor deallocates the ReportData object
        ~ReportForHighestSubregion();
        //printReport() prints out the generated report to the console and to a .txt file
        //uses a stringstream object initially output to, also uses ReportData's overloaded stream insertion operator
        virtual void printReport();
        //performs the computations for the report generation, uses the animalMap to retrieve and process records
        //clears the reportData first incase user has computed multiple times, then it retrieves the region Map's keys for iteration
        //for every region except "CAN", finds the subregion with highest number of horses-ponies in 2016 and the value itself with the help of
        //a helper function, the method then passes in the required variables to formatData() to format the output
        virtual void compute();

    private:
        //stores the report data which is computed by compute() and formatted by formatData()
        ReportData<int>* reportData;
        //formatData() takes in a string of the region, the string of the highest subregion and it's associated number of animals to populate the ReportData data member
        //the number of animals is used as a key for the ordering of the rows in ReportData. The method builds the string and then adds it to the reportData member.
        void formatData(string, string, int);
        //helper method for the compute() method, takes in a string representing the region an int reference as an output parameter for the highest number of animals
        //initially sets the subregion and max to default values, then retrieves the records for Horses-Ponies using the animalMap
        //then it iterates through the records finding records with the same region,in 2016, not in 'All' subregion and checks iif number of animals
        //is greater than max and sets max to that value, stores the subregion in a string variable. Returns a string of the subregion.
        string findSubRegionWithMax(string, int&);

};

#endif
