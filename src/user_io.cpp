#include "image_menu.h"

std::string getString(ActionData& action_data, const std::string& prompt) {

    std::string response;

    action_data.getOS() << prompt;
    action_data.getIS() >> response;
    return response;
}

int getInteger(ActionData& action_data, const std::string& prompt) {

    int response;

    action_data.getOS() << prompt;
    action_data.getIS() >> response;



    return response;
}

double getDouble(ActionData& action_data, const std::string& prompt) {

    double response;

    action_data.getOS() << prompt;
    action_data.getIS() >> response;
    return response;
}

// This is where all the work for the question_3 is done
int askQuestions3(ActionData& action_data){
    std::string gets;
    int geti;
    double getd;

    gets = getString(action_data, "What is your favorite color? ");
    geti = getInteger(action_data, "What is your favorite integer? ");
    getd = getDouble(action_data, "What is your favorite number? ");

    int i;
    for (i = 0; i < geti; i++) {
        action_data.getOS() << i+1 << " " << gets << " " << getd << std::endl;
    }
    

    return geti;
}

std::string getChoice(ActionData& action_data){
    return getString(action_data, "Choice? ");
}

void commentLine(ActionData& action_data){
    bool running = true;
    char c;
    while(running){
        //reads 1 character from the IS
        action_data.getIS().read((char*)& c,1);
        //detects if the input stream of action data is not good or the last character was a new line
        if(!action_data.getIS().good() || c == '\n'){
            running = false;
            return;
        }
    }
}

void quit(ActionData& action_data){
    action_data.setDone();
}
