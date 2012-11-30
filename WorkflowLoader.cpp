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

WorkflowGraph WorkflowLoader::createGraph(void){
  WorkflowGraph graph;
  StartStopNode * node;
  vector<pair<AbstractNode *, DecisionEdge *> > vec;

  graph.setTitle(getNextLine());

  node = createStartStopNode(getNextLine());

  pair<AbstractNode *, DecisionEdge *> p(node, NULL);
  vec.push_back(p);
 
  graph.addGraphVector(vec);
}

WorkflowGraph WorkflowLoader::generateGraph(WorkflowGraph graph){
  string line;
  list<string> desicions;
  Task * task;

  while((line = getNextLine()).compare("0") != 0){
    task = createNode(line);
    switch(task->getTraverseType(), NULL, 2){
      case SEQUENTIAL:
        
        break;
      case FORK:
        break;
      case MERGE:
        break;
      case JOIN:
        break;
      case DESICION:
        list<string> desicions;
        
        desicions = createDesicionList(line, task->getNumEdges());
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

Task * WorkflowLoader::createNode(string line){
  Task * t = new Task();
  string actor,
         task,
         transType,
         numEdges;
  stringstream stream(line, ios_base::in);

  getline(stream, actor, ',');
  getline(stream, task, ',');
  getline(stream, transType, ',');
  getline(stream, numEdges, ',');

  t->setTask(task);
  t->setActor(actor);
  t->setTraverseType(strtol(transType.c_str(), NULL, 2));
  t->setNumEdges(strtol(numEdges.c_str(), NULL, 2));

  return t;
}

DecisionEdge * WorkflowLoader::createEdge(string decision){
  DecisionEdge * edge = new DecisionEdge();

  edge->setDecision(decision);

  return edge;
}

vector<pair<AbstractNode *, DecisionEdge *> >  
WorkflowLoader::addNodeVector(AbstractNode * node){
  vector<pair<AbstractNode *, DecisionEdge *> > vec;

  pair<AbstractNode *, DecisionEdge *> p(node, NULL);
   
  vec.push_back(p);

  return vec;
}

vector<pair<AbstractNode *, DecisionEdge *> >  
WorkflowLoader::addEdgeVector(AbstractNode * task, DecisionEdge * edge,
                              vector<pair<AbstractNode *, DecisionEdge *> > node){
  pair<AbstractNode *, DecisionEdge *> p(task, edge);
  
  node.push_back(p);

  return node;
}

list<string> WorkflowLoader::createDesicionList(string line, int num){
  stringstream stream(line, ios_base::in);
  list<string> desicions;

  for(int i = 0; i < num; i++){
    string desicion;

    getline(stream, desicion, ',');
    desicions.push_back(desicion);
  } 

  return desicions;
}

StartStopNode * WorkflowLoader::createStartStopNode(string line){
  StartStopNode * node = new StartStopNode();
  string message,
         transType;
  stringstream stream(line, ios_base::in);

  getline(stream, message);
  getline(stream, transType);

  node->setMessage(message);
  node->setTraverseType(strtol(transType.c_str(), NULL, 2));

  return node;
}
