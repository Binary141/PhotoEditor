#include "ThreadedGrid.h"


ThreadedGrid::ThreadedGrid():
NumberGrid(){
    // for(int i = 0; i<getHeight(); i++){
    //     mVec.push_back(i);
    // }
}

ThreadedGrid::ThreadedGrid(const int& height, const int& width):
NumberGrid(height,width){
    // for(int i = 0; i<getHeight(); i++){
    //     mVec.push_back(i);
    // }
}

ThreadedGrid::~ThreadedGrid(){

}

void ThreadedGrid::calculateAllNumbers(){
    std::vector<std::thread> Threads;
    unsigned int cores = std::thread::hardware_concurrency();

    for(int i = 0; i<getHeight(); i++){
        mVec.push_back(i);
    }

    for(unsigned int i = 0; i<cores; i++){
        try {
            Threads.push_back(std::thread(&ThreadedGrid::worker,this));
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        
        //Threads.push_back(std::thread(&ThreadedGrid::worker,this));
    }

    for(long unsigned int i = 0; i<Threads.size(); i++){
        Threads[i].join();
    }

}

void ThreadedGrid::worker(){
    std::vector<int> jobs;
     

    while(mVec.size()> 0){
        jobs.resize(0);
        mVec.pop_back(jobs,2);

        //std::cout << mVec.size() << std::endl;

        for(long unsigned int i =0; i<jobs.size(); i++){        //segmentation fault will not be thrown to the main thread
                int row = jobs[i];
                //std::cout << row << std::endl;
                for(int col = 0; col<getWidth(); col++){
                    int num = calculateNumber(row,col);
                    //std::cout <<" start of line "<< row << " " << num << " end of line "<<std::endl;
                    setNumber(row,col,num);
                }
            }
    }
}






void ThreadedGrid::setPPM( PPM& ppm, const ColorTable& colors ){ // test 4

    


    if(colors.getNumberOfColors()<2){
        return;
    } 

    ppm.setHeight(getHeight());
    ppm.setWidth(getWidth());
    ppm.setMaxColorValue(colors.getMaxChannelValue());

    std::vector<std::thread> Threads;
    unsigned int cores = std::thread::hardware_concurrency();

    for(int i = 0; i< ppm.getHeight(); i++){
        for(int j = 0; j <ppm.getWidth(); j++){
            mPPMVec.push_back(SplitIndex(i,j));                          //<-----------------this is where the jobs are assigned
        }
    }
    for(unsigned int i = 0; i<cores; i++){
        try {
            Threads.push_back(std::thread(&ThreadedGrid::workerSetPPM,this, std::ref(ppm), std::ref(colors)) );
            //threads.push_back( std::thread(&ThreadedGrid::workerSetPPM, this, std::ref(ppm), std::ref(ct)) );
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        
    }

    for(long unsigned int i = 0; i<Threads.size(); i++){
        Threads[i].join();
    }


}

void ThreadedGrid::workerSetPPM(PPM& ppm, const ColorTable& colors){ //test 4



            std::vector<SplitIndex> jobs;
     

        while(mPPMVec.size()> 0){
            jobs.resize(0);
            mPPMVec.pop_back(jobs,200);

            //std::cout << mVec.size() << std::endl;

            for(long unsigned int i =0; i<jobs.size(); i++){        //segmentation fault will not be thrown to the main thread
                    int red;
                    int green;
                    int blue;

                    int row = jobs[i].getRow();
                    int column = jobs[i].getColumn();

                    if( getNumber(row,column)   == getMaxNumber()){
                        red = colors[colors.getNumberOfColors()-1].getRed();
                        green = colors[colors.getNumberOfColors()-1].getGreen();
                        blue = colors[colors.getNumberOfColors()-1].getBlue();
                    } else{
                        red = colors[getNumber(row,column) %colors.getNumberOfColors()].getRed(); //gets the red channel of colors at index mGrid mod size of colors
                        green = colors[getNumber(row,column) %colors.getNumberOfColors()].getGreen();//gets the Green channel of colors at index mGrid mod size of colors
                        blue = colors[getNumber(row,column) %colors.getNumberOfColors()].getBlue();//gets the blue channel of colors at index mGrid mod size of colors
                    }
                    

                    ppm.setPixel(row,column,red,green,blue);
                
        }


    

        }   
        
    


}


SplitIndex::SplitIndex(){

}

SplitIndex::SplitIndex(int row, int column){
    mRow = row;
    mColumn = column;
}

SplitIndex::~SplitIndex()
{
}
int SplitIndex::getRow(){
    return mRow;
}

int SplitIndex::getColumn(){
    return mColumn;
}
