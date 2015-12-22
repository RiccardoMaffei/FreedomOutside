/* 
 * File:   Node.h
 * Author: fede
 *
 * Created on 18 dicembre 2015, 14.55
 */

#ifndef NODE_H
#define	NODE_H

#include <exception>
#include <stddef.h>

template <class ListType>
class Node {
public:
    Node(ListType* value,Node* prev=NULL,Node* next=NULL);
    Node(const Node& orig);
    ListType getValue();
    void setNext(Node* node);
    void setPrev(Node* node);
    Node* getNext();
    Node* getPrev();
    virtual ~Node();
private:
    ListType value;
    Node* next;
    Node* prev;
};

#include "Node.cpp"

#endif	/* NODE_H */

