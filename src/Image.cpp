#include  "Image.h"
#include "iostream"


Image::Image() : height(0), width(0), vec( height*width*3)  {

}

Image::Image(const int& heightin, const int& widthin )
    : height(heightin), width(widthin), vec( height*width*3) {
    }

int Image::getHeight() const {
    return height;
}

int Image::getWidth() const {
    return width;
}

bool Image::indexValid(const int& row, const int& column, const int& channel) const{
    
    if(channel>2 || channel<0 || row >= getHeight() || row<0 || column >= getWidth() || column <0){
        return false;
    } else {
        return true;
    }
}

int Image::index(const int& row, const int& column, const int& channel ) const {
    return ((row * getWidth() * 3) + (column *3))+channel;
}

int Image::getChannel(const int& row, const int& column, const int& channel) const{
    if( indexValid(row, column, channel) ){
        
        return vec[index(row, column, channel)];

    } else {
        
        return -1;
    }
}

void Image::setHeight( const int& heightin){
    if(heightin>=0){
        height = heightin;
        vec.resize(getHeight()*getWidth()*3);
    }
}

void Image::setWidth(const int& widthin){
    if(widthin>=0){
        width = widthin;
        vec.resize(getHeight()*getWidth()*3);
    }
}

void Image::setChannel(const int& row, const int& column, const int& channel, const int& value){
    if(indexValid(row,column,channel)){
        
        vec[ index(row,column,channel) ] = value;
    } 
    //std::cout << getHeight() << getWidth();
}


