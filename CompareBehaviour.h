#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

//Abstract class that is part of an inheritance hierarchy of comparison behaviour class templates which includes polymorphic behaviour

template <class T>
class CompareBehaviour{
    public:
        virtual bool compare(T, T) = 0; // pure virtual function for comparison of two values
        virtual ~CompareBehaviour(); //virtual destructor
};

template <class T>
CompareBehaviour<T>::~CompareBehaviour<T>() {}

#endif
