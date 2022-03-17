#include "ColorTable.h"

Color::Color()
:mRed(0), mGreen(0),mBlue(0) {
    
}

Color::Color(const int& red, const int& green, const int& blue)
: mRed(red), mGreen(green), mBlue(blue){

}

int Color::getRed( ) const{
    return mRed;
}
int Color::getGreen( ) const{
    return mGreen;
}
   
int Color::getBlue( ) const{
    return mBlue;
}
int Color::getChannel( const int& channel) const{                   // fix this it is probably broken
    if(channel == 0){
        return getRed();
    } else if(channel ==1){
        return getGreen();
    } else if (channel == 2){
        return getBlue();
    } else{
        return -1;
    }
}

void Color::setRed(const int& value){
 if (value<0){

 } else{
    mRed = value;
 }
}
void Color::setGreen(const int& value){
    if (value<0){

 }  else{
    mGreen = value;
 }
}
void Color::setBlue(const int& value){
    if (value<0){

 } else{
    mBlue = value;
 }
}
void Color::setChannel( const int& channel,const int& value){
    if(channel ==0){
        setRed(value);
    } else if (channel == 1){
        setGreen(value);
    } else if (channel == 2){
        setBlue(value);
    }
}
void Color::invert(const int& max_color_value){
    if(getRed()<=max_color_value && getGreen() <= max_color_value && getBlue() <= max_color_value){
        setRed(max_color_value-getRed());
        setGreen(max_color_value-getGreen());
        setBlue(max_color_value- getBlue());
    }
    
}

bool Color::operator==(const Color& rhs) const{
    if(this->getBlue() == rhs.getBlue() && this->getGreen() == rhs.getGreen() && this->getRed() == rhs.getRed()){
        return true;
    } return false;
}

std::ostream& operator<<(std::ostream& os, const Color& color){
    os << color.getRed() << ":" << color.getGreen() << ":" << color.getBlue();
    return os;
}

ColorTable::ColorTable(const int& num_color){       
    mTable.resize(num_color);
}

int ColorTable::getNumberOfColors( ) const{
    return mTable.size();
}

void ColorTable::setNumberOfColors(const int& num_color){
    mTable.resize(num_color);
}

const Color& ColorTable::operator[](const int& i) const{
    
    if(i<0){
        static Color ec(-1,-1,-1);
        static Color c(-1,-1,-1);
        c = ec;
        return c;
    }

    unsigned int temp = i;
    

    if( temp>=mTable.size()){
        
        static Color ec(-1,-1,-1);
        static Color c(-1,-1,-1);
        c = ec;
        return c;
    } else{
        return mTable[temp];
        
    }
}

Color& ColorTable::operator[](const int& i){
    if(i<0){
        static Color ec(-1,-1,-1);
        static Color c(-1,-1,-1);
        c = ec;
        return c;
    }

    unsigned int temp = i;
    

    if( temp>=mTable.size()){
        
        static Color ec(-1,-1,-1);
        static Color c(-1,-1,-1);
        c = ec;
        return c;
    } else{
        return mTable[temp]; 
        
    }
}

void ColorTable::setRandomColor(const int& max_color_value, const int& position){
    if(position<0 || (unsigned) position> mTable.size() || max_color_value<0){
        return;
    }
    int rRed =std::rand();
    int rGreen = std::rand();
    int rBlue = std::rand(); 
    
    if(max_color_value ==0){
        mTable[position].setRed(0);
        mTable[position].setGreen(0);
        mTable[position].setBlue(0);
        return;
    }

    mTable[position].setRed((rRed % max_color_value));
    mTable[position].setGreen((rGreen %max_color_value));
    mTable[position].setBlue((rBlue %max_color_value));

}
/**
 * Use to find rate of change of the gradient
 */
double ColorTable::gradientSlope(const double y1, const double y2, const double x1, const double x2) const{ 
    return (y2-y1)/(x2-x1);
}

/**
 * use to find the value of each color
 */
double ColorTable::gradientValue(const double y1, const double x1, const double slope, const double x) const{
//slope= (y2-y1)/(x2-x1) -> (x2-x1)slope = y2-y1 -> (x2-x1)slope +y1 = y2
    return (x-x1)*slope+y1;
}

