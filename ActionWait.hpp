/* 
 * File:   ActionWait.hpp
 * Author: Federico Bertani
 *
 * Created on 29 dicembre 2015, 19.03
 */

#ifndef ACTIONWAIT_HPP
#define	ACTIONWAIT_HPP

#include "Action.hpp"

/**
 * The action of doing nothing for a turn.
 */
class ActionWait : public Action {
public:
    /**
     * ActionWait constructor
     */
    ActionWait();
    
    /**
     * ActionWait destructor.
     */
    virtual ~ActionWait();
    
    /**
     * do nothing
     */
    virtual void execute();
    
     /**
     * return a description of the action.
     * @param dest[] char: the string that will be filled with the description. <br> must be 255 long. 
     */
    virtual void getDescription(char dest[]);
    
    /**
     * Get the action outcome.
     * @return FedeList&lt;char**&gt;*: a string list that contains the outcome of the action.
     */
    virtual void getOutcome(FedeList<char*>* outcome);


private:

};

#endif	/* ACTIONWAIT_HPP */

