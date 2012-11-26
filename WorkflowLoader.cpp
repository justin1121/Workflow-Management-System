/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 22, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  Reads a workflow from a file and loads and creates the data into a 
 *  workflow graph.
 */

#include "WorkflowEngine.h"

WorkflowLoader::WorkflowLoader(string fileName){
  WorkflowLoader::fileName = fileName;
}

WorkflowLoader::~WorkflowLoader(void){
	closeFile();
}

WorkflowGraph WorkflowLoader::generateGraph(void){

}

void WorkflowLoader::openFile(void){
	file = new ifstream(fileName.c_str());
	
	if(file->is_open()){
		cout << "File has successfully been opened!\n";
	}
	else{
		cout << "Unable to open the file!\n";
	}
}

void WorkflowLoader::closeFile(void){
	if(file->is_open()){
		file->close();
		cout << "File has been successfully close!\n";
	}
	else{
		cout << "File has already been closed!\n";
	}
}

string WorkflowLoader::getNextLine(void){
	cout << "";
}

Task * WorkflowLoader::createNode(string task, string actor, int traverseType){
  Task * t = new Task();

  t->setTask(task);
  t->setActor(task);
  t->setTraverseType(traverseType);

  return t;
}

DecisionEdge * WorkflowLoader::createEdge(string decision){
  DecisionEdge * edge = new DecisionEdge();

  edge->setDecision(decision);

  return edge;
}
