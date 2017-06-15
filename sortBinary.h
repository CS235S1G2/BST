/***********************************************************************
 * Module:
 *    Week 09, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
   // create a tree
   BST <T> tree;
   // insert the array into the tree
   for (int i = 0; i < num; i++)
   {
      tree.insert(array[i]);
   }
   // write over the array
   int j = 0;
   BSTIterator <T> it = tree.begin();
   for (BSTIterator <T> it = tree.begin();
        it != tree.end(); ++it)
        {
           array[j] = *it;
           j++;
        }
}


#endif // SORT_BINARY_H
