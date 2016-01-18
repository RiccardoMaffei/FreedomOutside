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

#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <string>
/**
 * Utility functions for string
 */

/**
 * Converts the given integer in string.
 * @param n int: the int number.
 * @param dest char[]: the destination array.
 */
void itoa(int n, char dest[]);

/**
 * Converts the given double in string using only two decimal digits.
 * @param n double: the int number.
 * @param dest char[]: the destination array.
 */
void dtoaTwo(double n, char dest[]);

/**
 * Reverses the given string.
 * @param s char[]: string to revert.
 */
void reverse(char s[]);
#endif /* STRINGUTILS_HPP */

