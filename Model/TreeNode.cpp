//
//  TreeNode.cpp
//  NodesInXCode
//
//  Created by Konesavanh, Billy on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "TreeNode.h"

template <class Type>
TreeNode<Type> :: TreeNode() : Node<Type>()
{
    this -> leftChild = nullptr;
    this -> rightChild = nullptr;
    this -> parent = nullptr;
}
