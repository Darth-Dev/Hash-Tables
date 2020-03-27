#include "bucket.h"
#include <iostream>
using namespace std;

bucket::bucket(int Index){
    index = Index;
    nextBucket = nullptr;
}
    
void bucket::setNext(bucket* next){
    nextBucket = next;
}

bucket* bucket::getNext(){
    return nextBucket;
}

void bucket::setIndex(int Index){
    index = Index;
}

int bucket::getIndex(){
    return index;
}

void bucket::printData(){
    cout << index;
}