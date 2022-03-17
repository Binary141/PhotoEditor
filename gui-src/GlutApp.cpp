#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
  : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream),mMinX(-2.0), mMaxX(2.0), mMinY(-2.0),mMaxY(2.0),
  mInteractionMode(IM_FRACTAL), mFractalMode(M_MANDELBROT),mMaxNumber(200),mNumColor(32),mHSVColor(false) {
    
  configureMenu(mMenuData);
  mActionData.setGrid(new ComplexFractal);

  mColor1 = Color(0,255,0);
  mColor2 = Color(255,0,255);


  setColorTable();
  createFractal();

  // // read1
  // mOutputStream.clear();
  // mInputStream.clear();
  // mInputStream.str("pretty-mandel-1.ppm");
  // takeAction("read1", mMenuData, mActionData);
  
  // // copy
  // mOutputStream.clear();
  // mInputStream.clear();
  // mInputStream.str("");
  // takeAction("copy", mMenuData, mActionData);
}

void GlutApp::setSize(int height, int width) {
  mHeight = height;
  mWidth = width;
}

int GlutApp::getHeight() const {
  return mHeight;
}
int GlutApp::getWidth() const {
  return mWidth;
}

void GlutApp::display() {

  if(mInteractionMode == IM_FRACTAL){
        PPM& p = mActionData.getOutputImage();
        double max = static_cast<double>(p.getMaxColorValue());
      double r, g, b;
      int row, column;
      glBegin( GL_POINTS );
      for(row = 0; row < p.getHeight(); row++) {
        for(column = 0; column < p.getWidth(); column++) {
          r = p.getChannel(row, column, 0) / max;
          g = p.getChannel(row, column, 1) / max;
          b = p.getChannel(row, column, 2) / max;
          glColor3d(r, g, b);
          glVertex2i(column, p.getHeight()-row-1);
        }
      }
      glEnd( );
  } else{
      displayColorTable();
  }
}


