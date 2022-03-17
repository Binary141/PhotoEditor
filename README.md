# PhotoEditor
A desktop application that allows users to create or edit photos in the ppm format.
## General Info
This has a gui and a command line version of this code in this repository.
### Gui Mode
The feature set of in the gui mode is less developed than the command line tool. The current feature set with the gui is:
* q to exit
* the arrow keys to pan in the according direction (only works when zoomed in at least once)
* J to create a Julia set
* j to create a Julia set at a different value
* M to create a Mandelbrot set at the selected value (defaults to 0,0)
* Left click to pick a new value for the Mandelbrot set
* m to create a Mandelbrot set at a preselected value
* C to generic complex fractal
* c to create a different generic complex fractal
* 1 to create a new random table of colors
* T to pull up the color table
* t to swap from the color table view to the fractal mode
* . or > to add more colors to the color table
* , or < to remove a color from the color table
* b to show the default Mandelbrot fractal
* n to show the default Julia set fractal
* F to show the default complex fractal
* z to zoom in
* Z to zoom out
* R to reset the plane
* = or + to increase the max escape count of the fractal
* - to decrease the max escape count of the fractal
* a to toggle between RGB colors and HSV colors
  
### Command Line Mode
On the command line type help to pull up a list of commands and there descriptions

## Tool stack description
C++ and openGL were used to create this application

## Running
To run the gui mode type make in the gui-src folder.  To run the command line mode type make in the src folder. To use the gui you will need an application to configure your gui. I would recommend XLaunch.