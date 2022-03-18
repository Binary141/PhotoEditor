COMMONOFILES := controllers.o user_io.o image_drawing.o image_output.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ActionData.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o 
COMMONHFILES := Image.h PPM.h ActionData.h MenuData.h image_menu.h NumberGrid.h ColorTable.h ComplexFractal.h JuliaSet.h MandelbrotSet.h ThreadedGrid.h ThreadedVector.h
LDFLAGS := -lpthread

all: hello questions_3 ascii_image image_file four_square ppm_menu 


hello: hello.o
	g++ -o hello hello.o

hello.o: hello.cpp 
	g++ -c hello.cpp

questions_3: questions_3.o $(COMMONOFILES)
	g++ -o $@  $^ $(LDFLAGS)

questions_3.o: questions_3.cpp $(COMMONHFILES)
	g++ -c questions_3.cpp

user_io.o: user_io.cpp $(COMMONHFILES)
	g++ -c user_io.cpp


ascii_image:  ascii_image.o $(COMMONOFILES)
	g++ -o $@ $^ $(LDFLAGS)

Image.o: Image.cpp $(COMMONHFILES) 
	g++ -c Image.cpp

image_drawing.o: image_drawing.cpp $(COMMONHFILES)
	g++ -c image_drawing.cpp

image_output.o: image_output.cpp $(COMMONHFILES) 
	g++ -c image_output.cpp

ascii_image.o: ascii_image.cpp $(COMMONHFILES) 
	g++ -c ascii_image.cpp


controllers.o: controllers.cpp $(COMMONHFILES)
	g++ -c controllers.cpp 

image_file.o: image_file.cpp $(COMMONHFILES)
	g++ -c image_file.cpp

PMM.o: PPM.cpp $(COMMONHFILES)
	g++ -c PPM.cpp

image_file: image_file.o $(COMMONOFILES)
	g++ -o $@ $^ $(LDFLAGS)


four_square.o: four_square.cpp $(COMMONHFILES)
	g++ -c four_square.cpp

four_square: four_square.o $(COMMONOFILES)
	g++ -o $@ $^ $(LDFLAGS)

ActionData.o: ActionData.cpp $(COMMONHFILES)
	g++ -c ActionData.cpp

MenuData.o: MenuData.cpp $(COMMONHFILES)
	g++ -c MenuData.cpp

ppm_menu: ppm_menu.o $(COMMONOFILES)
	g++ -o $@ $^ $(LDFLAGS)

ppm_menu.o: ppm_menu.cpp $(COMMONHFILES)
	g++ -c ppm_menu.cpp

image_filters.o: image_filters.cpp $(COMMONHFILES)
	g++ -c image_filters.cpp

NumberGrid.o: NumberGrid.cpp $(COMMONHFILES)
	g++ -c NumberGrid.cpp

ColorTable.o: ColorTable.cpp ColorTable.h
	g++ -c ColorTable.cpp

ComplexFractal.o: ComplexFractal.cpp ComplexFractal.h 
	g++ -c ComplexFractal.cpp

JuliaSet.o: JuliaSet.cpp JuliaSet.h 
	g++ -c JuliaSet.cpp

MandelbrotSet.o: MandelbrotSet.cpp MandelbrotSet.h 
	g++ -c MandelbrotSet.cpp

ThreadedGrid.o: ThreadedGrid.cpp ThreadedGrid.h 
	g++ -c ThreadedGrid.cpp 

# foo.o: foo.cpp $(COMMONHFILES)
# 	g++ -c foo.cpp										<-----------------------figure this out maybe need maybe not

clean:
	-rm -f image_file four_square ascii_image questions_3 hello testFile ppm_menu
	-rm -f *.o
	-rm -f *.ppm
	-rm -f *.gch

testFile: test.o $(COMMONOFILES)
	g++ -o $@ $^

test.o: test.cpp PPM.h Image.h image_menu.h
	g++ -c test.cpp 