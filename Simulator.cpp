/*
 * File:   Simulator.cpp
 * Author: Chris Dingwell
 *
 * Created on November 29, 2012, 3:29 PM
 */
 
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Simulator.h"
#include "WorkflowEngine.h"

using namespace std;
 
string Simulator::displayTask(Task task) {
  return "Participant: " + task.getActor() 
                           + "\tNext task(s): " + task.getTask();
}

void Simulator::setGraph(WorkflowGraph graph){
  Simulator::graph = graph;
}

void Simulator::simulate(void){
  AbstractNode * node;

  cout << graph.getTitle() << "\n";
  node = graph.getStartNode().first;
  
  cout << "Starting the simulation...\nThis is the starting node:\n";
  cout << "Actor: " << static_cast<StartStopNode *>(node)->getActor() << endl;
  cout << "Message: " << static_cast<StartStopNode *>(node)->getMessage()
                                                                      << endl;
  cout << "Moving on to first task...\n";
  node = graph.getNextNode().first;
  if(node == NULL){
    cout << "There was an error somewhere... Exiting...\n";
    exit(1);
  }
  while(node->getTraverseType() != STOP){
    askIfCompleted(static_cast<Task *>(node));
    node = graph.getNextNode().first;
    if(node == NULL){
      cout << "There was an error somewhere... Exiting...\n";
      exit(1);
    }
  }
}

void Simulator::askIfCompleted(Task * task){
  char completion = 'n';

  while(completion=='n'){
    cout << displayTask(*task) << endl;
    cout << "The " + task->getActor() + " must " + task->getTask();
    cout << ". Is this task completed? (y/n)\n\n";
    cin >> completion;
  }
}
