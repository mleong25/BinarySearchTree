#ifndef _BINARY_TREE_INTERFACE
#define _BINARY_TREE_INTERFACE

template<class ItemType>
class BinaryTreeInterface
{
public:
   /** Virtual destructor allows concrete implementations to clean up
       heap memory when the BinaryTree is discarded. */

   virtual ~BinaryTreeInterface() {}

   /** Tests whether this binary tree is empty.
    @return True if the binary tree is empty, or false if not. */

   virtual bool isEmpty() const = 0;

   /** Gets the height of this binary tree.
    @return The height of the binary tree. */

   virtual int getHeight() const = 0;

   /** Gets the number of nodes in this binary tree.
    @return The number of nodes in the binary tree. */

   virtual int getNumberOfNodes() const = 0;

   /** Gets the data that is in the root of this binary tree.
    @pre  The binary tree is not empty.
    @post  The root’s data has been returned, and the binary tree is unchanged.
    @return  The data in the root of the binary tree. */

   virtual ItemType getRootData() const = 0;

   /** Replaces the data item in the root of this binary tree
       with the given data, if the tree is not empty. However, if
       the tree is empty, inserts a new root node containing the
       given data into the tree.
    @pre  None.
    @post  The data in the root of the binary tree is as given.
    @param newData  The data for the root. */

   virtual void setRootData(const ItemType& newData) = 0;

   /** Removes all nodes from this binary tree. */

   virtual void clear() = 0;

   /** Traverses this binary tree in preorder (inorder, postorder) and
       calls the function visit once for each node.
    @param visit A client-defined function that performs an operation on
       or with the data in each visited node. */
   virtual void preorderTraverse(void visit(ItemType&)) const = 0;
   virtual void inorderTraverse(void visit(ItemType&)) const = 0;
   virtual void postorderTraverse(void visit(ItemType&)) const = 0;
};
#endif
