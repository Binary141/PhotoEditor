#ifndef _ThreadedGrid_H_
#define _ThreadedGrid_H_

#include "NumberGrid.h"
#include "ThreadedVector.h"
#include <thread>

class SplitIndex{ 

private:
    int mRow;
    int mColumn;

public:
    SplitIndex();
    SplitIndex(int row, int column);
    ~SplitIndex();
    int getRow();
    int getColumn();
};

class ThreadedGrid : public NumberGrid
{
private:
    
    ThreadedVector<int> mVec; 
    ThreadedVector<SplitIndex> mPPMVec;

public:
    ThreadedGrid();
    ThreadedGrid(const int& height, const int& width);
    virtual ~ThreadedGrid();
    virtual void calculateAllNumbers();
    virtual void worker();

    virtual void setPPM( PPM& ppm, const ColorTable& ct ); // test 4
    virtual void workerSetPPM(PPM& ppm, const ColorTable& ct); //test 4
};


class Tworker // legacy code i am afraid to remove
{
private:
    std::vector<int> mRowVec;


public:
    Tworker(/* args */);
    ~Tworker();
    int getRow();
};










#endif