/* 
 * File:   ActionWait.cpp
 * Author: fede
 * 
 * Created on 29 dicembre 2015, 19.03
 */

#include "ActionWait.hpp"

ActionWait::ActionWait() {
}

ActionWait::~ActionWait() {
}

void ActionWait::execute() {

}

void ActionWait::getDescription(char dest[]) {
    strcpy(dest,"Hide somewhere.");
}

FedeList<char*>* ActionWait::getOutcome() {
    FedeList<char*>* result = new FedeList<char*>;
    const char* firstPart = "You hid yourself in the room";
    char* line = new char[strlen(firstPart)+1];
    strcpy(line,firstPart);
    result->push_back(line);
    return result;   
}


