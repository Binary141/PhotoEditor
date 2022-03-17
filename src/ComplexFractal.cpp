#include "ComplexFractal.h"


ComplexFractal::ComplexFractal()
 : ThreadedGrid(200,300), mMin_x(-1.5), mMax_x(1.5), mMin_y(-1), mMax_y(1),mDeltax(0.01), mDeltay(0.01) {

    }

ComplexFractal::ComplexFractal( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y )
: ThreadedGrid(height,width), mMin_x(min_x), mMax_x(max_x), mMin_y(min_y), mMax_y(max_y) {

    mDeltax = (max_x - min_x) / (width - 1);
    mDeltay = (max_y - min_y) / (width - 1);
}

ComplexFractal::~ComplexFractal( ){

}
double ComplexFractal::getMinX( ) const{
    return mMin_x;
}

double ComplexFractal::getMaxX( ) const {
    return mMax_x;
}

double ComplexFractal::getMinY( ) const {
    return mMin_y;
}

double ComplexFractal::getMaxY( ) const {
    return mMax_y;
}

void ComplexFractal::setGridSize(const int& height, const int& width ){
    if(height <2 || width <2){
        return;
    }

    NumberGrid::setGridSize(height,width);
    double dx = calculateDeltaX();
    double dy = calculateDeltaY();
    setDeltas(dx,dy);
}

void ComplexFractal::setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y ){
    if(min_x<-2.0 || min_x>2.0 || max_x<-2.0 || max_x>2.0 || min_y<-2.0 || min_y>2.0 || max_y<-2.0 || max_y>2.0)
        return;
    
    if(min_x == max_x || min_y == max_y)
        return;
    

    if(min_x>max_x){
        mMax_x = min_x;
        mMin_x = max_x;
    } else{
        mMin_x = min_x;
        mMax_x = max_x;
    }

    if(min_y > max_y){
        mMin_y = max_y;
        mMax_y = min_y;
    } else{
        mMin_y = min_y;
        mMax_y = max_y;
    }

    double dx = calculateDeltaX();
    double dy = calculateDeltaY();
    setDeltas(dx,dy);
}

double ComplexFractal::getDeltaX( ) const{
    return mDeltax;
}

double ComplexFractal::getDeltaY( ) const {
    return mDeltay;
}

void ComplexFractal::setDeltas( const double& deltaX, const double& deltaY){
    if(deltaX>=0 && deltaY >= 0){
        mDeltax = deltaX;
        mDeltay = deltaY;
    }
}

double ComplexFractal::calculateDeltaY ( ) const{
    return (mMax_y - mMin_y) / (getHeight() - 1);
}

double ComplexFractal::calculateDeltaX( ) const {
    return (mMax_x - mMin_x) / (getWidth() -1);
}

double ComplexFractal::calculatePlaneXFromPixelColumn( const int& column ) const{
    if(column<0 || column>=getWidth()){
        
        return 0.0;
    }

    

    return mMin_x + getDeltaX() * column;
}

double ComplexFractal::calculatePlaneYFromPixelRow( const int& row ) const{
    if(row<0 || row>=getHeight()){
        return 0.0;
    }

    return mMax_y - getDeltaY() * row;
}

void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const{
    
    if(row<0|| row>=getHeight() || column<0|| column>=getWidth()){
        x =0;
        y =0;
        return;
    }
    
    x = calculatePlaneXFromPixelColumn(column);
    
    y = calculatePlaneYFromPixelRow(row);
}

int ComplexFractal::calculateNumber( const int& row, const int& column ) const{
    if(row<0 || row>=getHeight() || column<0 || column>=getWidth()){
        return -1;
    }
    double x;
    double y;
    calculatePlaneCoordinatesFromPixelCoordinates(row,column,x,y);
    return std::abs(getMaxNumber() * std::sin(10*x) * std::cos(10*y));
}