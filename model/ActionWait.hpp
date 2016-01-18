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
 * File:   ActionWait.hpp
 * Author: Federico Bertani
 *
 * Created on 29 dicembre 2015, 19.03
 */

#ifndef ACTIONWAIT_HPP
#define	ACTIONWAIT_HPP

#include "../model/Action.hpp"

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
    virtual FedeList<char*>* getOutcome();


private:

};

#endif	/* ACTIONWAIT_HPP */

