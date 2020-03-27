#include <vector>
class hashTable{

    private:
        bool modulo, midSquare10, midSquare2, stringHashing, alder32;
        bool chaining, linearProbing, quadraticProbing, doubleHashing;
        std::vector<int> tableBuckets;

    public:
        void collision(int,int);
        int stringHash();
        int modHash(int*);
        void deleteBucket();
        void searchTable();
        void printTable();
        void initializeTable(std::vector<int>);
        int getTableSize();
        void insert(int);
        void printConfiguration();
        hashTable(int,int);
       
};