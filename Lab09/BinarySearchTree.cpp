#include "BinarySearchTree.h"

/**** Protected Methods ****/
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode) {
  if(subTreePtr == nullptr) {
    return(newNode);
  }
  else if(newNode->getItem() > subTreePtr->getItem()) {
    BinaryNode<ItemType>* temp = insertInorder(subTreePtr->getRightChildPtr(), newNode);
    subTreePtr->setRightChildPtr(temp);
  }
  else {
    BinaryNode<ItemType>* temp = insertInorder(subTreePtr->getLeftChildPtr(), newNode);
    subTreePtr->setLeftChildPtr(temp);
  }
  return(subTreePtr);
}


// Removes the given target value from the tree while maintaining a
// binary search tree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, KeyType aKey, bool& success) {
  if(subTreePtr == nullptr) {
    success = false;
    return(nullptr);
  }
  else if(subTreePtr->getItem() == aKey) {
    subTreePtr = removeNode(subTreePtr);
    success = true;
    return(subTreePtr);
  }
  else if(subTreePtr->getItem() > aKey) {
    BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr -> getLeftChildPtr(), aKey, success);
    subTreePtr -> setLeftChildPtr(tempPtr);
    return(subTreePtr);
  }
  else {
    BinaryNode<ItemType>* temp = removeValue(subTreePtr->getRightChildPtr(), aKey, success);
    subTreePtr->setRightChildPtr(temp);
    return(subTreePtr);
  }
}


// Removes a given node from a tree while maintaining a
// binary search tree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeNode(BinaryNode<ItemType>* nodePtr) {
  if(nodePtr->isLeaf() == true) {
    delete nodePtr;
    nodePtr = nullptr;
    return(nodePtr);
  }
  else if((nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() != nullptr) || (nodePtr->getRightChildPtr() == nullptr && nodePtr->getLeftChildPtr() != nullptr)) {
    BinaryNode<ItemType>* tempPtr = nullptr;
    if(tempPtr->getLeftChildPtr() != nullptr) {
      tempPtr = tempPtr->getLeftChildPtr();
    }
    else {
      tempPtr = tempPtr->getRightChildPtr();
    }
    delete tempPtr;
    tempPtr = nullptr;
    return(tempPtr);
  }
  else {
    ItemType inorderSuccessor;
    BinaryNode<ItemType>* tempPtr = removeLeftmostNode(tempPtr->getRightChildPtr(), inorderSuccessor);
    tempPtr->setRightChildPtr(tempPtr);
    tempPtr->setItem(inorderSuccessor);
  }
}

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
ItemType& inorderSuccessor) {
  if(subTreePtr->getLeftChildPtr() == nullptr) {
    inorderSuccessor = subTreePtr->getItem();
    return(removeNode(subTreePtr));
  }
  else {
    subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLegetLeftChildPtr(), inorderSuccessor));
    return(subTreePtr);
  }
}

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findNode(BinaryNode<ItemType>* treePtr,
KeyType aKey) const {
  if(treePtr == nullptr) {
    throw(NotFoundException(aKey + " is unable to be found.\n"));
  }
  else if(treePtr->getEntry() < aKey) {
    return(findNode(treePtr->getRightChildPtr()));
  }
  else if(treePtr->getEntry() > aKey) {
    return(findNode(treePtr->getLeftChildPtr()));
  }
  else if(treePtr->getEntry() == aKey) {
    return(treePtr->getEntry());
  }
  else {
    throw(NotFoundException(aKey + " is unable to be found.\n"));
  }
  return(nullptr);
}

// Recursive traversal helper methods:
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
  if(subTreePtr == nullptr) {
    return(0);
  }
  else if(subTreePtr != nullptr) {
    if(getHeightHelper(subTreePtr->getLeftChildPtr()) >= getHeightHelper(subTreePtr->getRightChildPtr())) {
      return(getHeightHelper(subTreePtr->getLeftChildPtr())+getHeightHelper(subTreePtr) + 1);
    }
    else {
      return(getHeightHelper(subTreePtr->getRightChildPtr())+getHeightHelper(subTreePtr) + 1);
    }
  }
  return(0);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const {
  if(subTreePtr != nullptr) {
  return(getNumberOfNodesHelper(subTreePtr->getRightChildPtr()) + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + 1);
  }
  else if(subTreePtr == nullptr) {
    return(0);
  }
  return(0);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if(treePtr != nullptr) {
    ItemType treeTemp = treePtr->getItem();
    visit(treeTemp);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if(treePtr != nullptr) {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType treeTemp = treePtr->getItem();
    visit(treeTemp);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if(treePtr != nullptr) {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    ItemType treeTemp = treePtr->getItem();
    visit(treeTemp);
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
  if(subTreePtr != nullptr) {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const {
  BinaryNode<ItemType>* temp = nullptr;
  
  if(treePtr != nullptr) {
    temp = new BinaryNode<ItemType>(treePtr->getItem());
    temp->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    temp->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
  }
  return(temp);
}

/**** Public Methods ****/
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree() {
  rootPtr = nullptr;
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const ItemType& rootItem) {
  rootPtr = new BinaryNode<ItemType>(rootItem);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const BinarySearchTree& tree) {
  rootPtr = copyTree(tree.rootPtr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree() {
  clear();
}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty() const {
  if(rootPtr == nullptr) {
    return(true);
  }
  return(false);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeight() const {
  return(getHeightHelper(rootPtr));
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodes() const {
  return(getNumberOfNodesHelper(rootPtr));
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::add(const ItemType& newEntry) {
  BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
  rootPtr = insertInorder(rootPtr, newNodePtr);
  if(rootPtr==nullptr){
    return false;
  }
  return true;
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(const KeyType& aKey) {
  bool success = false;
  rootPtr = removeValue(rootPtr, aKey, success); 

  if(success == false) {
    throw(NotFoundException("Unable to find key.\n"));
    return false;
  }
  return true;
}

template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getEntry(const KeyType& aKey) const throw(NotFoundException) {
  BinaryNode<ItemType>* searchPtr = findNode(rootPtr, aKey);
  if(searchPtr == nullptr) {
    throw(NotFoundException("Unable to find key.\n"));
  }
  else {
    return(searchPtr->getItem());
  }
}

// An entry in a BinarySearchTree can be set if and only if "item == aKey".
// If this is not the case, throw InvalidSetEntryRequest.
// If "aKey" does not exist in the tree, throw NotFoundException.
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::setEntry(const KeyType& aKey, const ItemType& item) const
throw(NotFoundException, InvalidSetEntryRequest) {

}
 
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::contains(const KeyType& aKey) const {
  findNode(rootPtr, aKey);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clear() {
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorderTraverse(void visit(ItemType&)) const {
  preorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorderTraverse(void visit(ItemType&)) const {
  inorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorderTraverse(void visit(ItemType&)) const {
  postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
BinarySearchTree& BinarySearchTree<KeyType, ItemType>::operator=(const BinarySearchTree& rightHandSide) {
  rootPtr = copyTree(rightHandSide.rootPtr);
  return(*this);
}