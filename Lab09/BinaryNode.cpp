/*
  @Author: Marcus Leong
  @File Name: BinaryNode.cpp
  @description: definition of BinaryNode class
  @Date:11-16-2018
*/

/*** Constructors ***/
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) {
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
  item = anItem;
}

template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
                                 BinaryNode<ItemType>* leftPtr,
                                 BinaryNode<ItemType>* rightPtr)
{
  leftChildPtr = leftPtr;
  rightChildPtr = rightPtr;
  item = anItem;
}

/*** Setters and Getters ***/
template<typename ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
}

template<typename ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
  return(item);
}

/*** Public Method of Binary Node ***/
template<typename ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
  if(getLeftChildPtr() == nullptr && getRightChildPtr() == nullptr) {
    return(true);
  }
  return(false);
}

/*** Setters and Getters for Children of Node ***/
template<typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
  return(leftChildPtr);
}

template<typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
  return(rightChildPtr);
}

template<typename ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {
  leftChildPtr = leftPtr;
}

template<typename ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr) {
  rightChildPtr = rightPtr;
}