/*
  @Author: Marcus Leong
  @File Name: Executive.cpp
  @description: definition of Executive
  @Date:12-6-2018
*/


#include "BinarySearchTree.h"
#include "Task.h"
#include <string>
#include <fstream>
#include <iostream>

#ifndef _EXECUTIVE
#define _EXECUTIVE

class Executive {
private:
  int time;
  static Executive *Exec;
  BinarySearchTree<int, Task>* BST;  
  
public:
  Executive();
  Executive(std::string file);
  ~Executive();
  void addTask(int id, std::string name, int estimatedTime, int Time);
  void finish(int id);
  void started(int id);
  void start(int id);
  void taskPresent(int id);
  void flush(BinarySearchTree<int, Task>* BST);
  static void visit(Task& id);
};
#endif