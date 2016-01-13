/* 
 * File:   Action.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.58
 */

#ifndef ACTION_HPP
#define	ACTION_HPP

#include <string.h>
#include "FedeList.hpp"

/**
 * Executable Action interface.
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
     * Get the Action description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    virtual void getDescription(char dest[]) = 0;
    
    //TODO: check in every action if it has been executed or not.
    /**
     * Get the action outcome.
     * Remeber to deallocate every pointer of the list.
     * @return FedeList&lt;char**&gt;*: a string list that contains the outcome of the action.
     */
    virtual FedeList<char*>* getOutcome() = 0;
private:

};

#endif	/* ACTION_HPP */

