/* 
 * File:   ItemHealthKit.hpp
 * Author: Riccardo Maffei
 *
 * Created on 21 dicembre 2015, 21.42
 */

#ifndef ITEMHEALTHKIT_HPP
#define ITEMHEALTHKIT_HPP
#include "Item.hpp"

class ItemHealthKit: public Item{
public:
    ItemHealthKit(char name[]);
    virtual ~ItemHealthKit();
private:

};

#endif /* ITEMHEALTHKIT_HPP */

