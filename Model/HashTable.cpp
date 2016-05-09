//
//  HashTable.cpp
//  NodesInXCode
//
//  Created by Konesavanh, Billy on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "HashTable.hpp"
#include <cmath>

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new HashNode<Type>[capacity];
}

template <class Type>
HashTable<Type> :: ~HashTable<Type>()
{
    delete [] internalStorage;
}

template <class Type>
int HashTable<Type> :: getSize()
{
    return this-> size;
}

template <class Type>
void HashTable<Type> :: add(HashNode<Type>  currentNode)
{
    if(!contains(currentNode))
    {
        //update size if needed.
        if(this-> size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        //Find where to put the value.d
        int positionToInsert = findPosition(currentNode);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            //Loop over the internalStorage to find the next empty slot.
            //Wrap if needed
            //Insert the value there.
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
                
            }
        }
    
            internalStorage[positionToInsert] = currentNode;
    }
}

/*
 *Very basic hashing algorithm.
 *Simply assigns a position based on modulo math.
 */
template <class Type>
int HashTable<Type> :: findPosition(HashNode<Type>  currentNode)
{
    //We are going to "hash" the key of the HashNode to find its storage spot.
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}

template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
bool HashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    
    if(candidateNumber < 1)
    {
        return false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if(candidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    else
    {
        for(int next = 3; next <= sqrt(candidateNumber) + 1; next += 2)
        {
            if(candidateNumber % next == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    return isPrime;
}

template <class Type>
void HashTable<Type> :: updateSize()
{
    int updatedCapacity = getNextPrime();
    HashNode<Type> updatedStorage = new HashNode<Type> [updatedCapacity];
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
    }
    
    internalStorage = updatedStorage;
}
