#include <iostream>
#include <string>
#include "hashTable.h"
using namespace std;

int main(){
    int hashChoice, collisionChoice, hashValue, choice, it=0;
    string input;
    vector<int> initialInts(50);
    vector<string> initialStrings(50); 

    do{
    cout << "Type a number to select a hashing function.\n1. Modulo hashing\n2. Mid-square base 10 hashing\n3. Mid-square base 2 hashing\n4. Multiplicative string hashing\n5. Alder 32 hashing\n";
    cin >> hashChoice;
    cout << "Type a number to select a collision strategy.\n1. Chaining\n2. Linear probing\n3. Quadratic probing\n4. Double hashing\n";
    cin >> collisionChoice;
    }while (!(hashChoice>0 && hashChoice<=5) || !(collisionChoice>0 && collisionChoice<=4));

    

    hashTable table(hashChoice, collisionChoice);
    table.printConfiguration();

    if (collisionChoice == 1){      //if chaining
        cout << "Enter integer values separated by a space to populate the hash table, enter -1 to exit: ";
            while (cin >> hashValue){

                if (hashValue == -1){
                    break;
                }
                bucket* newBucket = new bucket(hashValue);
                table.insert(hashValue);
            }
    }
    

    if (collisionChoice =! 1){          //not chaining
        table.initializeTable(initialInts);
    }
    
    if (hashChoice == 4){           //if string hashing
            table.initializeTable(initialStrings);
    }
    
    if (collisionChoice != 1 || hashChoice == 4)        //if not chaining or string hashing
    {
        cout << "Enter integer values separated by a space to populate the hash table, enter -1 to exit: ";
            while (cin >> hashValue){

            if (hashValue == -1){
                break;
            }
            table.insert(hashValue); 
    }
    }

    do{
        cout << "Enter a number 1-4 to perform an action. Press 0 to exit.\n" << "0: Exit\n1: Insert\n2. Search\n3. Delete\n4. Print\n";
        cin >> choice;
        switch (choice){
        
            case 0:
                return 0;
                break;

            case 1:
                cout << "Enter a value to insert into the hash table.\n";
                cin >> hashValue; 
                table.insert(hashValue);
                break;

            case 2:
                table.searchTable();
                break;

            case 3:
                table.deleteBucket();
                break;
            
            case 4:
                table.printTable();
                break;    
            
            default:
                break;
        }
    }while(choice != 0);

    return 0;
}