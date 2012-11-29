/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 22, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  Reads a workflow from a file and loads and creates the data into a 
 *  workflow graph.
 */

#include <sstream>
#include <stdarg.h>
#include <stdlib.h>
#include "WorkflowEngine.h"

using ::std::istream;
using ::std::stringstream;
using ::std::ios_base;

WorkflowLoader::WorkflowLoader(string fileName){
  WorkflowLoader::fileName = fileName;
}

WorkflowLoader::~WorkflowLoader(void){
	closeFile();
}

WorkflowGraph WorkflowLoader::generateGraph(void){
  string line,
         actor,
         task, 
         transType,
         numEdges;
  list<string> desicions;
  WorkflowGraph graph;

  while((line = getNextLine()).compare("0") != 0){
    stringstream stream(line, ios_base::in);

    getline(stream, actor, ',');
    getline(stream, task, ',');
    getline(stream, transType, ',');
    getline(stream, numEdges, ',');
    
    switch(strtol(transType.c_str(), NULL, 2)){
      case SEQUENTIAL:
        break;
      case FORK:
        break;
      case MERGE:
        break;
      case JOIN:
        break;
      case DESICION:
        int num;
        num = strtol(numEdges.c_str(), NULL, 2);
        for(int i = 0; i < num; i++){
          string desicion;

          getline(stream, desicion, ',');
          desicions.push_back(desicion);

          i++;
        }
        break;
    }
  }

  return graph;
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
  string line;
  
  std::getline(*file, line);

  if((*file).eof()){
    return "0";
  }
  return line;
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

vector<pair<Task *, DecisionEdge *> >  
WorkflowLoader::addNodeVector(Task * task){
  vector<pair<Task *, DecisionEdge *> > vec;

  pair<Task *, DecisionEdge *> p(task, NULL);
   
  vec.push_back(p);

  return vec;
}

vector<pair<Task *, DecisionEdge *> >  
WorkflowLoader::addEdgeVector(Task * task, DecisionEdge * edge,
                              vector<pair<Task *, DecisionEdge *> > node){
  pair<Task *, DecisionEdge *> p(task, edge);
  
  node.push_back(p);

  return node;
}
