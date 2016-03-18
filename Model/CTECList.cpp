/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: bkon4208
 */

#include "CTECList.h"
#include <assert.h>

template<class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

/*
 * 1: Start at head
 * 2: Iterate over nodes
 * 3: Update position, then delete
 * 4: Delete final
 * 5: reset size, head, end default
 */

template<class Type>
CTECList<Type>::~CTECList()
{
	ArrayNode<Type> * current = head;

	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type> * temp = current;

		current = current -> getNext();
		head = current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}

template<class Type>
int CTECList<Type>:: getSize()
{
	this -> calculateSize();
	return this -> size;
}

/*
 * 1. Creates a new ArrayNode with value and head.
 * 2. Updates head.
 * 3. Updates size.
 */
template<class Type>
void CTECList<Type>:: addToFront(const Type& value)
{
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value, head);
	head = newNode;

	calculateSize();
}


/*
 * 1. Creates new ArrayNode<Type> with the supplied value.
 * 2. Adds the node to the end.
 * 3. Updates end.
 * 4. updates size.
 */
template<class Type>
void CTECList<Type>:: addToEnd(const Type& value)
{
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
	end -> setNext(newNode);
	end = newNode;

	calculateSize();

}

template<class Type>
void CTECList<Type>:: addAtIndex(int index, const Type& value)
{
	Type thingToAdd;
		assert(size > 0 && index >= 0 && index < size);

		ArrayNode<Type> * previous, next;
			if(index == 0)
			{
                ArrayNode<Type> * newNode = new ArrayNode<Type>(value, head);
                head = newNode;
			}
			else if(index == size - 1)
			{
                ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
                end -> setNext(newNode);
                end = newNode;
			}
			else
			{
				for(int spot = 0; spot < index + 1; spot++)
				{

				}
			}

			this -> calculateSize();
			return thingToAdd;
}

template <class Type>
Type CTECList<Type>:: getFront()
{
	if(index == 0)
	{
	return head -> getValue();
	}

}

template<class Type>
Type CTECList<Type>:: getEnd()
{
        if(index == size - 1)
        {
            return head -> getValue();
        }
}

template<class Type>
Type CTECList<Type>:: getFromIndex(int index)
{
	Type thingToGet;
	assert(size > 0 && index >= 0 && index < size);

	ArrayNode<Type> * previous, next;
		if(index == 0)
		{
			thingToGet = getFront();
		}
		else if(index == size - 1)
		{
			thingToGet = getEnd();
		}
		else
		{
			for(int spot = 0; spot < index + 1; spot++)
			{

			}
		}

		this -> calculateSize();
		return thingToGet;
}

template<class Type>
Type CTECList<Type>:: removeFromFront()
{
	Type thingToRemove; //In case we need to use the value we are removing.
	assert(size > 0);
	//Create a pointer to what is after head.
	//Find the next spot
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = head->getNext();
	//Get what was in the head node
	thingToRemove = head -> getValue();
	//Delete what head is pointing to.
	//Remove head
	delete head;
	//Set head to the new head.
	//Move head to the next spot.
	head = newHead;

	size--;

	this -> calculateSize();
	return thingToRemove;
}

template<class Type>
Type CTECList<Type>:: removeFromEnd()
{
	//Check for size == 1 it is a special case
	//Loop over size
	//or
	//Loop until getNext()->getNext() == nullptr.
	//Grab the value from the last node
	//set the next to last node as end
	//delete the old last node
	//Before return the variable call calculateSize().
	assert(size > 0);
	Type thingToRemove;

	if(size == 1)
	{
		thingToRemove = removeFromFront();
		end = nullptr;
		calculateSize();
		return thingToRemove;
	}
	else
	{
	ArrayNode<Type> * current = head;

	for(int spot = 0; spot < size -1; spot++)
	{
		current = current -> getNext();
	}

//Another way to do this
//	ArrayNode<Type> * pointer = head;
//	while(pointer -> getNext() -> getNext() != nullptr)
//	{
//		pointer = pointer -> getNext();
//	}

	thingToRemove = current -> getNext() -> getValue();
	end = current;
	delete current -> getNext();

	this -> calculateSize();
	return thingToRemove;
	}
}

template<class Type>
Type CTECList<Type>:: removeFromIndex(int index)
{

	Type thingToRemove;

	assert(size > 0);
	assert(index >= 0);
	assert(index < size);
	assert(size > 0 && index >= 0 && index < size); // same as the three above

	ArrayNode<Type> * previous, deleteMe, newNext;
	if(index == 0)
	{
		thingToRemove = removeFromFront();
	}
	else if(index == size - 1)
	{
		thingToRemove = removeFromEnd();
	}
	else
	{
		for(int spot = 0; spot < index + 1; spot++)
		{

		}
	}

	this -> calculateSize();
	return thingToRemove;
}

/**
 * Calculates the size of the list by iterating over all of the nodes in the list.
 */
template<class Type>
void CTECList<Type> :: calculateSize()
{
	assert(size >= 0);

	ArrayNode<Type> * counterPointer = head;
	int count = 0;
	if(counterPointer == nullptr)
	{
		this -> size = 0;
		return;
	}
	else
	{
		count ++;
		while(counterPointer -> getNext() != nullptr)
			{
				counterPointer = counterPointer -> getNext();
				count ++;
			}
		this -> size = count;
	}

}

template<class Type>
Type CTECList<Type>:: set(int index, const Type& value)
{
	assert(index < size && index >= 0);

		ArrayNode<Type> * current = head;
		for (int spot = 0; spot <= index; spot++)
		{
			if (spot != index)
			{
				current = current->getNext();
			}
			else
			{
				current->setValue(value);
			}
		}

}

template <class Type>
int CTECList<Type> :: indexOf(Type searchValue)
{
    assert(this -> size > 0);
    int index = 0;
    ArrayNode<Type> * searchPointer;
    
    for(searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer -> getNext())
    {
        if(searchValue == searchPointer -> getValue())
        {
            return index;
        }
         index++;
    }
    index = -1;
    
    return index;
}