/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 15, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  This is a graph that contains the workflow and handles traversing itself.
 */

#include <stdarg.h>
#include "WorkflowEngine.h"

WorkflowGraph::~WorkflowGraph(){
  // iterate through everything and delete the shit out of them
}

vector<pair<Task *, DecisionEdge *> >  WorkflowGraph::addNode(Task * task){
  vector<pair<Task *, DecisionEdge *> > vec;

  pair<Task *, DecisionEdge *> p(task, NULL);
   
  vec.push_back(p);

  return vec;
}

vector<pair<Task *, DecisionEdge *> >  
WorkflowGraph::addEdge(Task * task, DecisionEdge * edge,
                                    vector<pair<Task *, DecisionEdge *> > node){
  pair<Task *, DecisionEdge *> p(task, edge);
  
  node.push_back(p);

  return node;
}

void WorkflowGraph::addGraphVector(vector<pair<Task *, DecisionEdge *> > vec){
  nodes.push_back(vec);
}
