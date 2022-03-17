#include "JuliaSet.h"

JuliaSet::JuliaSet() 
: ComplexFractal(), mA(-0.650492), mB(-0.478235) {
    
    setMaxNumber(255);
}

JuliaSet::JuliaSet(const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y, const double& a, const double& b )
    : ComplexFractal(height,width,min_x,max_x,min_y,max_y), mA(a), mB(b) {
}

JuliaSet::~JuliaSet(){

}

double JuliaSet::getA() const{
    return mA;
}

double JuliaSet::getB() const{
    return mB;
}

void JuliaSet::setParameters(const double& a, const double& b){
    if(a<-2 || a>2 || b<-2 || b>2){
        return;
    }
    mA = a;
    mB = b;
}

void JuliaSet::calculateNextPoint(const double x0, const double y0, double& x1, double &y1) const{
    x1 = x0*x0 -y0*y0 + mA;
    y1 = 2*y0*x0 + mB;

}

int JuliaSet::calculatePlaneEscapeCount(const double& x0, const double& y0) const{
    
    double x1;
    double y1;

    double startX = x0;
    double startY = y0;

    if(std::pow((x0),2)+ std::pow((y0),2) > 4 ){
        return 0;
    }

    for(int count = 1; count <getMaxNumber();count++) {
        calculateNextPoint(startX,startY,x1,y1);

        //std::cout << startX<< " " << startY << " " << x1 << " " << y1 << std::endl;

        if(std::pow((x1),2)+ std::pow((y1),2) > 4 ){
            return count;
        }
        startX = x1;
        startY = y1;
    }
    return getMaxNumber();
}

int JuliaSet::calculateNumber(const int& row, const int& column) const{

    if(row<0 || row>=getHeight()|| column<0 || column>=getWidth()){
        return -1;
    }

    double x;
    double y;
    calculatePlaneCoordinatesFromPixelCoordinates(row,column,x,y);
    return calculatePlaneEscapeCount(x,y);  
}