/* 
 * File:   ItemArmor.hpp
 * Author: Riccardo Maffei
 *
 * Created on 18 dicembre 2015, 12.33
 */

#ifndef ITEMARMOR_HPP
#define ITEMARMOR_HPP

#include "Item.hpp"


class ItemArmor : public Item {
public:
    ItemArmor();
    ItemArmor(const ItemArmor& orig);
    virtual ~ItemArmor();
private:

};

#endif /* ITEMARMOR_HPP */

