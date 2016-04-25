//
//  Graph.cpp
//  NodesInXCode
//
//  Created by Konesavanh, Billy on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "Graph.hpp"

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source < size());
    assert(target < size());
    edges [source][target] = true;
}

template <class Type>
void Graph<Type> :: addVertex(const Type& label)
{
    int newVertexNumber;
    int otherNumber;
    
    assert(size() < MAXIMUM);
    
    newVertexNumber = manyVertices;
    ++manyVertices;
    
    for(otherNumber = 0; otherNumber < manyVertices; otherNumber++)
    {
        edges [otherNumber] [newVertexNumber] = false;
        edges [newVertexNumber] [otherNumber] = false;
    }
    
    label [newVertexNumber] = label;
}

template <class Type>
bool Graph<Type> :: isEdge(int source, int target) const
{
    bool connected = false;
    
    assert(source < size() && target < size());
    connected = edges [source] [target];
    
    return connected;
}
