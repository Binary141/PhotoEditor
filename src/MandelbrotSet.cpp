#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet() 
: ComplexFractal(){

}

MandelbrotSet::MandelbrotSet(const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y)
: ComplexFractal(height,width,min_x,max_x,min_y,max_y) {

}

MandelbrotSet::~MandelbrotSet(){

}

void MandelbrotSet::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const{
    x1 = x0*x0 - y0*y0 + a;
    y1 = 2*x0*y0 + b;
}

int MandelbrotSet::calculatePlaneEscapeCount( const double& a, const double& b ) const{
    double x0,x1,y0,y1;
    x0 = a;
    y0 = b;
    
    
     if(std::pow((x0),2)+ std::pow((y0),2) > 4 ){
        return 0;
    }

    for(int count = 1; count <getMaxNumber();count++) {
        calculateNextPoint(x0,y0,a,b,x1,y1);

        //std::cout << startX<< " " << startY << " " << x1 << " " << y1 << std::endl;

        if(std::pow((x1),2)+ std::pow((y1),2) > 4 ){
            return count;
        }
        x0 = x1;
        y0 = y1;
    }
    return getMaxNumber();
}

int MandelbrotSet::calculateNumber( const int& row, const int& column ) const{
    if(row<0 || row>=getHeight()|| column<0 || column>=getWidth()){
        return -1;
    }

    double x;
    double y;
    calculatePlaneCoordinatesFromPixelCoordinates(row,column,x,y);
    return calculatePlaneEscapeCount(x,y);  
}


MandelbrotPower::MandelbrotPower() 
: MandelbrotSet(), mPower(2.0){

}
MandelbrotPower::~MandelbrotPower(){

}
double MandelbrotPower::getPower( ) const{
    return mPower;
}
void MandelbrotPower::setPower( const double& power ){
    mPower = power;
}
void MandelbrotPower::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const{

    double r = sqrt( x0*x0 + y0*y0 );
    double theta = atan2( y0, x0 );
    x1 = (std::pow(r , getPower())) * cos( getPower() * theta ) + a;
    y1 = (std::pow(r , getPower())) * sin( getPower() * theta ) + b;

}
