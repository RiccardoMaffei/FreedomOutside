/* 
 * File:   ConsoleView.hpp
 * Author: Riccardo Maffei
 * Author: Danilo Branca
 *
 * Created on 21 dicembre 2015, 1.52
 */

#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include "View.hpp"
#include "FedeList.hpp"
#include <iostream>
#include <cstring>
using namespace std;

/**
 * Console view for the game.
 */
class ConsoleView: public View{
public:
    /**
     * Construct a console view
     */
    ConsoleView();
    
    /**
     * Console view destructor
     */
    virtual ~ConsoleView();
    
    /**
     * Ask the username and copies it in dest.
     * @param dest char[]: an array big enough to hold the username.
     */
    void getUsername(char dest[]);
    
    /**
     * Show the game splash screen as ascii art.
     */
    virtual void showSplash();

    /**
     * Show the game intro/prologue.
     */
    virtual void showPrologue();
    
private:
    /**
     * Print text in a frame made with ascii character.
     * @param FedeList&lt;char*&gt;: a list that contain strings.
     */
    void frameText(FedeList<char*>* list);
};

#endif /* CONSOLEVIEW_HPP */

