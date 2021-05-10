#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "CompareBehaviour.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"

//Templated class for type T that contains the results for one report, organized as an ordered collection
//of keys and formatted strings that each represent one row in the report.

template <class T>
class ReportData{
    template <class U>
    friend ostream& operator<<(ostream&, ReportData<U>&); //overloaded stream insertion operator that iterates through the collection of rows and outputs them

    public:
        //Constructor that takes in a CompareBehaviour pointer and sets the variable
        ReportData(CompareBehaviour<T>*);
        ~ReportData(); //deallocates the CompareBehaviour pointer
        //Takes in a key of type T and a string row, iterates through the rowCollection to find correct insertion point using the CompareBehaviour object
        //inserts the ReportRow using the key and string row once position is found
        void add(T, string);
        void clear(); //clears the rowCollection

    private:
        //nested class that represents a row in the ReportData
        class ReportRow{
            public:
                T key; // key which is used for ordering of the rows in ReportData
                string row;
                ReportRow(T key, string row){
                    this->key = key;
                    this->row = row;
                }
        };
        vector<ReportRow> rowCollection;
        CompareBehaviour<T>* compare; // CompareBehaviour object pointer, decides the ordering of the ReportRows in ReportData

};

template <class T>
ostream& operator<<(ostream& output, ReportData<T>& r){
    for(int i = 0; i < r.rowCollection.size(); ++i){
        output << r.rowCollection.at(i).row << endl;
    }
    return output;
}

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c) {
    compare = c;
}

template <class T>
ReportData<T>::~ReportData<T>() {
    delete compare;
}

template <class T>
void ReportData<T>::add(T key, string row) {
    if(rowCollection.size() == 0){
        rowCollection.push_back(ReportRow(key, row));
        return;
    }
    typename vector<ReportRow>::iterator itr;
    bool added = false;
    for(itr = rowCollection.begin(); itr != rowCollection.end(); ++itr){
        if(compare->compare((*itr).key, key)){
            rowCollection.insert(itr,ReportRow(key, row));
            added = true;
            break;
        }
    }
    if(!added){
        rowCollection.push_back(ReportRow(key, row));
    }
}

template <class T>
void ReportData<T>::clear() {
    rowCollection.clear();
}

#endif
