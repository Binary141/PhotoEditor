#include "NumberGrid.h"


NumberGrid::NumberGrid() :
mHeight(300), mWidth(400), mMax(255), mGrid(mHeight*mWidth) { 
    
}

NumberGrid::NumberGrid( const int& height, const int& width ):
mHeight(height), mWidth(width), mMax(255), mGrid(mHeight*mWidth){

}

NumberGrid::~NumberGrid(){

}

int NumberGrid::getHeight() const{
    return mHeight;
}

int NumberGrid::getWidth() const {
    return mWidth;
}

int NumberGrid::getMaxNumber() const{
    return mMax;
}

void NumberGrid::setGridSize(const int& height, const int& width ){
    if(height >= 2 && width >= 2){
        mHeight = height;
        mWidth = width;
        mGrid.resize(mHeight*mWidth);
    }
}

void NumberGrid::setMaxNumber(const int& number){
    if(number>0){
        mMax = number;
    }
}

const std::vector< int >& NumberGrid::getNumbers( ) const{
    return mGrid;
}

int NumberGrid::index( const int& row, const int& column ) const{
    return row*mWidth + column;
}

bool NumberGrid::indexValid( const int& row, const int& column ) const{
    //return row<=mHeight && column <= mWidth
    if( row >= getHeight() || row<0 || column >= getWidth() || column <0){
        return false;
    } else {
        return true;
    };
}

bool NumberGrid::numberValid( const int& number ) const{
    return number>=0 && number<=mMax;
}

int NumberGrid::getNumber( const int& row, const int& column ) const{
    if(indexValid(row,column)){
        return mGrid[index(row,column)];
    } else{
        return -1;
    }
}

void NumberGrid::setNumber( const int& row, const int& column, const int& number ){
    
    if(indexValid(row,column) && numberValid(number)){
    

        mGrid[index(row,column)] = number;
    } 
}

void NumberGrid::setPPM( PPM& ppm ) const{
    ppm.setHeight(mHeight);
    ppm.setWidth(mWidth);
    ppm.setMaxColorValue(63);

    int tempNum;

    for(int i =0; i<mHeight; i++){
        for(int j = 0; j<mWidth; j++){
            tempNum = getNumber(i,j);
            if(tempNum == 0){
                ppm.setPixel(i,j,0,0,0);
            } else if ( tempNum == mMax){
                ppm.setPixel(i,j, 63,31,31);
            } else if( tempNum % 8 == 0){
                ppm.setPixel(i,j,63,63,63);
            } else if( tempNum % 8 == 1){
                ppm.setPixel(i,j,63,31,31);
            } else if( tempNum % 8 == 2){
                ppm.setPixel(i,j,63,63,31);
            } else if( tempNum % 8 == 3){
                ppm.setPixel(i,j,31,63,31);
            } else if( tempNum % 8 == 4){
                ppm.setPixel(i,j,0,0,0);
            } else if(tempNum % 8 == 5){
                ppm.setPixel(i,j,31,63,63);
            } else if(tempNum % 8 == 6){
                ppm.setPixel(i,j,31,31,63);
            } else if(tempNum % 8 == 7){
                ppm.setPixel(i,j,63,31,63);
            }
        }
    }
}

void NumberGrid::setPPM(PPM& ppm, const ColorTable& colors) {
    if(colors.getNumberOfColors()<2){
        return;
    }

    ppm.setHeight(mHeight);
    ppm.setWidth(mWidth);
    ppm.setMaxColorValue(colors.getMaxChannelValue());

    for(int i = 0; i< ppm.getHeight(); i++){
        for(int j = 0; j <ppm.getWidth(); j++){

            int red;
            int green;
            int blue;

            if(mGrid[index(i,j)] == getMaxNumber()){
                red = colors[colors.getNumberOfColors()-1].getRed();
                green = colors[colors.getNumberOfColors()-1].getGreen();
                blue = colors[colors.getNumberOfColors()-1].getBlue();
            } else{
                red = colors[mGrid[index(i,j)] %colors.getNumberOfColors()].getRed(); //gets the red channel of colors at index mGrid mod size of colors
                green = colors[mGrid[index(i,j)] %colors.getNumberOfColors()].getGreen();//gets the Green channel of colors at index mGrid mod size of colors
                blue = colors[mGrid[index(i,j)] %colors.getNumberOfColors()].getBlue();//gets the blue channel of colors at index mGrid mod size of colors
            }
            

            ppm.setPixel(i,j,red,green,blue);
        }
    }
}

void NumberGrid::calculateAllNumbers(){
    for(int i = 0; i<getHeight(); i++){
        for(int j = 0; j<getWidth(); j++){
            int calc = calculateNumber(i,j);
            setNumber(i,j,calc);
        }
    }
}