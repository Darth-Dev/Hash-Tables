#include <vector>
#include <string>
#include "bucket.h"
class hashTable{

    private:
        bool modulo, midSquare10, midSquare2, stringHashing, alder32;
        bool chaining, linearProbing, quadraticProbing, doubleHashing;
        std::vector<int> tableBuckets;
        std::vector<std::string> stringBuckets;
        bucket* head;

    public:
        void cleanKey(std::string*);
        void collision(int,int);
        int stringHash();
        int modHash(int*);
        void deleteBucket();
        void searchTable();
        void printTable();
        void initializeTable(std::vector<int>);
        void initializeTable(std::vector<std::string>);
        void initializeTable(std::vector<bucket>);
        int getTableSize();
        void insert(int);
        void printConfiguration();
        hashTable(int,int);
       
};