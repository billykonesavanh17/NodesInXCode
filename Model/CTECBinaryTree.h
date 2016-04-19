//
//  CTECBinaryTree.hpp
//  NodesInXCode
//
//  Created by Konesavanh, Billy on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECBinaryTree_h
#define CTECBinaryTree_h

#include "TreeNode.cpp"

template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int height;
    int size;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    void insert(const Type& value, CTECBinaryTree<Type> * currentTree);
    void calculateSize(TreeNode<Type> * currentNode);
public:
    CTECBinaryTree();   //Done
    ~CTECBinaryTree();
    bool insert(const Type& value); //Done
    bool contains(Type value);  //Done
    Type remove(const Type & value);
    int getHeight();
    int getSize();  //Done
    bool isBalanced();
    TreeNode<Type> * getRoot();
    void inorderTraversal(TreeNode<Type> * currentNode);    //Done
    void preorderTraversal(TreeNode<Type> * currentNode);   //Done
    void postorderTraversal(TreeNode<Type> * currentNode);  //Done
};



#endif /* CTECBinaryTree_h */
