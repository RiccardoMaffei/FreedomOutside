/* 
 * File:   StringUtils.hpp
 * Author: Riccardo Maffei
 *
 * Created on 23 dicembre 2015, 2.49
 */

#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP
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
 * Reverses the given string.
 * @param s char[]: string to revert.
 */
void reverse(char s[]);
#endif /* STRINGUTILS_HPP */

