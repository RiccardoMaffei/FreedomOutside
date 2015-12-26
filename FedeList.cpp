/* 
 * File:   FedeList.cpp
 * Author: Federico Bertani
 * Author: Riccardo Maffei
 * 
 * Created on 8 novembre 2015, 13.46
 */

#ifndef FEDELIST_CPP
#define	FEDELIST_CPP

#include <cstdlib>
#include "FedeList.hpp"

template <class ListType>
FedeList<ListType>::FedeList(){
    //set all cursors to NULL
    headCursor = tailCursor = cursor = NULL;
    //in this way at the first push the cursor will point to the head/tail
    cursorPosition = -1;
    //set the size of the list as 0
    listSize = 0;
};

template <class ListType>
FedeList<ListType>::FedeList(ListType element){
    //call the default constructor
    FedeList();
    //push the element
    this -> push_back(element);
}

template <class ListType>
FedeList<ListType>::~FedeList(){
    //set current node as the head
    NodePointer current = headCursor;
    //while current is not NULL
    while(current != NULL){
        //set the next as the current next
        NodePointer next = current -> getNext();
        //delete the current
        delete current;
        //set the current as next
        current = next;
    }
    
}

template <class ListType>
FedeList<ListType>* FedeList<ListType>::push_front(ListType element){
    //if head cursor is not NULL
    if (headCursor != NULL){
        //create the node to add with the given element and the current head as next
        NodePointer toAdd = new Node<ListType>(element, NULL, headCursor);
        //set the node to add as the previous of the current head node
        headCursor -> setPrev(toAdd);
        //set the node to add as the head cursor
        headCursor = toAdd;
    }
    //else (empty list)
    else {
        //create the node to add with the given element and save it in head cursor
        headCursor = new Node<ListType>(element);
        //set the tail as the head
        tailCursor = headCursor;
    }
    //increase the list size
    listSize++;
    //if the list was empty (listsize == 1)
    if(listSize == 1){
        //manually set the cursor to the head
        cursor = headCursor;
        //manually set the cursor position as 0
        cursorPosition = 0;
    }
    //else (the cursor was already on an element and now it has been shifted)
    else{
        //leave the curso where it is
        //increase the cursor position
        cursorPosition++;
    }
    //return this list for method chaining
    return (this);
};

template <class ListType>
FedeList<ListType>* FedeList<ListType>::push_back(ListType element){
    //if tail cursor is not NULL
    if (tailCursor != NULL){
        //create the node to add with the given element and the current tail as prev
        NodePointer toAdd = new Node<ListType>(element, tailCursor, NULL);
        //set the node to add as the next of the current tail node
        tailCursor -> setNext(toAdd);
        //set the node to add as the tail cursor
        tailCursor = toAdd;
    }
    //else (empty list)
    else {
        //create the node to add with the given element and save it in tail cursor
        tailCursor = new Node<ListType>(element);
        //set the head as the tail
        headCursor = tailCursor;
    }
    //increase the list size
    listSize++;
    //if the list was empty (listsize == 1)
    if(listSize == 1){
        //manually set the cursor to the head
        cursor = headCursor;
        //manually set the cursor position as 0
        cursorPosition = 0;
    }
    //return this list for method chaining
    return (this);
};

template <class ListType>
FedeList<ListType>* FedeList<ListType>::insert(ListType element, int position){
    //if the position is between 0 and the size of the list (internal))
    if ((position > 0) && (position < listSize)){
        //move the cursor over the position
        moveCursor(position);
        //create a new node with the given element, the previous and the current (future next) node
        NodePointer nodeToInsert = new Node<ListType>(element, cursor -> getPrev(), cursor);
        //set the node to insert as the next of the previous
        cursor -> getPrev() -> setNext(nodeToInsert);
        //set the node to insert as the previous
        cursor -> setPrev(nodeToInsert);
        //increase the cursor position
        cursorPosition++;
        //increase the list size
        listSize++;
    }
    //else if the position is 0
    else if(position == 0){
        //push front
        push_front(element);
    }
    //else if the position is listsize (wanna append)
    else if(position == listSize){
        //push back
        push_back(element);
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("position out of range"));
    }
    //return this list for method chaining
    return (this);
};

template <class ListType>
ListType FedeList<ListType>::pop_front(){
    //the result
    ListType result;
    //if there is at least 1 element (listSize > 0)
    if (listSize > 0){
        //save the result value
        result = headCursor -> getValue();
        //save the node to delete
        NodePointer toDelete = headCursor;
        //if there is more than 1 element
        if (listSize > 1){
            //if the cursor is pointing to the head
            if(cursor == headCursor){
                //move the cursor to the future head
                cursor = cursor -> getNext();
                //do not change cursor position
            }
            //else (the cursor is ahead)
            else{
                //decrease the cursor position
                cursorPosition--;
            }
            //set head cursor as the next of the current head cursor
            headCursor = headCursor -> getNext();
            //set the previous of the head cursor as NULL
            headCursor -> setPrev(NULL);
        } 
        //else (only one element)
        else {
            //set head cursor, cursor and tail cursor as NULL
            cursor = headCursor = tailCursor = NULL;
            //set the cursor position as -1 (empty list)
            cursorPosition = -1;
        }
        //delete the node to delete
        delete toDelete;
        //decrease the list size
        listSize--;
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("the list is empty"));
    }
    //return the result
    return result;
}

