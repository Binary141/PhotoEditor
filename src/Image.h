#ifndef Image_H
#define Image_H
#include <vector> 

class Image {
    public:
        Image(); //default constructor
        Image(const int& height, const int& width ); //other constructer
        int getHeight( ) const; //returns height
        int getWidth( ) const; //returns width
        bool indexValid( const int& row, const int& column, const int& channel ) const; //cheacks if the index is valid
        int index( const int& row, const int& column, const int& channel ) const; //calculates the corcet index
        int getChannel( const int& row, const int& column, const int& channel ) const; //gets the item at the channel
        void setHeight( const int& height ); //sets height
        void setWidth( const int& width ); // sets width
        void setChannel( const int& row, const int& column, const int& channel, const int& value ); //set the value of the channel
        //std::vector<int> getVector( ) const;

    private:
        int height;
        int width;
        std::vector<int> vec;
};



#endif
