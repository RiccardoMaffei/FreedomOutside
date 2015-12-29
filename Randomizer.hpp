/* 
 * File:   Randomizer.hpp
 * Author: Riccardo Maffei
 *
 * Created on 29 dicembre 2015, 2.23
 */

#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include "FedeList.hpp"
#include "Item.hpp"
/**
 * This class contains Game randomization core. Every random generation in the game should be handled here.
 * This class may use game difficulty to edit statistics.
 */
class Randomizer {
public:
    
    /**
     * Generate a random list of items and save it to the given list.
     * This is used for room generation.
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    static void generateRoomItems(FedeList<Item*>* items);
private:
    Randomizer();
    Randomizer(const Randomizer& orig);
    virtual ~Randomizer();
};

#endif /* RANDOMIZER_HPP */

