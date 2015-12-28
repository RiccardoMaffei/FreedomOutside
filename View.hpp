/* 
 * File:   View.hpp
 * Author: Riccardo Maffei
 *
 * Created on 22 dicembre 2015, 16.28
 */

#ifndef VIEW_HPP
#define VIEW_HPP

#include "Action.hpp"
#include "FedeList.hpp"
/**
 * The view interface.It has the methods that every view(console,2d,3d,...) should have.
 */
class View {
public:
    View();
    virtual ~View();
    
    /**
     * Ask the username and copies it in dest.
     * @param dest char[]: an array big enough to hold the username.
     */
    virtual void getUsername(char dest[]) = 0;
    
    /**
     * Show the game splash screen.
     */
    virtual void showSplash() = 0;
    
    /**
     * Show the game intro/prologue.
     */
    virtual void showPrologue() = 0;
    
    /**
     * Show actions and retriever the selected action.
     * @param actions FedeList&lt;Action*&gt;*: the action list.
     * @return Action*: the action selected by the user.
     */
    virtual Action* selectAction(FedeList<Action*>* actions) = 0;
private:

};

#endif /* VIEW_HPP */

