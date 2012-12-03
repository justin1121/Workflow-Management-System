/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 15, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  This contains all of the Workflow Engine's class definitions.
 */
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <queue>

#include "AbstractNode.h"

using ::std::string;
using ::std::vector;
using ::std::list;
using ::std::pair;
using ::std::ifstream;
using ::std::cout;
using ::std::cin;
using ::std::queue;

// enum for using a switch statement to deal with the different
// types of transitions
enum trans_enum{
  SEQUENTIAL = 1,
  FORK,
  MERGE,
  JOIN,
  DESICION,
  START,
  STOP
};

// all of the class definitions for the WorkflowEngine package.
class DecisionEdge{
  public:
	  DecisionEdge();
    void setDecision(string);
    string getDecision(void);
  private:
    string decision;
};

class Task : public AbstractNode{
  public:
    Task();
    string getActor(void);
    string getTask(void);
    int getNumEdges(void);
    int getTraverseType(void);
    void setActor(string);
    void setTask(string);
    void setNumEdges(int);
    void setTraverseType(int);
  private:
    string task;
    string actor;
    int numEdges;
};

class StartStopNode : public AbstractNode{
  public:
    string getActor(void);
    string getMessage(void);
    int getTraverseType(void);
    void setActor(string);
    void setMessage(string);
    void setTraverseType(int);
  private:
    string message;
    string actor;
};

// some typedefs to make the code a bit more readable.
typedef pair<AbstractNode *, DecisionEdge *> NodeEdgePair;
typedef vector<NodeEdgePair> VecPairNodeEdge;
typedef vector<VecPairNodeEdge> Graph;

class WorkflowGraph{
  public:
    ~WorkflowGraph();
    void addGraphVector(VecPairNodeEdge vec);
    string getTitle(void);
    void setTitle(string);
    NodeEdgePair getStartNode(void);
    NodeEdgePair getNextNode(void);
  private:
    Graph graph;
    string title;
    queue<AbstractNode *> que;
};

class WorkflowLoader{
  public:
    WorkflowLoader();
    WorkflowLoader(string);
    ~WorkflowLoader(void);
    WorkflowGraph createGraph(void);
    WorkflowGraph generateGraph(WorkflowGraph);
    void openFile(void);
    void closeFile(void);
    void setFileName(string);
  private:
    string getNextLine(void);
    Task * createNode(string);
    DecisionEdge * createEdge(string);
    VecPairNodeEdge addNodeVector(AbstractNode *);
    VecPairNodeEdge addEdgeVector(AbstractNode *, DecisionEdge *, 
                                                  VecPairNodeEdge);
    list<string> createDesicionList(string, int);
    StartStopNode * createStartStopNode(string);
    void resetVector(void);
    string fileName;
	  ifstream * file;
    VecPairNodeEdge vec;
    bool initial;
};
