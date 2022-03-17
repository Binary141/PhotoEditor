#include "PPM.h"

#include "iostream"


PPM::PPM( ): Image( ){
    max = 1;
    
}
PPM::PPM( const int& height, const int& width): Image(height,width) {
    max = 1;
   
}

int PPM::getMaxColorValue( ) const{
    return max;
}

bool PPM::valueValid(const int& value) const{

    if(value<0  || value>max){
        return false;
    } else{
        return true;
    }
}

void PPM::setMaxColorValue(const int& max_color_value){
    if(max_color_value<1 || max_color_value > 255){

    }  else{
        max = max_color_value;
    }
}

void PPM::setChannel(const int& row, const int& column, const int& channel, const int& value){
    //std::cout << row << "row " << column << "column  " << channel<< "channel "<< value<< "value " << getWidth() << "width " << getHeight() << "height ";
    
    if(valueValid(value)){
        Image::setChannel(row,column, channel, value);
    }
}

void PPM::setPixel(const int& row, const int& column, const int& red, const int& green, const int& blue){
    setChannel(row,column,0,red);
    setChannel(row,column,1,green);
    setChannel(row,column,2,blue);
}

void PPM::writeStream(std::ostream& os) const{
    
    os << "P6 "<< getWidth()<< " " << getHeight() << " "<< max<< "\n";

    unsigned int v;
    for(int i =0; i< getHeight(); i++){

        for (int j = 0; j< getWidth(); j++) {
            v = getChannel(i, j,0);

            //std::cout << " " << v << " ";

            os.write((char*)&v,1);
            
            v = getChannel(i, j,1);
            os.write((char*)&v,1);


            v = getChannel(i, j,2);
            os.write((char*)&v,1);
            }
        }

    }

