#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

#include "Record.h"
#include "Map.h"

//A control object abstract class that is part of an inheritance hierarchy of control object classes that compute and generate reports

class ReportGenerator{

    public:
        //static function that reads in data from the farm.dat file, creates Record objects using the data and pushes them
        //to the primaryCollection of Record pointers, then it iterates through all the records and populates all three Map objects
        static void loadData();
        virtual void compute() = 0; //pure virtual function implemented by the derived classes
        void cleanup(); //deallocates all the Record objects in the primaryCollection
        virtual ~ReportGenerator();
        virtual void printReport() = 0; // pure virtual function implemented by the derived classes

    protected:
        static vector<Record *> primaryCollection;
        static Map<int> yearMap; //Map object with the years as keys
        static Map<string> regionMap; //Map object with the regions as keys
        static Map<string> animalMap; //Map object with the animalType as keys


};

#endif
