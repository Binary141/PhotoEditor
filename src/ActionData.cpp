#include "ActionData.h"
//#include "image_menu.h"



ActionData::ActionData(std::istream& is, std::ostream& os) 
   : mInStream(is), mOutStream(os), mTable(16){
       mQuit = false;
       mGrid = 0;

       
       Color c1 = Color(0,255,0);
       Color c2 = Color(255,0,255);
    
       mTable.insertGradient(c1,c2,0,15);
}

std::istream& ActionData::getIS( ){
    return mInStream;
}

std::ostream& ActionData::getOS( ){
    return mOutStream;
}

PPM& ActionData::getInputImage1( ){
    return mImageOne;
}

PPM& ActionData::getInputImage2( ){
    return mImageTwo;
}

PPM& ActionData::getOutputImage( ){
    return mOImage;
}

bool ActionData::getDone() const{
    return mQuit;
}

void ActionData::setDone( ){
    mQuit = true;
}

ActionData::~ActionData(){
    if(mGrid != 0){
        delete mGrid;
    }
}

NumberGrid& ActionData::getGrid(){
    return *mGrid;
}

void ActionData::setGrid(NumberGrid *grid){
    if( mGrid != 0){
        delete mGrid;
    }
    mGrid = grid;
}   
ColorTable& ActionData::getTable(){
    return mTable;
}