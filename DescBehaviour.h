#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H

#include <string>
#include <iostream>
#include <iomanip>
#include "CompareBehaviour.h"

using namespace std;

//Part of an inheritance hierarchy comparison behaviour class templates which includes polymorphic behaviour
//Concrete derive class which inherits from CompareBehaviour, orders in descending order, templated for type T

template <class T>
class DescBehaviour: public CompareBehaviour<T>{
    public:
        //Polymorphic function, takes in two values of type T, returns true if value 1 is less than value 2 else false
        virtual bool compare(T, T);
};

template <class T>
bool DescBehaviour<T>::compare(T v1, T v2) {
    if(v1 < v2){
        return true;
    }
    return false;
}

#endif
