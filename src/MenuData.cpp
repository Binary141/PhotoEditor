#include "MenuData.h"
#include "string"



MenuData::MenuData( ) {

}

void MenuData::addAction(const std::string& name, ActionFunctionType func, const std::string& description){
    nameVec.push_back(name);
    nameToFun.insert(std::pair<std::string, ActionFunctionType>(name,func));
    nameToDes.insert(std::pair<std::string,std::string>(name, description));
}

const std::vector<std::string>& MenuData::getNames( ) const{
    return nameVec;
}

ActionFunctionType MenuData::getFunction(const std::string&name){ 
    if(nameToFun.find(name) != nameToFun.end()){
        return nameToFun.at(name);
    }
    return 0;
}

const std::string& MenuData::getDescription(const std::string&name){
    if(nameToDes.find(name) != nameToDes.end()){
        
        return nameToDes.at(name);
    }
    static std::string s = "";
    return s;
}

int MenuData::getSize(){
    return nameVec.size();
}