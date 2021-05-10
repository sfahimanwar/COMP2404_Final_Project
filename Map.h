#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>
using namespace std;
#include <iomanip>
#include <vector>
#include "Record.h"

//A templated collection class that stores keys of type T and vectors of Record pointers as keys

template <class T>
class Map{
    public:
        //adds the given Record pointer to the vector that corresponds to the given key, uses the overloaded subscript operator
        //uses a try-catch block to check if key exists, adds it if key exist, if it doesn't, it adds the new key to keyCollection and then adds the Record
        void add(T key, Record* rec);
        int getSize(); // returns the size of the keyCollection which is the same size as the value collection
        vector<T>& getKeyCollection(); // returns a reference to the keyCollection
        //Overloaded subscript operator, takes in a key parameter of type T
        //Iterates through the keyCollection, when it finds a match, returns the matching value from the valueCollection
        //throws an exception if it doesn't find a matching key
        vector<Record*>& operator[](T);

    private:
        vector<T> keyCollection; // collection of keys of the Map of type T
        vector<vector<Record*> > valueCollection; // vector of vectors of Record pointers

};

template <class T>
int Map<T>::getSize() {
    return keyCollection.size();
}

template <class T>
vector<T>& Map<T>::getKeyCollection() {
    return keyCollection;
}

template <class T>
vector<Record*>& Map<T>::operator[](T key) {
    for(int i = 0; i < keyCollection.size(); ++i){
        if(keyCollection[i] == key){
            return valueCollection[i];
        }
    }
    throw "Key not found";
}


template <class T>
void Map<T>::add(T key, Record *rec) {
    try{
        (*this)[key].push_back(rec);
    }catch(...) {
        keyCollection.push_back(key);
        vector<Record*> newCollection;
        newCollection.push_back(rec);
        valueCollection.push_back(newCollection);
    }
}

#endif
