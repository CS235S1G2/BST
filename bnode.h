

#ifndef BINARY_TREE
#define BINARY_TREE

/***********************************************
 * BINARY NODE
 * A node to be used in a binary tree
 **********************************************/
template <class T>
class BinaryTree
{
   public:
      // constructors
      BinaryTree(): pParent(NULL), pLeft(NULL), pRight(NULL)
      {
         data = T();
      }
      BinaryTree(const T & t): 
         data(t), pParent(NULL), pLeft(NULL), pRight(NULL) {}
      
      // methods
      void addLeft (BNode <T> * pNode, BNode <T> * pAdd);
      void addRight(BNode <T> * pNode, BNode <T> * pAdd);
      void addLeft (BNode <T> * pNode, const T & t) throw (const char *);
      void addRight(BNode <T> * pNode, const T & t) throw (const char *);
      
      // members
      T data;
      BinaryTree <T> * pParent;
      BinaryTree <T> * pLeft;
      BinaryTree <T> * pRight;
};

// nonmember function prototypes
void deleteBTree(BNode <T> * & pNode);
std::ostream & out operator << (std::ostream & out, const BinaryTree <T> * rhs);




#endif BINARY_TREE
