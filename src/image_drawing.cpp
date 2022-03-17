#include "image_menu.h"

#include <iostream>


void diagonalQuadPattern(ActionData& action_data){
    int height = getInteger(action_data,"Image height? ");
    int width = getInteger(action_data,"Image width? ");
    
    action_data.getInputImage1().setMaxColorValue(255);
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);

    //the red color
    int i = height/2;
    int j =0;
    for(;i<height;i++){
        for(j =0; j<width; j++){
            action_data.getInputImage1().setChannel(i,j,0,255);
            //std::cout << i << image.getChannel(i,j,0);
        }   
    }    

    //the green color
    for(i =0; i<height;i++){
        for(j = 0; j<width; j++){

            action_data.getInputImage1().setChannel(i,j,1, (2*i+2*j)%256 );
        }
    }

    //the blue color
    
    for (i = 0; i<height; i++) {

        j = width/2;
        
        for(;j<width; j++){
            action_data.getInputImage1().setChannel(i,j,2,255);
        }
    }    
}

void stripedDiagonalPattern(ActionData& action_data){

    int widthin;
    int heightin;

    heightin = getInteger(action_data, "Image height? ");
    widthin = getInteger(action_data, "Image width? ");

    action_data.getInputImage1().setHeight(heightin);
    action_data.getInputImage1().setWidth(widthin);
    


    if((heightin+widthin)/3>255){
        action_data.getInputImage1().setMaxColorValue(255);
    }else{
        action_data.getInputImage1().setMaxColorValue((heightin+widthin)/3);
    }


    
    //the red color
    for(int i = action_data.getInputImage1().getHeight()/2;i<action_data.getInputImage1().getHeight();i++){
        for(int j =0; j<action_data.getInputImage1().getWidth(); j++){
            if(i%3!=0){
                
                action_data.getInputImage1().setChannel(i,j,0,action_data.getInputImage1().getMaxColorValue());
            }   
        }
    }

    //the green color    
    for(int i = 0;i<heightin;i++){
        for(int j =0; j<widthin; j++){
            action_data.getInputImage1().setChannel(i,j,1, (i+widthin-j-1)%(1+action_data.getInputImage1().getMaxColorValue() ) );
            
        }
        
    }

    //the blue color
    for(int i =0;i<heightin;i++){
        for(int j =0; j<widthin; j++){
            if(j<i){

            }  else {
                action_data.getInputImage1().setChannel(i,j,2,action_data.getInputImage1().getMaxColorValue());
            }
        }
        
    }


}


void fourSquarePattern( ActionData& action_data) {

    int sizein = getInteger(action_data, "Image size? ");

    action_data.getInputImage1().setHeight(sizein);
    action_data.getInputImage1().setWidth(sizein);
    action_data.getInputImage1().setMaxColorValue(100);

    //top left 
    for(int i = 0; i<action_data.getInputImage1().getHeight()/2;i++){
        for(int j =0; j<action_data.getInputImage1().getWidth()/2; j++){

            action_data.getInputImage1().setPixel(i,j,100,0,66);               
        }  
    }

    //top right 
    for(int i = 0; i<action_data.getInputImage1().getHeight()/2;i++){
        for(int j =action_data.getInputImage1().getWidth()/2; j<action_data.getInputImage1().getWidth(); j++){
            action_data.getInputImage1().setPixel(i,j,0,100,33);               
        }
    }


    //bottom left
    for(int i = action_data.getInputImage1().getHeight()/2; i<action_data.getInputImage1().getHeight();i++){
        for(int j =0; j<action_data.getInputImage1().getWidth()/2; j++){
            action_data.getInputImage1().setPixel(i,j,66,33,100);                      
        }
    }


    //bottom right
    for(int i = action_data.getInputImage1().getHeight()/2; i<action_data.getInputImage1().getHeight();i++){
        for(int j =action_data.getInputImage1().getWidth()/2; j<action_data.getInputImage1().getWidth(); j++){
            action_data.getInputImage1().setPixel(i,j,33,66, 0);            
        }
    }
}

void setSize(ActionData& action_data){
    int height = getInteger(action_data,"Height? ");
    int width = getInteger(action_data,"Width? ");

    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
}

void setMaxColorValue(ActionData& action_data){
    action_data.getInputImage1().setMaxColorValue( getInteger(action_data, "Max color value? ") );
}

