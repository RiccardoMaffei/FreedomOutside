/* 
 * File:   ConsoleView.hpp
 * Author: Riccardo Maffei
 *
 * Created on 21 dicembre 2015, 1.52
 */

#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include "View.hpp"
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
     * @param dest char[]: an array big enought to hold the username.
     */
    void getUsername(char dest[]);
private:

};

#endif /* CONSOLEVIEW_HPP */

