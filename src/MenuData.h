#ifndef MenuData_H
#define MenuData_H

#include "ActionData.h"

#include <map>

typedef void(*ActionFunctionType) (ActionData& action_data);

class MenuData{
    public:
    MenuData();
    void addAction(const std::string& name, ActionFunctionType func, const std::string& desctiption);
    const std::vector<std::string>& getNames( ) const;
    ActionFunctionType getFunction(const std::string& name);
    const std::string& getDescription(const std::string& name);
    int getSize();

    private:
        std::vector<std::string> nameVec;
        std::map<std::string,ActionFunctionType> nameToFun;
        std::map<std::string, std::string> nameToDes;

};

#endif