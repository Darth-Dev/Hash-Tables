#include "hashTable.h"
#include <iostream>
using namespace std;

void hashTable::deleteBucket(){
    int deleteValue;
    cout << "Enter value to search for in hash table: ";
    cin >> deleteValue;

    for (size_t i = 0; i < tableBuckets.size(); i++){
        if (tableBuckets.at(i) == deleteValue){
            tableBuckets.at(i) == -1;
            cout << "Deleted value " << deleteValue << " from bucket #" << i << endl;
        }
        else{
            cout << "Value to delete was no found.\n";
        }
    }
}

void hashTable::searchTable(){
    int searchValue;
    cout << "Enter value to search for in hash table: ";
    cin >> searchValue;

    for (size_t i = 0; i < tableBuckets.size(); i++){
        if (tableBuckets.at(i) == searchValue){
            cout << "Search found " << searchValue << " in bucket #" << i << endl;
        }
        else{
            cout << "Search found no results.\n";
        }
    }
}

void hashTable::printTable(){
    for (size_t i = 0; i < tableBuckets.size(); i++){
        cout << i << ": " << tableBuckets.at(i) << endl;
    }
}

void hashTable::initializeTable(vector<int> initialValues){
    cout << "initializing table...\n";
    for (size_t i = 0; i < initialValues.size(); i++){
        tableBuckets.push_back(initialValues.at(i));
        cout << initialValues.at(i) << " - " << tableBuckets.at(i) << endl;
    }
    cout << endl;
    
}

int hashTable::getTableSize(){
    return tableBuckets.size();
}

void hashTable::insert(int hashVal){
    int hashIndex = hashVal % getTableSize();
    cout << hashIndex << endl;
    if (modulo){
        cout << "Value: " << hashVal << " inserted into index " << hashIndex << " of " << getTableSize() << endl;
        tableBuckets.at(hashIndex) = hashVal;                   
    }
    
}

void hashTable::printConfiguration(){

    if (modulo){
        cout << "Hashing method is set to modulo hashing.\n"; 
    }
    else if(midSquare10){
        cout << "Hashing method is set to mid-square base 10 hashing.\n";
    }
    else if(midSquare2){
        cout << "Hashing method is set to mid-square base 2 hashing.\n";
    }
    else if(stringHashing){
        cout << "Hashing method is set to multiplicative string hashing.\n";
    }
    else if(alder32){
        cout << "Hashing method is set to alder 32 hashing.\n";
    }

    if (chaining){
        cout << "Collision strategy is set to chaining.\n";
    }
    else if (linearProbing){
        cout << "Collision strategy is set to linear probing.\n";
    }
    else if (quadraticProbing){
        cout << "Collision strategy is set to quadratic probing.\n";
    }
    else if(doubleHashing){
        cout << "Collision strategy is set to double hashing.\n";
    } 
}

hashTable::hashTable(int hashOption, int collisionOption){

    if (hashOption == 1){
        modulo = true;
        midSquare10 = false;
        midSquare2 = false;
        stringHashing = false;
        alder32 = false;
    }
    else if(hashOption == 2){
        modulo = false;
        midSquare10 = true;
        midSquare2 = false;
        stringHashing = false;
        alder32 = false;
    }
    else if(hashOption == 3){
        modulo = false;
        midSquare10 = false;
        midSquare2 = true;
        stringHashing = false;
        alder32 = false;
    }
    else if(hashOption == 4){
        modulo = false;
        midSquare10 = false;
        midSquare2 = false;
        stringHashing = true;
        alder32 = false;
    }
    else if(hashOption == 5){
        modulo = false;
        midSquare10 = false;
        midSquare2 = false;
        stringHashing = false;
        alder32 = true;
    }

    if(collisionOption == 1){
        chaining = true;
        linearProbing = false;
        quadraticProbing = false;
        doubleHashing = false;
    }
    else if (collisionOption == 2){
        chaining = false;
        linearProbing = true;
        quadraticProbing = false;
        doubleHashing = false;
    }
    else if (collisionOption == 3){
        chaining = false;
        linearProbing = false;
        quadraticProbing = true;
        doubleHashing = false;
    }
    else if (collisionOption == 4){
        chaining = false;
        linearProbing = false;
        quadraticProbing = false;
        doubleHashing = true;
    }
}