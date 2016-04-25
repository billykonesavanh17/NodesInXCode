//
//  Graph.hpp
//  NodesInXCode
//
//  Created by Konesavanh, Billy on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <set>

template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool edges [MAXIMUM] [MAXIMUM];
    Type labels [MAXIMUM];
    int manyVertices;
public:
    Graph();
    virtual ~Graph();
    void addVertex(const Type& label);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator [] (int vertex);
    int size() const;
    
    bool isEdge(int source, int target) const;
    std::set<int> neighbrs(int vertex);
    Type operator [] (int vertex) const;
};

#endif /* Graph_hpp */
