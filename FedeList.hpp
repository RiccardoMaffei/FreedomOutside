/* 
 * File:   FedeList.h
 * Author: Federico Bertani
 * Author: Riccardo Maffei
 *
 * Created on 16 novembre 2015, 19.01
 */

#ifndef FEDELIST_H
#define	FEDELIST_H

#include <stdexcept>
#include "Node.hpp"

using namespace std;

/**
 * FedeList in a multipurpouse list implemented with a template class.
 * It's offers static adding time and linear searching time.
 * @tparam the type of element of the list.
 */
template <class ListType> 
class FedeList {
    public:
    /**
     * Create an empty FedeList.
     */
    FedeList();
    
    /**
     * Constructs a FedeList with only a node containg the given element.
     * @param element ListType: the element to put as first node.
     */
    FedeList(ListType element);
    
    /**
     * Destroy a Fedelist.
     */
    virtual ~FedeList(); 
    
    /**
     * Add an element in head of the list.
     * @param element ListType: the element to add.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* push_front(ListType element);
    
     /**
     * Add an element in tail of the list.
     * @param element ListType: the element to add.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* push_back(ListType element);
    
    /**
     * Insert an element in the given position.
     * The element is inserted <b>before</b> the element that may be in the position.
     * @param element ListType: the element to insert.
     * @param position int: the position in the list where insert the element.
     * @return FedeList*: a pointer to the list object for method chaining.
     * @throws out_of_range: throw a out of range exception if the position is invalid.
     */
    FedeList* insert(ListType element,int position);
    
    /**
     * Remove an element in the head of the list and returns it.
     * throw exception if the list is empty.
     * @return ListType*: the element in the head of the list.
     * @throws out_of_range: throw a out of range exception if the list is empty.
     */
    ListType pop_front();
    
    /**
     * Remove an element in the tail of the list and return it.
     * @return ListType*: the element in the tail of the list.
     * @throws out_of_range: throw a out of range exception if the list is empty.
     */
    ListType pop_back();
    
    /**
     * Get an element from the list in the given position.
     * @param position: the position in the list of the element to get.
     * @return ListType*: the element from the list in the given position.
     * @throws out_of_range: throw a out of range exception if the position is invalid.
     */
    ListType get(int position);
    
    /**
     * Remove from the list the element in the given position.
     * @param position int: the position in the list of the element to remove.
     * @return FedeList*: a pointer to the list object for method chaining.
     * @throws out_of_range: throw a out of range exception if the position is invalid.
     */
    FedeList* remove(int position);  
    
     /**
     * Remove from the list the element that is equal to the element given.
     * NOTE: list type comparison is made through == operator.
     * @param element ListType: the element used for the comparison.
     * @return FedeList*: a pointer to the list object for method chaining.
     */
    FedeList* removeByElement(ListType element); 
    
    /**
     * Return the size of the list.
     * @return int: the size of the list.
     */
    int getSize();
    
    //define Node<ListType>* as NodePointer
    typedef Node<ListType>* NodePointer; 
    
protected:
    //a pointer that always point to the head of the list
    NodePointer headCursor;
    //a pointer that always point to the tail of the list
    NodePointer tailCursor;
    //a sliding cursor
    NodePointer cursor;
    //the position of the cursor inside of the list, 0 based (-1 in case of empty list)
    int cursorPosition;
    //the lenght of the list
    int listSize;
    
    /**
     * This set the cursor as near as possible to the searched position.
     * @param position int: the position of the searched element.
     */
    void prepareSearch(int position);
    
    /**
     * Move the cursor to the node in the given position.
     * @param position int: the position of the node to get.
     * @return NodePointer: a pointer to the node to get.
     * @throws out_of_range: throw a out of range exception if the position is invalid.
     */
    void moveCursor(int position);
    
    /**
     * Check if the position given is valid.
     * @param position int: the position to check.
     * @return true is the position is valid, false otherwise.
     */
    bool isValidPosition(int position);
};

#include "FedeList.cpp"

#endif	/* FEDELIST_H */

