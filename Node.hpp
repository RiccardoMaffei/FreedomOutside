/* 
 * File:   Node.h
 * Author: Federico Bertani
 * Author: Riccardo Maffei
 *
 * Created on 18 dicembre 2015, 14.55
 */

#ifndef NODE_H
#define	NODE_H

#include <exception>
#include <stddef.h>

/**
 * A FedeList node.
 */
template <class ListType>
class Node {
public:
    
    /**
     * Construct a node with the given value and next/prev pointers.
     * @param value ListType: the value.
     * @param prev Node*: a pointer to the previous node.
     * @param next Node*: a pointer to the next node.
     */
    Node(ListType value, Node* prev = NULL, Node* next = NULL);
    
    /**
     * Clone the given Node.
     * @param orig Node: the original Node.
     */
    Node(const Node& orig);
    
    /**
     * Get the Node value.
     * @return ListType: returns the value of the node.
     */
    ListType getValue();
    
    /**
     * Set the next Node pointer.
     * @param node Node*: the next Node.
     */
    void setNext(Node* node);
    
    /**
     * Set the previous Node pointer.
     * @param node Node*: the previous Node.
     */
    void setPrev(Node* node);
    
    /**
     * Get the next Node pointer.
     * @return Node*: the next Node.
     */
    Node* getNext();
    
    /**
     * Get the previous Node pointer.
     * @return Node*: the previous Node.
     */
    Node* getPrev();
    
    /**
     * Node destructor.
     */
    virtual ~Node();

private:
    //the value
    ListType value;
    //pointer to the next node
    Node* next;
    //pointer to the previous node
    Node* prev;
};

#include "Node.cpp"

#endif	/* NODE_H */

