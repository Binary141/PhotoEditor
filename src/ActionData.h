#ifndef ActionData_H
#define ActionData_H

#include<iostream>
#include "PPM.h"
#include "NumberGrid.h"
//#include "image_menu.h"
#include "ActionData.h"

class ActionData{
    public: 
        ActionData(std::istream& is, std::ostream& os);
        std::istream& getIS();
        std::ostream& getOS();
        PPM& getInputImage1();
        PPM& getInputImage2();
        PPM& getOutputImage();
        bool getDone() const;
        void setDone();
        ~ActionData();
        NumberGrid& getGrid();
        void setGrid(NumberGrid *grid);
        ColorTable& getTable();


    private:
        std::istream& mInStream;
        std::ostream& mOutStream;
        PPM mImageOne;
        PPM mImageTwo;
        PPM mOImage;
        bool mQuit;
        NumberGrid* mGrid;
        ColorTable mTable;
};

#endif