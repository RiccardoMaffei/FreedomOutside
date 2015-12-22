/* 
 * File:   Node.cpp
 * Author: fede
 * 
 * Created on 18 dicembre 2015, 14.55
 */

#ifndef NODE_CPP
#define	NODE_CPP

#include "Node.hpp"

template <class ListType>
Node<ListType>::Node(ListType* value,Node* prev,Node* next) {
    this->value = *value;
    this->prev = prev;
    this->next = next;
}

template <class ListType>
Node<ListType>::Node(const Node& orig) {
    value = orig.value;
    prev = orig.prev;
    next = orig.next;
}

template <class ListType>
Node<ListType>::~Node() {

}    

template <class ListType>
ListType Node<ListType>::getValue() {
   return value; 
}

template <class ListType>
void Node<ListType>::setPrev(Node* node) {
    this->prev = node;
}

template <class ListType>
void Node<ListType>::setNext(Node* node) {
    this->next = node;
}

template <class ListType>
Node<ListType>* Node<ListType>::getPrev() {
   return prev; 
}

template <class ListType>
Node<ListType>* Node<ListType>::getNext() {
   return next; 
}

#endif	/* NODE_H */
