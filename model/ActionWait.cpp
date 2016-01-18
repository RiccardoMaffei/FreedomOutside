/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   ActionWait.cpp
 * Author: Federico Bertani
 * 
 * Created on 29 dicembre 2015, 19.03
 */

#include "../model/ActionWait.hpp"

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


