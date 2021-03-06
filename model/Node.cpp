/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   Node.cpp
 * Author: Federico Bertani
 * Author: Riccardo Maffei
 * 
 * Created on 18 dicembre 2015, 14.55
 */

#ifndef NODE_CPP
#define	NODE_CPP

#include "../model/Node.hpp"

template <class ListType>
Node<ListType>::Node(ListType value, Node* prev, Node* next){
    //save the value
    this -> value = value;
    //save the previous node pointer
    this -> prev = prev;
    //save the next node pointer
    this -> next = next;
}

template <class ListType>
Node<ListType>::Node(const Node& orig){
    //copy the value
    value = orig.value;
    //copy the previous node pointer
    prev = orig.prev;
    //copy the next node pointer
    next = orig.next;
}

template <class ListType>
Node<ListType>::~Node(){
    //do nothing
}    

template <class ListType>
ListType Node<ListType>::getValue(){
    //return the value
   return value; 
}

template <class ListType>
void Node<ListType>::setPrev(Node* node){
    //save the previous node pointer
    this -> prev = node;
}

template <class ListType>
void Node<ListType>::setNext(Node* node){
    //save the next node pointer
    this -> next = node;
}

template <class ListType>
Node<ListType>* Node<ListType>::getPrev(){
    //return the previous node pointer
    return this -> prev; 
}

template <class ListType>
Node<ListType>* Node<ListType>::getNext(){
    //return the next node pointer
    return this -> next; 
}

#endif	/* NODE_H */
