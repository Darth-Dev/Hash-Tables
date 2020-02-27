#include <iostream>
using namespace std;

int main(){
    int hashChoice, collisionChoice;
    cout << "Type a number to select a hashing function.\n1. Modulo hashing\n2. Mid-square base 10 hashing\n3. Mid-square base 2 hashing\n4. Multiplicative string hashing\n5. Alder 32 hashing\n";
    cin >> hashChoice;
    cout << "Type a number to select a collision strategy.\n1. Chaining\n2. Linear probing\n3. Quadratic probing\n4. Double hashing\n";
    cin >> collisionChoice;

    switch (hashChoice){
        case 1:
            //set hashing function to modulo hashing
        break;

        case 2:
            //set hashing function to Mid-square base 10 hashing
        break;

        case 3:
            //set hashing function to Mid-square base 2 hashing
        break;
        
        case 4:
            //set hashing function to Multiplicative string hashing
        break;

        case 5:
            //set hashing function to Alder 32 hashing
        break;
    
        default:
        break;
    }

    switch (collisionChoice){
        case 1:
            //set hashing function to modulo hashing
        break;

        case 2:
            //set hashing function to Mid-square base 10 hashing
        break;

        case 3:
            //set hashing function to Mid-square base 2 hashing
        break;
        
        case 4:
            //set hashing function to Multiplicative string hashing
        break;

        case 5:
            //set hashing function to Alder 32 hashing
        break;
    
        default:
        break;
    }

    //read in data and run hashing and collision configuration
    //prompt for search insert delete and execute
    return 0;
}