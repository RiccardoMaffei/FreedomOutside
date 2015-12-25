/* 
 * File:   Action.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.58
 */

#ifndef ACTION_HPP
#define	ACTION_HPP

/**
 * Action interface.
 */
class Action {
public:
    Action();
    virtual ~Action();
    
    /**
     * Execute the action.
     */
    virtual void execute() = 0;
    
    /**
     * Get the Action escription. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    virtual void getDescription(char dest[]) = 0;
    
private:

};

#endif	/* ACTION_HPP */