void GlutApp::createJulia() {

  selectJulia();
  
  configureGrid(200);
  
  juliaParameters(0.45, -0.32);
  
  fractalPlaneSize(-2.0,2.0,-2.0,2.0); 

  fractalCalculate();
 
  gridApplyColorTable();

}


  void GlutApp::createJulia2(){
      selectJulia();
    
    configureGrid(200);
    
    juliaParameters(0.5, -0.2);
    
    fractalPlaneSize(-1.0,1.0,-1.0,1.0); 

    fractalCalculate();
  
    gridApplyColorTable();
  }

  void GlutApp::createMandelbrot(){
      selectMandelbrot();
    
    configureGrid(200);
    
                                            
    
    fractalPlaneSize(0.0,1.0,0.0,1.0); 

    fractalCalculate();
  
    gridApplyColorTable();
  }
  void GlutApp::createMandelbrot2(){
      
    
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");

    takeAction("mandelbrot-power",mMenuData,mActionData);


    configureGrid(200);
    
    

    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
    std::stringstream tmp;
    tmp << 500;
    mInputStream.str(tmp.str());
  }
  takeAction("set-mandelbrot-power",mMenuData,mActionData);                                          //something may be missing here
    
    fractalPlaneSize(0.665,0.75,0.665,0.75); 

    fractalCalculate();
  
    gridApplyColorTable();
  }


  void GlutApp::createComplexFractal(){
    selectComplexFractal();
    
    configureGrid(200);
    
                                          //something may be missing here
    
    fractalPlaneSize(-2.0,2.0,-2.0,2.0); 

    fractalCalculate();
  
    gridApplyColorTable();
  }                               
  void GlutApp::createComplexFractal2(){
    selectComplexFractal();
    
    configureGrid(200);
    
                                            //something may be missing here
    
    fractalPlaneSize(-1.01,0.01,-1.01,0.01); 

    fractalCalculate();
  
    gridApplyColorTable();
  }


  void GlutApp::selectJulia(){
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    takeAction("julia",mMenuData, mActionData);
  }

  void GlutApp::selectMandelbrot(){
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    takeAction("mandelbrot",mMenuData, mActionData);
  }   

  void GlutApp::selectComplexFractal(){
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    takeAction("complex-fractal",mMenuData, mActionData);
  }

  void GlutApp::configureGrid(int max){
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
    std::stringstream tmp;
    tmp << mHeight << " " << mWidth << " "<< max;
    mInputStream.str(tmp.str());
  }
    takeAction("grid",mMenuData,mActionData);


  }
  
  void GlutApp::juliaParameters(double a, double b){
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
    std::stringstream tmp;
    tmp << a << " " << b ;
    mInputStream.str(tmp.str());
  }
  takeAction("julia-parameters",mMenuData,mActionData);
  }


  
  void GlutApp::fractalPlaneSize(double x_min, double x_max, double y_min, double y_max){

  mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
    std::stringstream tmp;
    tmp << x_min << " " << x_max << " " << y_min << " " << y_max;
    mInputStream.str(tmp.str());
  }
  takeAction("fractal-plane-size",mMenuData,mActionData);
  }


  void GlutApp::fractalCalculate(){
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    takeAction("fractal-calculate",mMenuData, mActionData);
  }
  
  void GlutApp::gridApplyColorTable(){
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    takeAction("grid-apply-color-table",mMenuData, mActionData);
  }

  void GlutApp::NewColorTable(){
    
    mOutputStream.clear();
    mInputStream.clear();               //first pos, fr,fg,fb , second pos, sr,sg,sb
    mOutputStream.str("");                 // 0                       15
    mInputStream.str("");

    {
    std::stringstream tmp;
    tmp << 0;
    mInputStream.str(tmp.str());
    }  

  takeAction("set-random-color",mMenuData, mActionData);

  mOutputStream.clear();
    mInputStream.clear();               //first pos, fr,fg,fb , second pos, sr,sg,sb
    mOutputStream.str("");                 // 0                       15
    mInputStream.str("");

    {
    std::stringstream tmp;
    tmp << mActionData.getTable().getNumberOfColors()-1;
    mInputStream.str(tmp.str());
    }  

  takeAction("set-random-color",mMenuData, mActionData);

  mOutputStream.clear();
    mInputStream.clear();               //first pos, fr,fg,fb , second pos, sr,sg,sb
    mOutputStream.str("");                  //0                     mActionData.getTable().getNumberOfColors()-1
    mInputStream.str("");

    {
    std::stringstream tmp;
    
      int size = mActionData.getTable().getNumberOfColors()-1;
    tmp << 0<< " "
    << mActionData.getTable()[0].getRed() << " "
    << mActionData.getTable()[0].getGreen() << " "
    << mActionData.getTable()[0].getBlue() << " "
    <<size << " "
    << mActionData.getTable()[size].getRed() << " " 
    << mActionData.getTable()[size].getGreen() << " "
    << mActionData.getTable()[size].getBlue();
    
        //mTable.insertGradient(c1,c2,0,15);
        //std::cout << mActionData.getTable().getNumberOfColors() << std::endl;

    mInputStream.str(tmp.str());
    }  


    takeAction("set-color-gradient",mMenuData, mActionData);




    gridApplyColorTable();

    //std::cout << mActionData.getTable().getNumberOfColors();
  }


  void GlutApp::displayColorTable(){
    
  glBegin( GL_POINTS );

    
    double red, green, blue;
    for(int row = 0; row<mHeight;row++){
      for(int column = 0; column<mWidth;column++){

        int i = column * mActionData.getTable().getNumberOfColors() / mWidth;
        red = mActionData.getTable()[i].getRed() /255.0;
        green = mActionData.getTable()[i].getGreen() /255.0;
        blue = mActionData.getTable()[i].getBlue() /255.0;
        
        glColor3d(red,green,blue);
        glVertex2i(column, row);

      }
    }
  }


  void GlutApp::setInteractionMode(InteractionMode mode){
      mInteractionMode = mode;
  }

  void GlutApp::setColorTable(){
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
    std::stringstream tmp;
    tmp << mNumColor;        //<-----------------------------------
    mInputStream.str(tmp.str());
    }
    takeAction("set-color-table-size",mMenuData, mActionData);
    if(!mHSVColor){
        mOutputStream.clear();
        mInputStream.clear();
        mOutputStream.str("");
        mInputStream.str("");
        {
        std::stringstream tmp;
        tmp << 0<< " "
        << mColor1.getRed() << " "
        << mColor1.getGreen() << " "
        << mColor1.getBlue() << " "
        << mActionData.getTable().getNumberOfColors()-1 << " "
        << mColor2.getRed() << " " 
        << mColor2.getGreen() << " "
        << mColor2.getBlue();
        mInputStream.str(tmp.str());
        }
        takeAction("set-color-gradient",mMenuData, mActionData);
    } else{

      

      mOutputStream.clear();
        mInputStream.clear();
        mOutputStream.str("");
        mInputStream.str("");
        {
          double h1, s1, v1;
        mColor1.getHSV(h1,s1,v1);

        double h2, s2, v2;
        mColor2.getHSV(h2,s2,v2);

        std::stringstream tmp;
        tmp << 0<< " "
        << h1 << " "
        << s1 << " "
        << v1 << " "
        << mActionData.getTable().getNumberOfColors()-1 << " "
        << h2 << " " 
        << s2 << " "
        << v2;
        mInputStream.str(tmp.str());
        }
        takeAction("set-hsv-gradient",mMenuData, mActionData);

  }

    
  } 


  void GlutApp::decreaseColorTableSize(){
    if(mActionData.getTable().getNumberOfColors() >10){
      mNumColor = mActionData.getTable().getNumberOfColors()/1.1;
    setColorTable();
    gridApplyColorTable();
    }
    

  }


  void GlutApp::increaseColorTableSize(){
    if(mActionData.getTable().getNumberOfColors()>=1024){
      return;
    }
    mNumColor = mActionData.getTable().getNumberOfColors()*1.1;
    setColorTable();
    gridApplyColorTable();
  }

  void GlutApp::zoomIn(){
    double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
    mMinX += dx;
    mMaxX -= dx;
    double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
    mMinY += dy;
    mMaxY -= dy;
  }

  void GlutApp::zoomOut(){
    double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
    double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
    if(mMinX-dx>=-2.0 && mMinY-dy>=-2.0 && mMaxX+dx<=2.0 && mMaxY+dx<=2.0 ){
      mMinX -= dx;
      mMaxX += dx;
      mMinY -= dy;
      mMaxY += dy;
    }
  }

  void GlutApp::moveLeft(){
    double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
    if(mMinX-dx<-2.0){
      return;
    }
    mMinX -= dx;
    mMaxX -= dx;
  }

  void GlutApp::moveRight(){
    double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
    if(mMaxX + dx>2.0){
      return;
    }
    mMinX += dx;
    mMaxX += dx;
  }

  void GlutApp::moveDown(){
    double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
    if(mMinY-dy<-2.0){
      return;
    }
    mMinY -= dy;
    mMaxY -= dy; 
  }

  void GlutApp::moveUp(){
    double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
    if(mMaxY + dy>2.0){
      return;
    }
    mMinY += dy;
    mMaxY += dy;
  }

  void GlutApp::setFractalMode(FractalMode mode){
      mFractalMode = mode;
  }
  void GlutApp::increaseMaxNumber(){
    if(mMaxNumber>=2048){
      return;
    }
    mMaxNumber*=1.1;
  }
  void GlutApp::decreaseMaxNumber(){
    if(mMaxNumber<=11){
     return;
    }
    mMaxNumber= mMaxNumber / 1.1;
  }
  void GlutApp::setAB(int x, int y){
    ComplexFractal* cf = dynamic_cast<ComplexFractal*> (&mActionData.getGrid());
    
    if((mFractalMode == M_MANDELBROT) && (cf != nullptr)){
        double dx = cf->getDeltaX();
        mA = mMinX + x * dx;
        double dy = cf->getDeltaY();
        mB = mMinY +y *dy;
    }
  }
  void GlutApp::resetPlane(){
      mMinX = -2.0;
      mMinY = -2.0;
      mMaxX = 2.0;
      mMaxY = 2.0;
  }
  void GlutApp::createFractal(){
      switch (mFractalMode)  {
            case M_MANDELBROT:
              selectMandelbrot();
              break;
            case M_JULIA:
              selectJulia();
              juliaParameters(mA,mB);  
              break;
            case M_COMPLEX:
              selectComplexFractal();
              break;
            default:
              break;
      } 

      configureGrid(mMaxNumber);
      fractalPlaneSize(mMinX,mMaxX,mMinY,mMaxY);
      fractalCalculate();
      gridApplyColorTable();
  }



void GlutApp::toggleHSVColor(){
  if(mHSVColor){
    mHSVColor = false;
  } else{
    mHSVColor = true;
  }

  setColorTable();
  gridApplyColorTable();
}