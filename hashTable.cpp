#include "hashTable.h"
#include <iostream>
#include <cmath>
using namespace std;

void hashTable::collision(int hashIndex, int hashVal){

    if (chaining){
        /* code */
    }

    if (linearProbing){
        for (int i = hashIndex; i < tableBuckets.size(); i++){
            if (tableBuckets.at(i) == 0){
                tableBuckets.at(i) = hashVal;
                cout << "Collision resolved.\n";
                break;
            }
            else if(tableBuckets.at(i) != 0 && tableBuckets.at(i) == tableBuckets.size()){
                //resize table and insert
            }
        }
        
    }
    
    
}

int hashTable::stringHash(){
    const int constVal = 2;
    int hashVal=0;

    for (size_t i = 0; i < tableBuckets.size(); i++){
        hashVal = hashVal + (pow(constVal, i) * static_cast<int>(tableBuckets[i]));
    }

    return hashVal;
}

int hashTable::modHash(int* value){
    return *value % getTableSize();
}

void hashTable::deleteBucket(){
    int deleteValue;
    cout << "Enter value to search for in hash table: ";
    cin >> deleteValue;

    for (size_t i = 0; i < tableBuckets.size(); i++){
        if (tableBuckets.at(i) == deleteValue){
            tableBuckets.at(i) = 0;
            cout << "Deleted value " << deleteValue << " from bucket #" << i << endl;
        }
        else if(tableBuckets.at(i) != deleteValue && i == tableBuckets.size()){
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
        else if(tableBuckets.at(i) != searchValue && i == tableBuckets.size()){
            cout << "Search found no results.\n";
        }
    }
}

void hashTable::printTable(){
    for (size_t i = 0; i < tableBuckets.size(); i++){
        cout << i << ": " << tableBuckets.at(i) << "\t";
    }
    cout << endl;
}

void hashTable::initializeTable(vector<int> initialValues){
    cout << "Initializing table...\n";
    for (size_t i = 0; i < initialValues.size(); i++){
        tableBuckets.push_back(initialValues.at(i));
    }
}

int hashTable::getTableSize(){
    return tableBuckets.size();
}

void hashTable::insert(int hashVal){

    if (modulo){

        int hashIndex;
        hashIndex = modHash(&hashVal);

        if(tableBuckets.at(hashIndex) != 0){
            collision(hashIndex, hashVal);
        }
        else{
            tableBuckets.at(hashIndex) = hashVal;
            cout << "Value: " << hashVal << " inserted into index " << hashIndex << " of " << getTableSize() << endl;
        }
    }

    if (midSquare10){
        /* code */
    }
 
    if (midSquare2){
        /* code */
    }
    
    
    if (stringHashing){
        /* code */
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