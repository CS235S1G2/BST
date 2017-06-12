/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Jones, CS 235
 * Author:
 *    Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
 * Summary:
 *    Binary Search Tree
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "bnode.h"   // for BinaryNode
#include "stack.h"   // for Stack

/***********************************************
 * BINARY SEARCH TREE
 * A binary tree that follows the rule pLeft < root < pRight
 **********************************************/
template <class T>
class BST
{
   public:
      // constructors & destructor
      BST(): root(NULL) {}
      BST(const BST <T> & rhs) throw (const char *);
      ~BST()
      {
         deleteBinaryTree(root);
         root = NULL;
      }
      BST <T> & operator = (const BST <T> & rhs);
      
      // make a friend
      friend void deleteBinaryTree(BinaryNode <T> * &pNode);
      
      // container interfaces
      bool empty()   { return root == NULL;    }
      int size()     { return root->size();     }
      void clear()   
      { 
         deleteBinaryTree(root); 
         root = NULL;
      }
      
      // Binary Search Tree interfaces
      void insert(const T & t) throw (const char *);
      void remove(BSTIterator <T> & it);
      BSTIterator <T> find(const T & t);
      
      // iterators
      BSTIterator <T> begin();
      BSTIterator <T> end()  { return BSTIterator <T> (NULL); }
      BSTIterator <T> rbegin();
      BSTIterator <T> rend() { return BSTIterator <T> (NULL); }
      
   private:
      BinaryNode <T> * root; 
};

/***********************************************
 * BST ITERATOR
 * A class to iterate through the BST
 **********************************************/
template <class T>
BSTIterator
{
   public:
      BSTIterator(BinaryNode <T> * pNode);
      BSTIterator(Stack <BinaryNode <T> *> nodes);
      
      BSTIterator <T> & operator = (const Stack <BinaryNode <T> *> rhs);
      
      bool operator == (const BSTIterator <T> & rhs) const;
      
      bool operator != (const BSTIterator <T> & rhs) const;
      
      // return const by reference to keep tree valid
      const T & operator * ()
      {
         return nodes.top()->data;
      }
      
      BSTIterator <T> & operator ++ ();
      BSTIterator <T>   operator ++ (int postfix);
      
   private:
      Stack <BinaryNode <T> *> nodes;
};
 
/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 *     advance by one. Note that this implementation uses
 *     a stack of nodes to remember where we are. This stack
 *     is called "nodes".
 * Author:      Br. Helfrich
 * Performance: O(log n) though O(1) in the common case
 *************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator -- ()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;

   // if there is a left node, take it
   if (nodes.top()->pLeft != NULL)
   {
      nodes.push(nodes.top()->pLeft);

      // there might be more right-most children
      while (nodes.top()->pRight)
         nodes.push(nodes.top()->pRight);
      return *this;
   }

   // there are no left children, the right are done
   assert(nodes.top()->pLeft == NULL);
   BinaryNode <T> * pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}

#endif // BST_H

