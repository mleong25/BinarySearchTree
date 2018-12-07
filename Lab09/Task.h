#ifndef _TASK
#define _TASK

#include <string>
#include <iostream>

class Task {
private:
  int taskID;
  std::string taskName;
  int estimatedCompletion;
  int timeAddedToBST;
  int timeStarted;
public:
  Task(int id, std::string name, int est, int time);
  
  void printStats();
  
  /*** Public Getters ***/
  int getID();
  std::string getTaskName();
  int getEstimatedCompletion();
  int getTimeAdded();
  int getTimeStarted();
  
  
  /*** Public Setters ***/
  void setTime(int time);
};
#endif