void ColorTable::insertGradient( const Color& color1, const Color& color2, const int& position1, const int& position2 ){

    //std::cout << "color1= " << color1 << " color2= " << color2 << " pos1= " << position1 <<" pos2= "<< position2 << " size= " <<mTable.size() << std::endl;

    if (position1>= position2){
        
        return;
    }

            //std::cout << "color 1 " << color1 << " color 2 " << color2 << " pos1 " << position1 <<" pos 2 "<< position2 << " size " <<mTable.size() << std::endl;

    if(!indexValid(position1) || !indexValid(position2)){
        return;
    }

        //std::cout << "color 1 " << color1 << " color 2 " << color2 << " pos1 " << position1 <<" pos 2 "<< position2 << " size " <<mTable.size() << std::endl;



    double gRed = gradientSlope(color1.getRed(),color2.getRed(),position1,position2);
    double gGreen = gradientSlope(color1.getGreen(),color2.getGreen(),position1,position2);
    double gBlue = gradientSlope(color1.getBlue(),color2.getBlue(),position1,position2);

    for(int i = position1; i<=position2;i++){
        mTable[i].setRed(gradientValue(color1.getRed(),position1,gRed,i));
        mTable[i].setGreen(gradientValue(color1.getGreen(),position1,gGreen,i));
        mTable[i].setBlue(gradientValue(color1.getBlue(),position1,gBlue,i));
    }
}

int ColorTable::getMaxChannelValue( ) const{
    int max = mTable[0].getRed();
    for(unsigned int i = 0; i<mTable.size(); i++){
        if(mTable[i].getRed()> max){
            max = mTable[i].getRed();
        }
        if(mTable[i].getGreen() > max){
            max = mTable[i].getGreen();
        }
        if(mTable[i].getBlue() > max){
            max = mTable[i].getBlue();
        }
    }
    return max;
}

bool ColorTable::indexValid(const int& pos) const{
    if(pos<0 || (unsigned) pos>=mTable.size()){
        return false;
    } else{
        return true;
    }
}

void ColorTable::insertInvertedGradient( const Color& color1, const int& position1, const int& position2 ){
 Color cNew = color1;
 cNew.invert(255);
 insertGradient(color1,cNew,position1,position2);
 

}


void HSV_to_RGB(const double& hue, const double& saturation, const double& value, double& red, double &green, double& blue) {
  /* Convert Hue, Saturation, Value to Red, Green, Blue
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
   *
   * Inputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   *
   * Outputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   */
  if(hue < 0.0 || hue > 360.0 || saturation < 0.0 || saturation > 1.0 || value < 0.0 || value > 1.0) {
    red = green = blue = 0.0;
    std::cerr << "HSV_to_RGB() input parameters out of range." << std::endl
              << " hue: " << hue  << std::endl
              << " saturation: " << saturation << std::endl
              << " value: " << value << std::endl;
    return;
  }

  // chroma selects the strength of the "primary" color of the current area of the wheel
  double chroma = value * saturation;
  // hue2 selects which 60-degree wedge of the color wheel we are in
  double hue2 = hue / 60.0;
  // x selects the strength of the "secondary" color of the current area of the wheel
  double x = chroma * ( 1 - std::abs( std::fmod( hue2, 2 ) - 1 ) );
  if( hue2 >= 0 && hue2 < 1 ) {
    red = chroma;
    green = x;
    blue = 0.0;
  } else if( hue2 >= 1 && hue2 < 2 ) {
    red = x;
    green = chroma;
    blue = 0.0;
  } else if( hue2 >= 2 && hue2 < 3 ) {
    red = 0.0;
    green = chroma;
    blue = x;
  } else if( hue2 >= 3 && hue2 < 4 ) {
    red = 0.0;
    green = x;
    blue = chroma;
  } else if( hue2 >= 4 && hue2 < 5 ) {
    red = x;
    green = 0.0;
    blue = chroma;
  } else if( hue2 >= 5 && hue2 <= 6 ) {
    red = chroma;
    green = 0.0;
    blue = x;
  } else {
    red = 0;
    green = 0;
    blue = 0;
  }

  // m scales all color channels to obtain the overall brightness.
  double m = value - chroma;
  red = 255.0*( red + m );
  green = 255.0*( green + m );
  blue = 255.0*( blue + m );
}

