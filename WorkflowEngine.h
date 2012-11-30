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

#include "AbstractNode.h"

using ::std::string;
using ::std::vector;
using ::std::list;
using ::std::pair;
using ::std::ifstream;
using ::std::cout;
using ::std::cin;

enum trans_enum{
  SEQUENTIAL = 1,
  FORK,
  MERGE,
  JOIN,
  DESICION,
  START,
  STOP
};

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
    string getMessage(void);
    int getTraverseType(void);
    void setMessage(string);
    void setTraverseType(int);
  private:
    string message;
};

class WorkflowGraph{
  public:
    ~WorkflowGraph();
    void addGraphVector(vector<pair<AbstractNode *, DecisionEdge *> > vec);
    string getTitle(void);
    void setTitle(string);
    // transversing graph will go here somewhere
  private:
    vector<vector<pair<AbstractNode *, DecisionEdge *> > > nodes;
    string title;
};

class WorkflowLoader{
  public:
    WorkflowLoader(string);
    ~WorkflowLoader(void);
    WorkflowGraph createGraph(void);
    WorkflowGraph generateGraph(WorkflowGraph);
    void openFile(void);
    void closeFile(void);
  private:
    string getNextLine(void);
    Task * createNode(string);
    DecisionEdge * createEdge(string);
    vector<pair<AbstractNode *, DecisionEdge *> > addNodeVector(AbstractNode *);
    vector<pair<AbstractNode *, DecisionEdge *> >  
    addEdgeVector(AbstractNode *, DecisionEdge *, 
                    vector<pair<AbstractNode *, DecisionEdge *> >);
    list<string> createDesicionList(string, int);
    StartStopNode * createStartStopNode(string);
    string fileName;
	  ifstream * file;
};