void PPM::readStream(std::istream& is){

    unsigned char version;
    int i;
   
    //gets P
    is.read((char*)& version, 1);
    
    //gets 6
    is.read((char*)& version, 1);

    //gets width
    is >> i;
    setWidth(i);

    //gets height    
    is >> i;
    setHeight(i);

    //gets max color
    is >> i;
    setMaxColorValue(i);

    
    //gets the newLine char
    is.read((char*)& version,1);
    
    unsigned char r;
    unsigned char g;
    unsigned char b;

    

    for(int i =0; i< getHeight() && is.good(); i++){

        for (int j = 0; j< getWidth() && is.good(); j++) {

        is.read((char*)& r,1);
        is.read((char*)& g,1);
        is.read((char*)& b,1);

        setPixel(i,j,r,g,b);
        }
    }
}

       bool PPM::operator==(const PPM& rhs) const{
            return getHeight()*getWidth() == rhs.getWidth()* rhs.getHeight();
        }

        bool PPM::operator!=(const PPM& rhs) const{
            return getHeight()*getWidth() != rhs.getWidth() * rhs.getHeight();
        }

        bool PPM::operator<(const PPM& rhs) const{
            return getHeight()*getWidth() < rhs.getHeight() * rhs.getWidth();
        }

        bool PPM::operator<=(const PPM& rhs) const{
            return getHeight() * getWidth() <= rhs.getWidth() * rhs.getHeight();
        }
    
        bool PPM::operator>(const PPM& rhs) const{
            return getHeight() * getWidth() > rhs.getWidth() * rhs.getHeight();
        }

        bool PPM::operator>=(const PPM& rhs) const{
            return getHeight() * getWidth() >= rhs.getWidth() * rhs.getHeight();
        }

        PPM& PPM::operator+=(const PPM& rhs){
            
            int r;
            int g;
            int b;
            for(int i= 0; i<getHeight();i++){
                for(int j = 0; j<getWidth(); j++){
                    //finds what the red value should be
                    r = rhs.getChannel(i,j,0) + getChannel(i,j,0);
                    if(r<getMaxColorValue()){
                        
                    } else{
                        r = getMaxColorValue();
                    }

                    //finds what the green value should be
                    g = getChannel(i,j,1) + rhs.getChannel(i,j,1);
                    if(g<getMaxColorValue()){
                        
                    } else{
                        g = getMaxColorValue();
                    }
                     
                    // finds what the blue value should be
                    b = getChannel(i,j,2) + rhs.getChannel(i,j,2);
                    if(b<getMaxColorValue()){
                        
                    } else{
                        b = getMaxColorValue();
                    }

                    //takes the red, green, and blue values and sets the pixel value
                    setPixel(i,j,r,g,b);
                }
            }
            return *this;
        }
        
        PPM& PPM::operator-=(const PPM& rhs){
            int r;
            int g;
            int b;
            for(int i= 0; i<getHeight();i++){
                for(int j = 0; j<getWidth(); j++){
                    //finds what the red value should be
                    r =  getChannel(i,j,0)- rhs.getChannel(i,j,0);
                    if(r>0){
                        
                    } else{
                        r = 0;
                    }

                    //finds what the green value should be
                    g = getChannel(i,j,1) - rhs.getChannel(i,j,1);
                    if(g>0){
                        
                    } else{
                        g = 0;
                    }
                     
                    // finds what the blue value should be
                    b = getChannel(i,j,2) - rhs.getChannel(i,j,2);
                    if(b>0){
                        
                    } else{
                        b = 0;
                    }

                    //takes the red, green, and blue values and sets the pixel value
                    setPixel(i,j,r,g,b);
                }
            }
            return *this;
        }

        PPM& PPM::operator*=(const double& rhs){
            
            int r;
            int g;
            int b;
            for(int i= 0; i<getHeight();i++){
                for(int j = 0; j<getWidth(); j++){
                    //finds what the red value should be
                    r =  getChannel(i,j,0)* rhs;
                    if(r<0){
                        r=0;
                    }else if (r>getMaxColorValue()){
                        r = getMaxColorValue();
                    }

                    //finds what the green value should be
                    g =  getChannel(i,j,1)* rhs;
                    if(g<0){
                        g=0;
                    }else if (g>getMaxColorValue()){
                        g = getMaxColorValue();
                    }
                     
                    // finds what the blue value should be
                    b = getChannel(i,j,2) * rhs;
                    if(b<0){
                        b=0;
                    }else if (b>getMaxColorValue()){
                        b = getMaxColorValue();
                    }

                    //takes the red, green, and blue values and sets the pixel value
                    setPixel(i,j,r,g,b);
                }
            }
            return *this;
        }
        PPM& PPM::operator/=(const double& rhs){


            int r;
            int g;
            int b;
            for(int i= 0; i<getHeight();i++){
                for(int j = 0; j<getWidth(); j++){
                    //finds what the red value should be
                    r =  getChannel(i,j,0)/ rhs;
                    if(r<0){
                        r=0;
                    }else if (r>getMaxColorValue()){
                        r = getMaxColorValue();
                    }

                    //finds what the green value should be
                    g = getChannel(i,j,1) / rhs;
                    if(g<0){
                        g=0;
                    }else if (g>getMaxColorValue()){
                        g = getMaxColorValue();
                    }
                     
                    // finds what the blue value should be
                    b = getChannel(i,j,2) / rhs;
                    if(b<0){
                        b=0;
                    }else if (b>getMaxColorValue()){
                        b = getMaxColorValue();
                    }

                    //takes the red, green, and blue values and sets the pixel value
                    setPixel(i,j,r,g,b);
                }
            }
            return *this;
        }
        PPM PPM::operator+(const PPM& rhs) const{
            int tempInt;
            //copies height width and max color to a new ppm
            PPM temp(getHeight(),getWidth());
            temp.setMaxColorValue(getMaxColorValue());
            //sets all the pixels to the new value
            for(int i =0; i < getHeight(); i++){
                for(int j = 0; j< getWidth(); j++){
                    //sets red
                    tempInt = getChannel(i,j,0)+rhs.getChannel(i,j,0);
                    if(tempInt>getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    }
                    temp.setChannel(i,j,0,tempInt);
                    //sets green
                    tempInt = getChannel(i,j,1)+rhs.getChannel(i,j,1);
                    if(tempInt>getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    }
                    temp.setChannel(i,j,1,tempInt);
                    //sets blue
                    tempInt = getChannel(i,j,2)+rhs.getChannel(i,j,2);
                    if(tempInt>getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    }
                    temp.setChannel(i,j,2,tempInt);
                }
            }
            return temp;

        }
        PPM PPM::operator-(const PPM& rhs) const{
            int tempInt;
            //copies height width and max color to a new ppm
            PPM temp(getHeight(),getWidth());
            temp.setMaxColorValue(getMaxColorValue());
            //sets all the pixels to the new value
            for(int i =0; i < getHeight(); i++){
                for(int j = 0; j< getWidth(); j++){
                    //sets red
                    tempInt = getChannel(i,j,0)-rhs.getChannel(i,j,0);
                    if(tempInt <0){
                        tempInt = 0;
                    }
                    temp.setChannel(i,j,0,tempInt);
                    //sets green
                    tempInt = getChannel(i,j,1)-rhs.getChannel(i,j,1);
                    if(tempInt <0){
                        tempInt = 0;
                    }
                    temp.setChannel(i,j,1,tempInt);
                    //sets blue
                    tempInt = getChannel(i,j,2)-rhs.getChannel(i,j,2);
                    if(tempInt <0){
                        tempInt = 0;
                    }
                    temp.setChannel(i,j,2,tempInt);
                }
            }
            return temp;
        }

        
        PPM PPM::operator*(const double& rhs) const{
            int tempInt;
            //copies height width and max color to a new ppm
            PPM temp(getHeight(),getWidth());
            temp.setMaxColorValue(getMaxColorValue());
            //sets all the pixels to the new value
            for(int i =0; i < getHeight(); i++){
                for(int j = 0; j< getWidth(); j++){
                    //sets red
                    tempInt = getChannel(i,j,0)*rhs;
                    if(tempInt>getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    } else if ( tempInt<0){
                        tempInt = 0;
                    }
                    temp.setChannel(i,j,0,tempInt);
                    //sets green
                    tempInt = getChannel(i,j,1)*rhs;
                    if(tempInt>getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    } else if ( tempInt<0){
                        tempInt = 0;
                    }
                    temp.setChannel(i,j,1,tempInt);
                    //sets blue
                    tempInt = getChannel(i,j,2)*rhs;
                    if(tempInt>getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    } else if ( tempInt<0){
                        tempInt = 0;
                    }
                    temp.setChannel(i,j,2,tempInt);
                }
            }
            return temp;
        }



        PPM PPM::operator/(const double& rhs) const{
            int tempInt;
            //copies height width and max color to a new ppm
            PPM temp(getHeight(),getWidth());
            temp.setMaxColorValue(getMaxColorValue());
            //sets all the pixels to the new value
            for(int i =0; i < getHeight(); i++){
                for(int j = 0; j< getWidth(); j++){
                    //sets red
                    tempInt = getChannel(i,j,0)/rhs;
                    if(tempInt <0){
                        tempInt = 0;
                    } else if (tempInt > getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    }
                    temp.setChannel(i,j,0,tempInt);
                    //sets green
                    tempInt = getChannel(i,j,1)/rhs;
                    if(tempInt <0){
                        tempInt = 0;
                    } else if (tempInt > getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    }
                    temp.setChannel(i,j,1,tempInt);
                    //sets blue
                    tempInt = getChannel(i,j,2)/rhs;
                    if(tempInt <0){
                        tempInt = 0;
                    } else if (tempInt > getMaxColorValue()){
                        tempInt = getMaxColorValue();
                    }
                    temp.setChannel(i,j,2,tempInt);
                }
            }
            return temp;
        }
        
        void PPM::grayFromChannel( PPM& dst, const int& src_channel ) const{

            dst.setHeight(getHeight());
            dst.setWidth(getWidth());
            dst.setMaxColorValue(getMaxColorValue());

            int tempPixelValue;

            for(int i = 0; i <getHeight(); i++){
                for(int j = 0; j<getWidth(); j++){
                    tempPixelValue = getChannel(i,j,src_channel);
                    dst.setPixel(i,j,tempPixelValue,tempPixelValue,tempPixelValue);
                }
            }

        }

        void PPM::grayFromRed( PPM& dst ) const{
            grayFromChannel(dst,0);
        }
        void PPM::grayFromGreen( PPM& dst ) const{
            grayFromChannel(dst,1);
        }
        void PPM::grayFromBlue( PPM& dst ) const{
            grayFromChannel(dst,2);
        }
        double PPM::linearColorimetricPixelValue( const int& row, const int& column ) const{
            int red = getChannel(row,column,0);
            int green = getChannel(row,column,1);
            int blue = getChannel(row,column,2);
            return 0.2126*red + 0.7152*green + 0.0722*blue;
        }
        
        void PPM::grayFromLinearColorimetric( PPM& dst ) const{
            dst.setHeight(getHeight());
            dst.setWidth(getWidth());
            dst.setMaxColorValue(getMaxColorValue());

            int tempPixelValue;

            for(int i = 0; i <getHeight(); i++){
                for(int j = 0; j<getWidth(); j++){
                    tempPixelValue = linearColorimetricPixelValue(i,j);
                    dst.setPixel(i,j,tempPixelValue,tempPixelValue,tempPixelValue);
                }
            }
        }

        void PPM::orangeFilter(PPM& dst) const{
            dst.setHeight(getHeight());
            dst.setWidth(getWidth());
            dst.setMaxColorValue(getMaxColorValue());

            int red;
            int green;
            int blue;

            for(int i = 0; i <getHeight(); i++){
                for(int j = 0; j<getWidth(); j++){

                    red = 2*(2*getChannel(i,j,0)+getChannel(i,j,1))/3;
                    if(red>getMaxColorValue()){
                        red = getMaxColorValue();
                    } else if (red<0){
                        red = 0;
                    }

                    green = 2*(2*getChannel(i,j,0)+getChannel(i,j,1))/6;
                    if(green>getMaxColorValue()){
                        green = getMaxColorValue();
                    } else if (green<0){
                        green = 0;
                    }

                    blue = getChannel(i,j,2)/2;
                    if(blue>getMaxColorValue()){
                        blue = getMaxColorValue();
                    } else if (blue<0){
                        blue = 0;
                    }

                    dst.setPixel(i,j,red,green,blue);
                }
            }
        }

