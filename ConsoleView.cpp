/* 
 * File:   ConsoleView.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 1.52
 */

#include "ConsoleView.hpp"

ConsoleView::ConsoleView() {
}

ConsoleView::~ConsoleView() {
}

void ConsoleView::getUsername(char dest[]) {
    //print the prompt
    cout << "Prisoner! What's your name?\n";
    //get the destination
    cin >> dest;
}

void ConsoleView::showSplash() {
    
}
