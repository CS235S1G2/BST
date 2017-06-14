

#ifndef BINARY_NODE
#define BINARY_NODE

#include <iostream> 
/***********************************************
 * BINARY NODE
 * A node to be used in a binary tree
 **********************************************/
template <class T>
class BinaryNode
{
   public:
      // constructors
      BinaryNode(): pParent(NULL), pLeft(NULL), pRight(NULL)
      {
         data = T();
      }
      BinaryNode(const T & t): 
         data(t), pParent(NULL), pLeft(NULL), pRight(NULL) {}
      
      // methods
      void addLeft (BinaryNode <T> * pAdd);
      void addRight(BinaryNode <T> * pAdd);
      void addLeft (const T & t) throw (const char *);
      void addRight(const T & t) throw (const char *);
      
      int size();
      
      // members
      T data;
      BinaryNode <T> * pParent;
      BinaryNode <T> * pLeft;
      BinaryNode <T> * pRight;
};

// nonmember function prototypes
template <class T>
void deleteBinaryTree(BinaryNode <T> * & pNode);

template <class T>
std::ostream & operator << (std::ostream & out, const BinaryNode <T> * rhs);

/***********************************************
 * BINARY NODE :: ADD LEFT (BNODE)
 * Add a previously existing left node
 **********************************************/
template <class T>
void BinaryNode <T> :: addLeft(BinaryNode <T> * pAdd)
{
   if (pAdd != NULL)
      pAdd->pParent = this;
   
   pLeft = pAdd;
}

/***********************************************
 * BINARY NODE :: ADD RIGHT (BNODE)
 * Add a previously existing right node
 **********************************************/
template <class T>
void BinaryNode <T> :: addRight(BinaryNode <T> * pAdd)
{
   if (pAdd != NULL)
      pAdd->pParent = this;
   pRight = pAdd;
}

/***********************************************
 * BINARY NODE :: ADD LEFT (T)
 * Add a NEW node to the left with value t
 **********************************************/
template <class T>
void BinaryNode <T> :: addLeft(const T & t) throw (const char *)
{
   try
   {
      BinaryNode <T> * pAdd = new BinaryNode <T>(t);
      pAdd->pParent = this;
      pLeft = pAdd;
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: unable to allocate a node";
   }
}

/***********************************************
 * BINARY NODE :: ADD RIGHT (T)
 * Add a NEW node to the right with value t
 **********************************************/
template <class T>
void BinaryNode <T> :: addRight(const T & t) throw (const char *)
{
      try
   {
      BinaryNode <T> * pAdd = new BinaryNode <T>(t);
      pAdd->pParent = this;
      pRight = pAdd;
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: unable to allocate a node";
   }
}

/***********************************************
 * SIZE B TREE
 * return the size of the tree under a given node
 **********************************************/
template <class T>
int BinaryNode <T> :: size()
{
   if (this == NULL)
      return 0;
   else
      return pLeft->size() + 1 + pRight->size();
}

/***********************************************
 * DELETE B TREE
 * Delete binary tree
 **********************************************/
template <class T>
void deleteBinaryTree(BinaryNode <T> * & pNode)
{
   if (pNode == NULL)
      return;
   deleteBinaryTree(pNode->pLeft);
   deleteBinaryTree(pNode->pRight);
   delete pNode;
}

/***********************************************
 * OPERATOR <<
 * Overload the insertion operator
 **********************************************/
template <class T>
 std::ostream & operator << (std::ostream & out, const BinaryNode <T> * rhs)
{
   if (rhs != NULL)
   {
      out << rhs->pLeft;
      out << rhs->data << " ";
      out << rhs->pRight;
   }
   
   return out;
}

#endif // BINARY_NODE
