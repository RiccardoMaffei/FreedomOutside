/* 
 * File:   ActionCombat.hpp
 * Author: Riccardo Maffei
 *
 * Created on 27 dicembre 2015, 14.58
 */

#ifndef ACTIONCOMBAT_HPP
#define ACTIONCOMBAT_HPP

#include "Action.hpp"


class ActionCombat: public Action{
public:
    ActionCombat();
    ActionCombat(const ActionCombat& orig);
    virtual ~ActionCombat();
private:

};

#endif /* ACTIONCOMBAT_HPP */

