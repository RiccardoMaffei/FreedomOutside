/* 
 * File:   FedeList.cpp
 * Author: Federico Bertani
 * 
 * Created on 8 novembre 2015, 13.46
 */

#ifndef FEDELIST_CPP
#define	FEDELIST_CPP

#include <cstdlib> //for abs() function
#include <climits>
#include "FedeList.hpp"

template <class ListType>
FedeList<ListType>::FedeList() {
    headCursor = NULL;
    cursor = headCursor;
    tailCursor = headCursor;
    //in this way at the first push the cursor will point to the head/tail
    cursorPosition = INT_MAX; 
    listSize = 0;
};

template <class ListType>
FedeList<ListType>::FedeList(ListType element) {
    FedeList();
    this->push_back(element);
}

template <class ListType>
FedeList<ListType>::FedeList(const FedeList& orig) {
    FedeList();
    //i can't access orig nodes 'cause it would change orig and it's const for c++ standard.
    //so i create a tmpCopy that point to same nodes but i can modify it.
    FedeList<ListType> tmpCopy = FedeList<ListType>();
    tmpCopy.headCursor = orig.headCursor;
    tmpCopy.cursor = orig.headCursor;
    tmpCopy.listSize = orig.listSize;
    int originSize = orig.getSize();
    for (int i = 0; i < originSize; i++) {
        this->push_back(*(tmpCopy.get(i)));
    }
}

template <class ListType>
FedeList<ListType>::~FedeList() {
    moveCursor(0);
    NodePointer cursorToDelete;
    for (int i = 0; i < listSize; i++) {
        cursorToDelete = cursor;
        moveCursor(i);
        delete cursorToDelete;
        listSize--;
    }
}

template <class ListType>
FedeList<ListType>* FedeList<ListType>::push_front(ListType element) {
    if (headCursor != NULL) {
        NodePointer tmp = new Node<ListType>(&element, (Node<ListType>*)NULL, headCursor);
        headCursor->setPrev(tmp);
        headCursor = tmp;
    } else {
        headCursor = new Node<ListType>(&element);
        tailCursor = headCursor;
    }
    listSize++;
    moveCursor(0);
    return (this);
};

template <class ListType>
FedeList<ListType>* FedeList<ListType>::push_back(ListType element) {
    if (tailCursor != NULL) {
        NodePointer tmp = new Node<ListType>(&element, tailCursor);
        tailCursor->setNext(tmp);
        tailCursor = tmp;
    } else {
        tailCursor = new Node<ListType>(&element);
        headCursor = tailCursor;
    }
    listSize++;
    moveCursor(0);
    return (this);
};

template <class ListType>
FedeList<ListType>* FedeList<ListType>::insert(ListType element, int position) throw (exception) {
    if ((listSize > 0) && (position < listSize)) {
        moveCursor(position);
        Node<ListType>* node = new Node<ListType>(&element, cursor->getPrev(), cursor);
        if (cursor->getPrev() != NULL) {
            cursor->getPrev()->setNext(node);
        } else {
            headCursor = node; //inserting in position 0, we need to update headcursor
        }
        cursor->setPrev(node);
        cursorPosition++;
        listSize++;
    } else {
        if (isValidPosition(position)) { //because it can be >listSize
            push_back(element);
        }
    }
    return (this);
};

template <class ListType>
ListType FedeList<ListType>::pop_front() throw (exception) {
    if (listSize > 0) {
        ListType valueToReturn = headCursor->getValue();
        NodePointer toDelete = headCursor;
        if (listSize > 1) {
            headCursor = headCursor->getNext();
            headCursor->setPrev((Node<ListType>*)NULL);
        } else {
            headCursor = NULL;
            tailCursor = NULL;
        }
        delete toDelete;
        cursor = headCursor; //in this way cursor wil never point to a inexisting node
        cursorPosition = 0;
        listSize--;
        return valueToReturn;
    } else throw (exception());
}

template <class ListType>
ListType FedeList<ListType>::pop_back() throw (exception) {
    if (listSize > 0) {
        ListType valueToReturn = tailCursor->getValue();
        NodePointer toDelete = tailCursor;
        if (listSize > 1) {
            tailCursor = tailCursor->getPrev();
            tailCursor->setNext((Node<ListType>*)NULL);
        } else {
            headCursor = NULL;
            tailCursor = NULL;
            cursor = NULL;
            cursorPosition = 0;
        }
        delete toDelete;
        cursor = tailCursor; //in this way cursor will never point to a inexisting node
        cursorPosition = listSize-1;
        listSize--;
        return valueToReturn;
    } else throw (exception());
}

template <class ListType>
ListType FedeList<ListType>::get(int position) throw (exception) {
    moveCursor(position);
    return cursor->getValue();
}

template <class ListType>
FedeList<ListType>* FedeList<ListType>::remove(int position) throw (exception) {
    const int lastElement = listSize - 1;
    //needed to use nested if instead of switch because switch can't be used with values that changes at run-time
    //like listSize
    if (position == 0) {
        pop_front();
    } else if (position == lastElement) {
        pop_back();
    } else {
        moveCursor(position);
        NodePointer toDelete = cursor;
        //doing bypass of node to delete
        NodePointer previus = cursor->getPrev();
        NodePointer next = cursor->getNext();
        previus->setNext(next);
        next->setPrev(previus);
        cursor = next; //can't use moveCursor because cursorPosition must remain the same.
        delete toDelete;
        listSize--;
    }
    return (this);
}

template<class ListType>
FedeList<ListType>* FedeList<ListType>::removeByElement(ListType element){
    //int counter set as 0
    int i = 0;
    //found element? default: false
    bool found = false;
    //while not found and the counter is less than the list size
    while ((!found) && (i<listSize)) {
        //move the cursor to the i position
        moveCursor(i);
        //if the value in the pointed node is equal to the searched element
        if (cursor->getValue() == element) {
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
void FedeList<ListType>::prepareSearch(int position) {
    //compute the distance between the current cursor position and the searched position
    int cursorDistance = abs(cursorPosition-position);
    //the distance position-head is position
    int headDistance = position;
    //the distance position-head is position
    int tailDistance = (listSize-position);
    //if the distance between the position to get and the head/tail is less thant the distance
    //between cursor and position we can make an optimization.
    if ((headDistance < cursorDistance) && (tailDistance < cursorDistance))
        //if head distance is less than tail distance
        if (headDistance <= tailDistance) {
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

template<class ListType>
void FedeList<ListType>::moveCursor(int position) throw (exception) {
    //if the position is valid
    if (isValidPosition(position)){
        //prepare to search
        prepareSearch(position);
        //check if the position is ahead to the cursor
        bool isPositionAhead = cursorPosition<position;
        //while the cursor position is not equal than the position
        while (cursorPosition != position) {
            //if the position is ahead
            if (isPositionAhead) {
                //move the cursor ahead
                cursor = cursor->getNext();
                //increase the cursor position
                cursorPosition++;
            } 
            //else (position is before the cursor)
            else {
                //move the cursor back
                cursor = cursor->getPrev();
                //decrease the cursor position
                cursorPosition--;
            }
        }
    }
    //else
    else{
        //throw an exception
        throw (exception());
    }
}

template<class ListType>
bool FedeList<ListType>::isValidPosition(int position){
    //check and return if the position is between and listize-1 (if the size is zero it will always return false)
    return ((position >= 0) && (position <= (listSize - 1)));
}



#endif	/* FEDELIST_CPP */