/*
 * Node.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: bkon4208
 */

#include "Node.h"


template <class Type>
Node<Type> :: Node()
{
	pointers = nullptr;
}

template <class Type>
Node<Type> :: Node(const Type& value)
{
	this -> value = value;
	pointers = nullptr;
}

template <class Type>
Node<Type>::~Node()
{
	// TODO Auto-generated destructor stub
}

/*
 * Gets the values for the node.
 */
template <class Type>
Type Node<Type> :: getValue()
{
	return this -> value;
}

/*
 * Sets the values for the node.
 */
template <class Type>
void Node<Type> :: setValue(const Type& value)
{
	this ->value = value;
}

/*
 * Node points to another node
 */
template <class Type>
Node<Type> * Node<Type> :: getPointers()
{
	return this -> pointers;
}

