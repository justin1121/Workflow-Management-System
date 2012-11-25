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

Task::Task(){
	task  = "";
	actor = "";
	type = -1;
}

string Task::getActor(void){
	return actor;
}

string Task::getTask(void){
	return task;
}
int Task::getTraverseType(void){
	return type;
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

