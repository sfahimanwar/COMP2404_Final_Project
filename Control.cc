#include "Control.h"

using namespace std;

Control::Control() {
    ReportForRegionPercent* reportForRegionPercent = new ReportForRegionPercent(new DescBehaviour<float>);
    ReportForAnimalPercent* reportForAnimalPercent = new ReportForAnimalPercent(new AscBehaviour<float>);
    ReportForHighestSubregion* reportForHighestSubregion = new ReportForHighestSubregion(new DescBehaviour<int>);
    reportGenerators.push_back(reportForRegionPercent);
    reportGenerators.push_back(reportForAnimalPercent);
    reportGenerators.push_back(reportForHighestSubregion);
}

Control::~Control() {
    for(int i = 0; i < reportGenerators.size(); ++i){
        delete reportGenerators[i];
    }
}

void Control::launch() {
    cout << "Loading data from file" << endl;
    reportGenerators[0]->loadData();
    int choice;
    while(true){
        view.showMenu(choice);
        if(choice == 0){
            cout << "GOODBYE" << endl;
            break;
        }else if(choice == 1){
            reportGenerators[0]->compute();
            reportGenerators[0]->printReport();
        }else if(choice == 2){
            reportGenerators[1]->compute();
            reportGenerators[1]->printReport();
        }else if(choice == 3){
            reportGenerators[2]->compute();
            reportGenerators[2]->printReport();
        }
    }
    reportGenerators[0]->cleanup();
}
