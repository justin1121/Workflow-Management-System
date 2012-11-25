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
#include <utility>

using ::std::string;
using ::std::vector;
using ::std::pair;
using ::std::ifstream;
using ::std::cout;
using ::std::cin;

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
    WorkflowGraph();
    ~WorkflowGraph();
    void addNode(Task *);
    void addEdge(DecisionEdge *);
    // transversing graph will go here somewhere
  private:
    vector<vector<pair<Task, DecisionEdge> > > nodes;
};

class WorkflowLoader{
  public:
    WorkflowLoader(string);
    ~WorkflowLoader(void);
    WorkflowGraph generateGraph(void);
  private:
    void openFile(void);
    void closeFile(void);
    string getNextLine(void);
    Task * createNode(string, string);
    DecisionEdge * createEdge(string);
    string fileName;
	ifstream * file;
};
