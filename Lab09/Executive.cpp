/*
  @Author: Marcus Leong
  @File Name: Executive.cpp
  @description: definition of Executive
  @Date:12-6-2018
*/

#include "Executive.h"
Executive* Executive::Exec = nullptr;

Executive::Executive() {
  static Executive *Exec;
  Exec = this;
}

Executive::Executive(std::string file) {
  Exec = this;
  std::ifstream inFile;
  inFile.open(file);
  
  int id, estTime;
  std::string action, task;
  
  if(inFile.is_open()) {
    while(!(inFile.eof())) {
      inFile >> action;
      if(action == "add") {
        time = time + 1;
        inFile >> id;
        inFile >> task;
        inFile >> estTime;
        addTask(id, task, estTime, time);
      }
      else if(action == "finish") {
        inFile >> id;
        finish(id);
      }
      else if(action == "started") {
        inFile >> id;
        started(id);
      }
      else if(action == "start") {
        inFile >> id;
        started(id);
      }
      else if(action == "taskPresent") {
        inFile >> id;
        taskPresent(id);
      }
      else if(action == "height") {
        BST->getHeight();
      }
      else if(action == "numberNodes") {
        BST->getNumberOfNodes();
      }
      else if(action == "flush") {
        flush(BST);
      }
    }
  }
  else {
    std::cout << "Unable to open file.\n";
  }
}

Executive::~Executive() {
  delete BST;
}

void Executive::addTask(int id, std::string name, int estimatedTime, int Time) {
  if(BST->contains(id) == true) {
    std::cout << "Task: " << id << " exists in the task manager.\n";
  }
  else {
    Task tempTask(id, name, estimatedTime, Time);
    if(BST->add(tempTask)){
      std::cout << "Task: " << id << " has been added.\n";  
    }
  }
}

void Executive::finish(int id) {
  if(!(BST->contains(id))) {
    std::cout << id << " is either non-existent or has not been started.\n";
  }
  else {
    if(BST->remove(id)) {
      std::cout << "Task: " << id << " has been removed.\n";
    }
  }
}

void Executive::started(int id) {
  Task tempTask = BST->getEntry(id);
  if(BST->contains(id) && tempTask.getTimeStarted() != -1) {
    std::cout << "Task: "<< id << " has been started.\n";
  }
  else if(BST->contains(id) && tempTask.getTimeStarted() == -1) {
    std::cout << "Task: " << id << "is not started.\n";
  }
  else {
    std::cout << "Task: " << id << " is not found.\n";
  }
}

void Executive::start(int id) {
  Task tempTask = BST->getEntry(id);
  if(BST->contains(id) && tempTask.getTimeStarted() != -1) {
    std::cout << "Task: " << id << " has been started.\n";
  }
  else if(BST->contains(id) && tempTask.getTimeStarted() == -1) {
    tempTask.setTime(time);
    std::cout << "Task: " << id << " has started.\n";
    //PRINT STATS
  }
  else {
    std::cout << "Task: " << id << " could not be found.\n";
  }
}

void Executive::taskPresent(int id) {
  Task tempTask = BST->getEntry(id);
  if(BST->contains(id)) {
    tempTask.printStats();
  }
  else {
    std::cout << "Task: " << id << " is not present in the search tree.\n";
  }
}

void Executive::flush(BinarySearchTree<int, Task>* BST) {
  BST->postorderTraverse(visit);
}

void Executive::visit(Task& id) {
  int tempID = id.getID();
  Exec->start(tempID);
  Exec->finish(tempID);
}