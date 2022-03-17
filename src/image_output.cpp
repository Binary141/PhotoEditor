#include "image_menu.h"


void drawAsciiImage(ActionData& action_data){
    
    for(int i =0; i< action_data.getOutputImage().getHeight(); i++){

        for (int j = 0; j< action_data.getOutputImage().getWidth(); j++) {

            double value = action_data.getOutputImage().getChannel(i,j,0) + action_data.getOutputImage().getChannel(i,j,1) + action_data.getOutputImage().getChannel(i,j,2);
            
            //std::cout << value << ' ';
           
            value = value / 765.0;
            
            //std::cout << value << ' ';

            if(value >= 1.0){
                action_data.getOS() << '@';
                
            } else if( value>= 0.9){
                action_data.getOS() << '#';
            } else if(value >=0.8){
                action_data.getOS() << '%';
            } else if( value >= 0.7){
                action_data.getOS() << '*';
            } else if( value >= 0.6){
                action_data.getOS() << '|';
            } else if( value >= 0.5){
                action_data.getOS() << '+';
            } else if( value >= 0.4){
                action_data.getOS() << ';';
            } else if( value >= 0.3){
                action_data.getOS() << '~';
            } else if( value >= 0.2){
                action_data.getOS() << '-';
            } else if(value >= 0.1){
                action_data.getOS() << '.';
            } else if( value >= 0.0){
                action_data.getOS() << ' ';
            }
        }
        action_data.getOS() << std::endl;

    }
}


void writeUserImage(ActionData& action_data){

    std::string filename = getString(action_data, "Output filename? ");
    std::ofstream data_file(filename, std::ios::binary);
    
    
    action_data.getOutputImage().writeStream(data_file);
    data_file.close();
}

void copyImage(ActionData& action_data){
    action_data.getOutputImage() = action_data.getInputImage1();
}

void readUserImage1(ActionData& action_data){
    std::string s = getString(action_data, "Input filename? ");
    std::ifstream dataFile(s,std::ios::binary);
    if(dataFile.good()){
        action_data.getInputImage1().readStream(dataFile);
    } else{
        std::string st = s + " could not be opened.\n" ;
         action_data.getOS() << st;
    }
}

void readUserImage2(ActionData& action_data){
    std::string s = getString(action_data, "Input filename? ");
    std::ifstream dataFile(s,std::ios::binary);
    if(dataFile.good()){
        action_data.getInputImage2().readStream(dataFile);
    } else{
        std::string st = s + " could not be opened.\n" ;
         action_data.getOS() << st;
    }
}
