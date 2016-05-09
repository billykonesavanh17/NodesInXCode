//
//  HashNode.hpp
//  NodesInXCode
//
//  Created by Konesavanh, Billy on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <stdio.h>
#include <iostream>  // For nullptr

template <class Type>
class HashNode
{
private:
    int key;
    Type value;
    
public:
    HashNode(int key, const Type& value);
    void setKey(int key);
    void setValue(Type& value);
    int getKey();
    Type getValue();
    
};

#endif /* HashNode_hpp */
