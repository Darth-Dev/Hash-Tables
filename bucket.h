class bucket{
private:
    int index;
    bucket *nextBucket;
public:
    bucket(int);
    void setNext(bucket*);
    bucket* getNext();
    void setIndex(int);
    int getIndex();
    void printData();
};
