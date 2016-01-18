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
 * File:   StringUtils.hpp
 * Author: Riccardo Maffei
 *
 * Created on 23 dicembre 2015, 2.49
 */

#include <string.h>
#include <stdlib.h>

#include "../model/StringUtils.hpp"
using namespace std;

void itoa(int n, char dest[]){
    //the iteration counter i 
    int i = 0;
    //the sign (the number before abs)
    bool negative = (n < 0);
    //if the number was negative
    if (n < 0){
        //negate the number
        n = -n;
    }
    //do!
    do {
        //set dest[i] as the char representation of the number modulo 10 and then increase i
        dest[i++] = n % 10 + '0';
        //divide the number by 10
        n /= 10;
    }
    //while n > 0
    while (n > 0);
    //ifthe number was negative
    if (negative){
        //set the minus char representation and increase the conuter i
        dest[i++] = '-';
    }
    //add a null byte at the end of the string
    dest[i] = '\0';
    //reverse the generated string
    reverse(dest);
}

void reverse(char s[]){
    //int i and j counters
    int i, j;
    //temporary char var
    char temp;
    //for the 
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        //save s[i] in temp
        temp = s[i];
        //save s[j] in s[i]
        s[i] = s[j];
        //save temp in s[j]
        s[j] = temp;
    }
}

void dtoaTwo(double n, char dest[]){
    //get n as a int number, (we want 2 digit precision).
    n = n * 100;
    //convert the int to a string troncating the bigger precision digits.
    itoa(n,dest);
    int dimension;
    //add 0 if the string is smaller than 3 character
    while ((dimension = strlen(dest))<3) {
        //allocate a buffer of 37 character.
        //40 is because the max double can be written with 39 character + /0
        char* prefix = new char[40];
        strcpy(prefix,"0");
        strcat(prefix,dest);
        strcpy(dest,prefix);
    }
    //don't want to use a cicle for 2 character
    //copy the string ending
    dest[dimension+1] = dest[dimension]; 
    dest[dimension] = dest[dimension-1];
    dest[dimension-1] = dest[dimension-2];
    //ad the point to separate int part to decimal.
    dest[dimension-2] = '.';
}