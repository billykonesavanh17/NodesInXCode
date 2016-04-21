//
//  CTECBinaryTree.cpp
//  NodesInXCode
//
//  Created by Konesavanh, Billy on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//


#include "CTECBinaryTree.h"
using namespace std;

template <class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

template <class Type>
bool CTECBinaryTree<Type> :: insert(const Type& value)
{
    TreeNode<Type> * insertedNode(value);
    TreeNode<Type> * current;
    TreeNode<Type> * trailingCurrent;
    assert(insertedNode != nullptr);
    if(contains (value))
    {
        return false;
    }
    else
    {
        if(root == nullptr)
        {
            root = insertedNode;
        }
    
        else
        {
            current = root;
            
            while(current != nullptr)
            {
                trailingCurrent = current;
                
                if(current -> getValue() > value)
                {
                    current = current -> getLeftChid();
                }
                else
                {
                    current = current -> getRightChild();
                }
            }
            if(trailingCurrent -> getValue() > value)
            {
                trailingCurrent -> setLeftChild(insertedNode);
            }
            else
            {
                trailingCurrent -> setRightChild(insertedNode);
            }
            insertedNode -> setParent(trailingCurrent);
        }
    }
        
        return true;
    
}


template <class Type>
void CTECBinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type> * current = root;
    TreeNode<Type> * trailing = current;
    if(!contains(value))
    {
        return;
    }
    else
    {
        while(current != nullptr && current -> getValue() != value)
        {
            trailing = current;
            if(current -> getValue() > value)
            {
                current = current -> getLeftChild();
            }
            else
            {
                current = current -> getRightChild();
            }
        }
            
            if(current == root)
            {
                remove(root);
            }
            else if(trailing -> getValue() > value)
            {
                remove(trailing -> getLeftChild);
            }
            else
            {
                remove(trailing -> getRightChild);
            }
    }
}

template <class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode -> getLeftChild());
        cout << currentNode -> getValue() << " ";
        inorderTraversal(currentNode -> getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode -> getValue() << " ";
        preorderTraversal(currentNode -> getLeftChild());
        preorderTraversal(currentNode -> getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postorderTraversal(currentNode -> getLeftChild());
        postorderTraversal(currentNode -> getRightChild());
        cout << currentNode -> getValue() << " ";
    }
}

template <class Type>
int CTECBinaryTree<Type> :: getSize()
{
    calculateSize(root);
    return size;
}


template <class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode -> getLeftChild());
        calculateSize(currentNode -> getRightChild());
        size++;
    }
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    /*
     Is the value in the root? - return true else
     If the value is not in the root and is less than root - call contains on left child.
     Else if the value is not in the root and is greater than root - call contains on right child.
     */
    bool isInTree = false;
    if(root -> getValue() == value)
    {
        return true;
    }
    else if(value < root -> getValue())
    {
        isInTree == contains(value, root -> getLeftChild());
    }
    else
    {
        isInTree == contains (value, root -> getRightChild());
    }
    return isInTree;
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    /*
     Is the value in the root? - return true else
     If the value is not in the root and is less than root - call contains on left child.
     Else if the value is not in the root and is greater than root - call contains on right child.
     */
    if(currentTree == nullptr)
    {
        return false;
    }
    
    if(currentTree -> getRoot() -> getValue() == value)
    {
        return true;
    }
    else if(value < currentTree -> getRoot() -> getValue())
    {
        return contains(value, currentTree ->  getRoot() -> getLeftChild());
    }
    else
    {
        return contains (value, currentTree ->  getRoot()-> getRightChild());
    }
}

template < class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRightMostChild(CTECBinaryTree<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree -> getRoot();
    while(rightNode -> getRightChild() != nullptr)
    {
        rightNode = rightNode -> getRightChild();
    }
    
    return rightNode;
}

template < class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getLeftMostChild(CTECBinaryTree<Type> * rightSubTree)
{
    TreeNode<Type> * leftNode = rightSubTree -> getRoot();
    while(leftNode -> getLefttChild() != nullptr)
    {
        leftNode = leftNode -> getLeftChild();
    }
    
    return leftNode;
}