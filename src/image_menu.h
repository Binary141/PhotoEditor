#ifndef image_menu_H
#define image_menu_H

#include "Image.h"
#include "PPM.h"
#include "ActionData.h"
#include "MenuData.h"
#include "ThreadedGrid.h"
#include "ColorTable.h"
#include "ComplexFractal.h"
#include "JuliaSet.h"
#include "MandelbrotSet.h"

#include <iostream>
#include <ios>
#include <fstream>
#include <ostream>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>
#include <ctime>



//user_io.cpp
std::string getString( ActionData& action_data, const std::string& prompt);
int getInteger( ActionData& action_data, const std::string& prompt);
double getDouble(ActionData& action_data, const std::string& prompt );
int askQuestions3(ActionData& action_data);
std::string getChoice(ActionData& action_data );
void commentLine( ActionData& action_data );
void quit(ActionData& action_data);

//image_drawing.cpp
void diagonalQuadPattern( ActionData& action_data);
void stripedDiagonalPattern( ActionData& action_data);
void fourSquarePattern(ActionData& action_data);  //exam 1
void setSize(ActionData& action_data);
void setMaxColorValue(ActionData& action_data);
void setChannel(ActionData& action_data);
void setPixel (ActionData& action_data);
void clearAll(ActionData& action_data);
void drawCircle(ActionData& action_data);
void drawBox(ActionData& action_data);
void drawSquare(ActionData& action_data); //exam 2
void configureGrid(ActionData& action_data);
void setGrid(ActionData& action_data);
void applyGrid(ActionData& action_data);
void setColorTableSize(ActionData& action_data);
void setColor(ActionData& action_data);
void setRandomColor(ActionData& action_data);
void setColorGradient(ActionData& action_data);
void applyGridColorTable(ActionData& action_data);
void setFractalPlaneSize(ActionData& action_data);
void calculateFractal(ActionData& action_data);
void setJuliaParameters(ActionData& action_data);
void setMandelbrotPower( ActionData& action_data ); //test 3
void setInvertedColorGradient(ActionData& action_data); //test 3
void calculateFractalSingleThread(ActionData& action_data);
void setHueSaturationValueGradient(ActionData& action_data); //final exam

//image_output.cpp
void drawAsciiImage(ActionData& action_data);
void writeUserImage(ActionData& actoin_data);
void copyImage(ActionData& action_data);
void readUserImage1( ActionData& action_data);
void readUserImage2( ActionData& action_data);

//controllers.cpp
int assignment1( std::istream& is, std::ostream& os);
int assignment2(std::istream& is, std::ostream& os);
int assignment3(std::istream& is, std::ostream& os);
int four_square( std::istream& is, std::ostream& os );
void showMenu( MenuData& menu_data, ActionData& action_data);
void takeAction(const std::string& choice, MenuData& menu_data, ActionData& action_data);
void configureMenu( MenuData& menu_data);
int imageMenu(std::istream& is, std::ostream& os);
void setComplexFractal( ActionData& action_data );
void setJuliaFractal( ActionData& action_data );
void setMandelbrotFractal( ActionData& action_data );
void setMandelbrotPowerFractal( ActionData& action_data ); // test 3

//image_filters.cpp
void plusEquals(ActionData& action_data);
void minusEquals(ActionData& action_data);
void timesEquals(ActionData& action_data);
void divideEquals(ActionData& action_data);
void plus(ActionData& action_data);
void minus(ActionData& action_data);
void times(ActionData& action_data);
void divide(ActionData& action_data);
void grayFromRed(ActionData& action_data);
void grayFromGreen(ActionData& action_data);
void grayFromBlue(ActionData& action_data);
void grayFromLinearColorimetric(ActionData& action_data);
void orangeFilter(ActionData& action_data); //exam 2


#endif