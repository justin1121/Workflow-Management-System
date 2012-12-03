/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 25, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  This is a node in the graph that contains all of the data needed
 *  for the Workflow graph.
 */

#include "WorkflowEngine.h"

/******************************************************************
 * constructor
 *
 * Initializes all of the variables.
 *****************************************************************/
Task::Task(){
	task  = "";
	actor = "";
	type = -1;
}

// all of the getters and setters for all of the member variables.
string Task::getActor(void){
	return actor;
}

string Task::getTask(void){
	return task;
}
int Task::getTraverseType(void){
	return type;
}

int Task::getNumEdges(void){
  return numEdges;
}

void Task::setActor(string actor){
	Task::actor = actor;
}

void Task::setTask(string task){
	Task::task = task;
}

void Task::setTraverseType(int type){
	Task::type = type;
}

void Task::setNumEdges(int num){
  Task::numEdges = num;
}