void setChannel(ActionData& action_data ){
    int row = getInteger(action_data, "Row? ");
    int column = getInteger(action_data, "Column? ");
    int channel = getInteger(action_data, "Channel? ");
    int value = getInteger(action_data, "Value? ");
    action_data.getInputImage1().setChannel(row,column,channel,value);
}

void setPixel(ActionData& action_data){
    int row = getInteger(action_data, "Row? ");
    int column = getInteger(action_data, "Column? ");
    int r = getInteger(action_data, "Red? ");
    int g = getInteger(action_data, "Green? ");
    int b = getInteger(action_data,"Blue? ");
    action_data.getInputImage1().setPixel(row,column,r,g,b);
}

void clearAll(ActionData& action_data){
    for(int i = 0;i<action_data.getInputImage1().getHeight();i++){
        for(int j= 0; j<action_data.getInputImage1().getWidth();j++){
            action_data.getInputImage1().setPixel(i,j,0,0,0);

        }
    }
}

void drawCircle(ActionData& action_data){

    int row = getInteger(action_data,"Center Row? ");
    int column = getInteger(action_data, "Center Column? ");
    int radius = getInteger(action_data, "Radius? ");
    int red = getInteger(action_data,"Red? ");
    int green = getInteger(action_data,"Green? ");
    int blue = getInteger(action_data, "Blue? ");

    int dist;
    for(int i = 0; i < action_data.getInputImage1().getHeight(); i++){
        for(int j = 0; j< action_data.getInputImage1().getWidth(); j++){
            dist = (i-row) * (i-row) +(j-column) *(j-column);
            if (dist<= (radius*radius)){
                action_data.getInputImage1().setPixel(i,j,red,green,blue);
            }
        }
    }


}

void drawBox(ActionData& action_data){

    int top = getInteger(action_data,"Top Row? ");
    int left = getInteger(action_data, "Left Column? ");
    int bottom = getInteger(action_data, "Bottom Row? ");
    int right = getInteger(action_data, "Right Column? ");
    int red = getInteger(action_data,"Red? ");
    int green = getInteger(action_data,"Green? ");
    int blue = getInteger(action_data, "Blue? ");

    for(int i = 0; i<action_data.getInputImage1().getHeight(); i++){
        for (int j = 0; j < action_data.getInputImage1().getWidth(); j++) {
            if(top <= i && bottom>=i && left<=j && right>=j){
                action_data.getInputImage1().setPixel(i,j,red,green,blue);
            }
        }
        
    }

}


void drawSquare(ActionData& action_data){
    
    int row = getInteger(action_data,"Row? ");
    int column = getInteger(action_data, "Column? ");
    int size = getInteger(action_data, "Size? ");
    int red = getInteger(action_data,"Red? ");
    int green = getInteger(action_data,"Green? ");
    int blue = getInteger(action_data, "Blue? ");

    for(int i = 0; i<action_data.getInputImage1().getHeight(); i++){

        for (int j = 0; j < action_data.getInputImage1().getWidth(); j++) {

            if(i>=row-(size/2)  && i <= row + (size/2)  &&  j >= column-(size/2)  && j<= column + (size/2)){
                action_data.getInputImage1().setPixel(i,j,red,green,blue);
            }
        }
        
    }
}

void configureGrid(ActionData& action_data){
    int height = getInteger(action_data,"Grid Height? ");
    int width = getInteger(action_data,"Grid Width? ");
    int max = getInteger(action_data,"Grid Max Value? ");
    action_data.getGrid().setGridSize(height,width);
    action_data.getGrid().setMaxNumber(max);
}

void setGrid(ActionData& action_data){
    int row = getInteger(action_data,"Grid Row? ");
    int column = getInteger(action_data,"Grid Column? ");
    int value = getInteger(action_data, "Grid Value? ");
    action_data.getGrid().setNumber(row,column,value);

}
void applyGrid(ActionData& action_data){
    action_data.getGrid().setPPM(action_data.getOutputImage());
    
}


void setColorTableSize(ActionData& action_data){
    int size = getInteger(action_data,"Size? ");
    action_data.getTable().setNumberOfColors(size);
}

