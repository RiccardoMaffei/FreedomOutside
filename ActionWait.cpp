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
    
}


