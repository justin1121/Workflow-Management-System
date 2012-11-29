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

void WorkflowGraph::addGraphVector(vector<pair<Task *, DecisionEdge *> > vec){
  nodes.push_back(vec);
}
