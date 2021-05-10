#ifndef ASCBEHAVIOUR_H
#define ASCBEHAVIOUR_H

#include <string>
#include <iostream>
#include <iomanip>
#include "CompareBehaviour.h"

using namespace std;

//Part of an inheritance hierarchy comparison behaviour class templates which includes polymorphic behaviour
//Concrete derive class which inherits from CompareBehaviour, orders in ascending order, templated for type T

template <class T>
class AscBehaviour: public CompareBehaviour<T>{
    public:
        //Polymorphic function, takes in two values of type T, returns true if value 1 is greater than value 2 else false
        virtual bool compare(T, T);
};

template <class T>
bool AscBehaviour<T>::compare(T v1, T v2) {
    if(v1 > v2){
        return true;
    }
    return false;
}

#endif
