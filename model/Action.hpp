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
 * File:   Action.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.58
 */

#ifndef ACTION_HPP
#define	ACTION_HPP

#include <string.h>
#include "../model/FedeList.hpp"

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