void setColor(ActionData& action_data){
    int pos = getInteger(action_data,"Position? ");
    int red = getInteger(action_data,"Red? ");
    int green = getInteger(action_data,"Green? ");
    int blue = getInteger(action_data,"Blue? ");
    action_data.getTable()[pos].setRed(red);
    action_data.getTable()[pos].setGreen(green);
    action_data.getTable()[pos].setBlue(blue);

}
void setRandomColor(ActionData& action_data){
    int pos = getInteger(action_data,"Position? ");
    action_data.getTable().setRandomColor(255,pos);
}
void setColorGradient(ActionData& action_data){

           


    int fpos = getInteger(action_data,"First position? ");
    int fred = getInteger(action_data,"First red? ");
    int fgreen = getInteger(action_data,"First green? ");
    int fblue = getInteger(action_data,"First blue? ");
    int spos = getInteger(action_data,"Second position? ");
    int sred = getInteger(action_data,"Second red? ");
    int sgreen = getInteger(action_data,"Second green? ");
    int sblue = getInteger(action_data,"Second blue? ");

                //std::cout <<std::endl<< fpos << " " << spos << std::endl;



    Color c1 = Color(fred,fgreen,fblue);
    Color c2 = Color(sred,sgreen,sblue);

    action_data.getTable().insertGradient(c1,c2,fpos,spos);
}
void applyGridColorTable(ActionData& action_data){
    action_data.getGrid().setPPM(action_data.getOutputImage(),action_data.getTable());
}

void setFractalPlaneSize(ActionData& action_data){

    ComplexFractal* cf = dynamic_cast<ComplexFractal*> (&action_data.getGrid());
    if(cf == nullptr){
        action_data.getOS() << "Not a ComplexFractal object. Can’t set plane size.";
        return;
    }

    double minX = getDouble(action_data, "Min X? ");
    double maxX = getDouble(action_data, "Max X? ");
    double minY = getDouble(action_data, "Min Y? ");
    double maxY = getDouble(action_data, "Max Y? ");  
    
    cf -> setPlaneSize( minX,  maxX, minY, maxY );
    
}

void calculateFractal(ActionData& action_data){
    action_data.getGrid().calculateAllNumbers();
}

void setJuliaParameters(ActionData& action_data){

    JuliaSet* js = dynamic_cast<JuliaSet*> (&action_data.getGrid());
    if(js == nullptr){
        action_data.getOS() << "Not a JuliaSet object.  Can't set parameters." << std::endl;
        return;
    }

    double a = getDouble(action_data,"Parameter a? ");
    double b = getDouble(action_data, "Parameter b? ");
    js->setParameters(a,b);

}



void setMandelbrotPower( ActionData& action_data ){
    
    MandelbrotPower* js = dynamic_cast<MandelbrotPower*> (&action_data.getGrid());
    if(js == nullptr){
        action_data.getOS() << "Not a MandelbrotPower object. Can't set power.";
        return;
    }

    double power = getDouble(action_data, "Power? ");
    js->setPower(power);
}

void setInvertedColorGradient(ActionData& action_data){
    int fpos = getInteger(action_data, "First position? ");
    int red  = getInteger(action_data, "First red? ");
    int green = getInteger(action_data, "First green? ");
    int blue = getInteger(action_data, "First blue? ");
    int spos = getInteger(action_data, "Second position? ");
    Color c1 = Color(red,green,blue);
    action_data.getTable().insertInvertedGradient(c1,fpos,spos);
}

void calculateFractalSingleThread(ActionData& action_data){
    action_data.getGrid().NumberGrid::calculateAllNumbers();
}

void setHueSaturationValueGradient(ActionData& action_data){
    int pos1 = getInteger(action_data, "First position? ");
    double hue1 = getDouble(action_data,"First hue? ");
    double sat1 = getDouble(action_data,"First saturation? ");
    double val1 = getDouble(action_data,"First value? ");

    int pos2 = getInteger(action_data, "Second position? ");
    double hue2 = getDouble(action_data,"Second hue? ");
    double sat2 = getDouble(action_data,"Second saturation? ");
    double val2 = getDouble(action_data,"Second value? ");

    double r1,g1,b1;
    HSV_to_RGB(hue1,sat1,val1,r1,g1,b1);
    Color c1 = Color(r1,g1,b1);

    double r2,g2,b2;
    HSV_to_RGB(hue2,sat2,val2,r2,g2,b2);
    Color c2 = Color(r2,g2,b2);

    action_data.getTable().insertHueSaturationValueGradient(c1,c2,pos1,pos2);

}