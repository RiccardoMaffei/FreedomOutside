/* 
 * File:   View.hpp
 * Author: Riccardo Maffei
 *
 * Created on 22 dicembre 2015, 16.28
 */

#ifndef VIEW_HPP
#define VIEW_HPP

/**
 * The view interface.
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
private:

};

#endif /* VIEW_HPP */

