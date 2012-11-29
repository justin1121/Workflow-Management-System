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

using ::std::string;
using ::std::vector;
using ::std::list;
using ::std::pair;
using ::std::ifstream;
using ::std::cout;
using ::std::cin;

enum trans_enum{
  SEQUENTIAL = 0,
  FORK,
  MERGE,
  JOIN,
  DESICION
};

class DecisionEdge{
  public:
	  DecisionEdge();
    void setDecision(string);
    string getDecision(void);
  private:
    string decision;
};

class AbstractNode{
  public:
    virtual int getTraverseType(void) = 0;
    virtual void setTraverseType(int) = 0;
};

class Task : AbstractNode{
  public:
    Task();
    string getActor(void);
    string getTask(void);
    void setActor(string);
    void setTask(string);
	  int getTraverseType(void);
	  void setTraverseType(int);
  private:
    string task;
    string actor;
    int type;
};

class WorkflowGraph{
  public:
    ~WorkflowGraph();
    void addGraphVector(vector<pair<Task *, DecisionEdge *> > vec);
    // transversing graph will go here somewhere
  private:
    vector<vector<pair<Task *, DecisionEdge *> > > nodes;
};

class WorkflowLoader{
  public:
    WorkflowLoader(string);
    ~WorkflowLoader(void);
    WorkflowGraph generateGraph(void);
    void openFile(void);
    void closeFile(void);
  private:
    string getNextLine(void);
    Task * createNode(string, string, int);
    DecisionEdge * createEdge(string);
    vector<pair<Task *, DecisionEdge *> > addNodeVector(Task *);
    vector<pair<Task *, DecisionEdge *> >  
    addEdgeVector(Task *, DecisionEdge *, 
                    vector<pair<Task *, DecisionEdge *> >);

    string fileName;
	  ifstream * file;
};
