//
//  HashTable.hpp
//  NodesInXCode
//
//  Created by Konesavanh, Billy on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "CTECArray.cpp"
#include "HashNode.cpp"

template <class Type>
class HashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    Type * internalStorage;
    HashNode<Type> internalArray;
    
    int findPosition(HashNode<Type>  currentNode);
    int handleCollision(HashNode<Type>  currentNode);
    void updateSize();
    
public:
    HashTable();
    ~HashTable();
    
    void add(HashNode<Type>  currentNode);
    bool remove(HashNode<Type>  currentNode);
    bool contains(HashNode<Type>  currentNode);
    int getSize();
    
};

#endif /* HashTable_hpp */