void RGB_to_HSV(const double& red0, const double &green0, const double& blue0, double& hue, double& saturation, double& value) {
  /* Red, Green, Blue to Convert Hue, Saturation, Value
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB
   *
   * Inputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   *
   * Outputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   */
  if(red0 < 0.0 || red0 > 255.0 || green0 < 0.0 || green0 > 255.0 || blue0 < 0.0 || blue0 > 255.0) {
    hue = saturation = value = 0.0;
    std::cerr << "RGB_to_HSV() input parameters out of range." << std::endl
              << " red: " << red0  << std::endl
              << " green: " << green0 << std::endl
              << " blue: " << blue0 << std::endl;
    return;
  }

  double red   = red0 / 255.0;
  double green = green0 / 255.0;
  double blue  = blue0 / 255.0;

  // x_max helps identify the primary hue
  double x_max = red;
  if(green > x_max) { x_max = green; }
  if(blue > x_max) { x_max = blue; }
  value = x_max;

  double x_min = red;
  if(green < x_min) { x_min = green; }
  if(blue < x_min) { x_min = blue; }

  double chroma = x_max - x_min;

  if(chroma == 0) {
    hue = 0;
  } else if(value == red) {
    hue = 60.0 * (0 + (green - blue)/chroma);
  } else if(value == green) {
    hue = 60.0 * (2 + (blue - red)/chroma);
  } else if(value == blue) {
    hue = 60.0 * (4 + (red - green)/chroma);
  } else {
    hue = -720.0;
  }
  if(hue < 0.0) {
    hue += 360.0;
  }

  if(value == 0.0) {
    saturation = 0.0;
  } else {
    saturation = chroma/value;
  }

}



void Color::setFromHSV(const double& hue, const double& saturation, const double& value){
    
    double r;
    double g;
    double b;
    
    HSV_to_RGB(hue,saturation,value,r,g,b);
    setRed(r);
    setGreen(g);
    setBlue(b);
}
void Color::getHSV(double& hue, double& saturation, double& value) const{
    
    RGB_to_HSV(getRed(),getGreen(),getBlue(),hue, saturation, value);
}

void ColorTable::insertHueSaturationValueGradient(const Color& color1, const Color& color2, const int& position1, const int& position2){

    if (position1>= position2){
        
        return;
    }


    if(!indexValid(position1) || !indexValid(position2)){
        return;
    }

    double h1, s1, v1;
    double h2, s2, v2;


    color1.getHSV(h1,s1,v1);
    color2.getHSV(h2,s2,v2);

    double hSlope = gradientSlope(h1,h2,position1,position2);
    double sSlope = gradientSlope(s1,s2,position1,position2);
    double vSlope = gradientSlope(v1,v2,position1,position2);

    double r,g,b;
    for(int i = position1; i<=position2;i++){

        HSV_to_RGB(gradientValue(h1,position1,hSlope,i),gradientValue(s1,position1,sSlope,i),
        gradientValue(v1,position1,vSlope,i),r,g,b);
        mTable[i].setRed(r);
        mTable[i].setGreen(g);
        mTable[i].setBlue(b);
    }
    /*
    double gRed = gradientSlope(color1.getRed(),color2.getRed(),position1,position2);
    double gGreen = gradientSlope(color1.getGreen(),color2.getGreen(),position1,position2);
    double gBlue = gradientSlope(color1.getBlue(),color2.getBlue(),position1,position2);

    for(int i = position1; i<=position2;i++){
        mTable[i].setRed(gradientValue(color1.getRed(),position1,gRed,i));
        mTable[i].setGreen(gradientValue(color1.getGreen(),position1,gGreen,i));
        mTable[i].setBlue(gradientValue(color1.getBlue(),position1,gBlue,i));
    }
    */
}