

#include "Task.h"

Task::Task(int id, std::string name, int est, int time) {
  taskID = id;
  taskName = name;
  estimatedCompletion = est;
  timeAddedToBST = time;
  timeStarted = -1;
}

void Task::printStats() {
  std::cout << "\tTask: " << taskName << "\t" << taskID << "\n" << "\tEstimated Completion: " << estimatedCompletion << "\n" << "\tTime added to BST: " << timeAddedToBST << "\n" << "\tTime Started: " << timeStarted << "\n";
}

/*** Getters ***/
int Task::getID() {
  return taskID;
}

std::string Task::getTaskName() {
  return taskName;
}

int Task::getEstimatedCompletion() {
  return estimatedCompletion;
}

int Task::getTimeAdded() {
  return timeAddedToBST;
}

int Task::getTimeStarted() {
  return timeStarted;
}

void Task::setTime(int time) {
  timeStarted = time;
}