template <class ListType>
ListType FedeList<ListType>::pop_back(){
    //the result
    ListType result;
    //if there is at least 1 element (listSize > 0)
    if (listSize > 0){
        //if the cursor is pointing to the tail
        if(cursor == tailCursor){
            //move the cursor to the future tail
            cursor = cursor -> getPrev();
            //decrease the cursor position
            cursorPosition--;
        }
        //else (the cursor is behind): do nothing
        //save the result value
        result = tailCursor -> getValue();
        //save the node to delete
        NodePointer toDelete = tailCursor;
        //if there is more than 1 element
        if (listSize > 1){
            //set tail cursor as the previous of the current tail cursor
            tailCursor = tailCursor -> getPrev();
            //set the next of the tail cursor as NULL
            tailCursor -> setNext(NULL);
        }
        //else (only one element)
        else {
            //set head cursor, tail cursor and cursor as NULL
            headCursor = tailCursor = cursor = NULL;
            //cursor position is already set as -1
        }
        //delete the node to delete
        delete toDelete;
        //decrease the list size
        listSize--;
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("the list is empty"));
    }
    //return the result
    return result;
}

template <class ListType>
ListType FedeList<ListType>::get(int position){
    //move the cursor to the position if exists. It throws an exception otherwise.
    moveCursor(position);
    //return the value in the given position
    return cursor -> getValue();
}

template <class ListType>
FedeList<ListType>* FedeList<ListType>::remove(int position){
    //if the position is valid
    if (isValidPosition(position)){
        //if the given position is 0 (first element)
        if (position == 0){
            //pop from the front
            pop_front();
        }
        //else if the position is listSize - 1 (last element)
        else if (position == (listSize - 1)){
            //pop from the back
            pop_back();
        }
        //else (internal position)
        else {
            //move the cursor to the position
            moveCursor(position);
            //the node to delete
            NodePointer toDelete = cursor;
            //---- bypass the node to delete ----
            //save the previous
            NodePointer previus = toDelete -> getPrev();
            //save the next
            NodePointer next = toDelete -> getNext();
            //set the next of previous as next
            previus -> setNext(next);
            //set the previous of next as previous
            next -> setPrev(previus);
            //---- end bypass ----
            //set the cursor as next (should not be nullbecause is checked if it is or not the last element)
            //(can't use moveCursor because cursorPosition must remain the same)
            cursor = next; 
            //delete the node to delete
            delete toDelete;
            //decrease the list size
            listSize--;
        }
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("position out of range"));
    }
    //return this list for method chaining
    return (this);
}

template<class ListType>
FedeList<ListType>* FedeList<ListType>::removeByElement(ListType element){
    //int counter set as 0
    int i = 0;
    //found element? default: false
    bool found = false;
    //while not found and the counter is less than the list size
    while ((!found) && (i<listSize)){
        //move the cursor to the i position
        moveCursor(i);
        //if the value in the pointed node is equal to the searched element
        if (cursor -> getValue() == element){
            //set the found as true
            found = true;
        } 
        //else
        else{
            //increase the counter
            i++;
        }
    }
    //if the ites has been found
    if(found){
        //remove the element
        remove(i);
    }
    //return this list for method chaining
    return (this);
}


template <class ListType>
int FedeList<ListType>::getSize(){
    //return the list size
    return listSize;
};

template <class ListType>
void FedeList<ListType>::prepareSearch(int position){
    //compute the distance between the current cursor position and the searched position
    int cursorDistance = abs(cursorPosition-position);
    //the distance position-head is position
    int headDistance = position;
    //the distance position-head is position
    int tailDistance = (listSize - 1 - position);
    //if the distance between the position to get and the head/tail is less thant the distance
    //between cursor and position we can make an optimization.
    if ((headDistance < cursorDistance) || (tailDistance < cursorDistance)){
        //if head distance is less than tail distance
        if (headDistance <= tailDistance){
            //set the cursor as the head
            cursor = headCursor;
            //set cursor position as 0
            cursorPosition = 0;
        }
        //else if tail distance is less than head distance
        else {
            //set the cursor as the tail
            cursor = tailCursor;
            //set cursor position as list size - 1
            cursorPosition = (listSize - 1);
        }
    }
}

template<class ListType>
void FedeList<ListType>::moveCursor(int position){
    //if the position is valid
    if (isValidPosition(position)){
        //prepare to search
        prepareSearch(position);
        //check if the position is ahead to the cursor
        bool isPositionAhead = cursorPosition<position;
        //while the cursor position is not equal than the position
        while (cursorPosition != position){
            //if the position is ahead
            if (isPositionAhead){
                //move the cursor ahead
                cursor = cursor -> getNext();
                //increase the cursor position
                cursorPosition++;
            } 
            //else (position is before the cursor)
            else {
                //move the cursor back
                cursor = cursor -> getPrev();
                //decrease the cursor position
                cursorPosition--;
            }
        }
    }
    //else (not valid position)
    else{
        //throw an exception
        throw (std::out_of_range("position out of range"));
    }
}

template<class ListType>
bool FedeList<ListType>::isValidPosition(int position){
    //check and return if the position is between and listize-1 (if the size is zero it will always return false)
    return ((position >= 0) && (position <= (listSize - 1)));
}



#endif	/* FEDELIST_CPP */