/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: bkon4208
 */

#include "CTECArray.h"
#include <assert.h>
using namespace std;

template<class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
	this->head = nullptr;

	assert(size > 0);

	for (int index = 0; index < size; index++)
	{
		if (head != nullptr)
		{
			//We have more than one ArrayNode.
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode -> setNext(head);
			head = nextNode;
		}
		else
		{
			//This is the first node in the array.
			ArrayNode<Type> * first = new ArrayNode<Type>();
			head = first;
		}
	}
}

//Destructor
template<class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for (int index = 0; index < size; index++)
	{
		if (deleteMe->getNext() != nullptr)
		{
			head = deleteMe -> getNext();
			deleteMe -> setNext(nullptr);
		}
		delete deleteMe ->getNext();
		deleteMe = head;
	}
	delete head;
}

//Gets the size of the CTECArray.
template<class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}


//Gets the value of the node and its position.
template<class Type>
Type CTECArray<Type>::get(int position)
{
	/*Bounds check for size and negative.
	 * The call to assert checks that the position lies within
	 * the valid range of indices.  If it out of those bounds,
	 * the program will exit.
	 */
	assert(position < size && position >= 0);

	ArrayNode<Type> * current = head;
	//Inclusive because I am inside the bounds guaranteed.
	for (int spot = 0; spot <= position; spot++)
	{
		if (spot != position)
		{
			current = current->getNext();
		}
		else
		{
			return current->getValue();
		}
	}
    return current->getValue();
}

template<class Type>
void CTECArray<Type>::set(int position, const Type& value)
{
	//bounds check for size and negative.

	assert(position < size && position >= 0);

	ArrayNode<Type> * current = head;
	for (int spot = 0; spot <= position; spot++)
	{
		if (spot != position)
		{
			current = current->getNext();
		}
		else
		{
			current->setValue(value);
		}
	}
/*
 1) Assert size is greater than 0.
 2) Declare and init valid return variable.
 3) reference to head and loop.
 4) If there,return index, else go to next.
 5) Return index.
 */
template<class Type>
int CTECArray<Type> ::indexOf(Type searchValue)
    {
        assert(this->size < 0)
        int indexNotFound = -1;
        
        ArrayNode * current = head;
        
        for(int index = 0; index < this-> size; index++)
        {
            if(current-> getValue() == searchValue)
            {
                return index;
            }
            else
            {
                current = current-> getNext();
            }
        }
        
        return indexOfValue;
    }

}
