/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   Item.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 17 dicembre 2015, 14.14
 */

#include <string.h>
#include "../model/Item.hpp"

Item::Item(const char name[]) {
    //copy the given name
    strcpy(this -> name, name);
}

Item::~Item() {
}

void Item::getName(char dest[]) {
    //copy the name in the destination array
    strcpy (dest, name);
}
