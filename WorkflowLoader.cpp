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

/******************************************************************
 * constructor
 *
 * Sets the fileName member variable and sets the bool member
 * variable to true.
 *****************************************************************/
WorkflowLoader::WorkflowLoader(){
}
/******************************************************************
 * constructor
 *
 * Sets the fileName member variable and sets the bool member
 * variable to true.
 *****************************************************************/
WorkflowLoader::WorkflowLoader(string fileName){
  WorkflowLoader::fileName = fileName;
  initial = true;
}

WorkflowLoader::~WorkflowLoader(void){
	closeFile();
}

/******************************************************************
 * createGraph 
 *
 * Sets the fileName member variable and sets the bool member
 * variable to true.
 *****************************************************************/
WorkflowGraph WorkflowLoader::createGraph(void){
  WorkflowGraph graph;
  StartStopNode * node;

  graph.setTitle(getNextLine());
  node = createStartStopNode(getNextLine());

  NodeEdgePair p(node, NULL);
  vec.push_back(p);
 
  graph.addGraphVector(vec);
  resetVector();

  return graph;
}

WorkflowGraph WorkflowLoader::generateGraph(WorkflowGraph graph){
  string line;
  list<string> desicions;
  Task * task;

  while((line = getNextLine()).compare("0") != 0){
    task = createNode(line);
    NodeEdgePair p(task, NULL);
    list<string> desicions;
    cout << task->getTraverseType() << "\n";
    switch(task->getTraverseType(), NULL, 2){
      case SEQUENTIAL:
        cout << "HEY\n";
        if(initial){
          vec.push_back(p);
          initial = false;
        } 
        else{
          vec.push_back(p);
          graph.addGraphVector(vec);
          resetVector();
          vec.push_back(p);
        }
        break;
      case FORK:
        break;
      case MERGE:
        break;
      case JOIN:
        break;
      case DESICION:
        desicions = createDesicionList(line, task->getNumEdges());
        break;
      case START:
        break;
      case STOP:
        vec.push_back(p);
        graph.addGraphVector(vec);
        resetVector();
        vec.push_back(p);
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
		cout << "File has been successfully closed!\n";
	}
	else{
		cout << "File has already been closed!\n";
	}
}

void WorkflowLoader::setFileName(string fileName){
  WorkflowLoader::fileName = fileName;
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

VecPairNodeEdge WorkflowLoader::addNodeVector(AbstractNode * node){
  VecPairNodeEdge vec;

  NodeEdgePair p(node, NULL);
   
  vec.push_back(p);

  return vec;
}

VecPairNodeEdge WorkflowLoader::addEdgeVector(AbstractNode * task, 
                                              DecisionEdge * edge,
                                              VecPairNodeEdge node){
  NodeEdgePair p(task, edge);
  
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
         actor,
         transType;
  stringstream stream(line, ios_base::in);

  getline(stream, actor, ','); 
  getline(stream, message, ',');
  getline(stream, transType, ',');

  node->setActor(actor);
  node->setMessage(message);
  node->setTraverseType(strtol(transType.c_str(), NULL, 2));

  return node;
}

void WorkflowLoader::resetVector(void){
  vec.clear();
}
