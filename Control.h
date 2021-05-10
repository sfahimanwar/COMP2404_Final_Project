#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

#include "ReportGenerator.h"
#include "ReportForRegionPercent.h"
#include "ReportForAnimalPercent.h"
#include "ReportForHighestSubregion.h"
#include "View.h"
#include "CompareBehaviour.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"

//Control class that controls the flow of the program

class Control{
    public:
        //Constructor that initializes 3 different ReportGenerator objects and adds them to the vector of ReportGenerator pointers
        Control();
        //Destructor that deallocates the ReportGenerator objects
        ~Control();
        //Controls main flow of the program, uses View object to show menu to users, and based on their choices, computes and generates different reports
        //Also uses the ReportGenerator objects to load data from farm.dat and also cleanup at the end
        void launch();

    private:
        View view; // View object used to display menu to users
        vector<ReportGenerator*> reportGenerators;

};

#endif
