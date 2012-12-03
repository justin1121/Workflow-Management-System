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

using ::std::make_pair;

WorkflowGraph::~WorkflowGraph(){
  // iterate through everything and delete it...this would have been
  // the code would have gone anyway
}

/******************************************************************
 * addGraphVector 
 *
 * Adds a fully formed vector to the graph type.
 *****************************************************************/
void WorkflowGraph::addGraphVector(VecPairNodeEdge vec){
  graph.push_back(vec);
}

void WorkflowGraph::setTitle(string title){
  WorkflowGraph::title = title;
}

string WorkflowGraph::getTitle(void){
  return title;
}


/******************************************************************
 * getStartNode
 *
 * Helper function to easily get the StartNode.
 *****************************************************************/
NodeEdgePair WorkflowGraph::getStartNode(void){
  return graph[0][0];
}

/******************************************************************
 * getNextNode
 *
 * Returns the next node in the proper order depending on the different
 * transitions that are used throughout the graph. It uses a queue
 * to know what nodes to go to next.
 *****************************************************************/
NodeEdgePair WorkflowGraph::getNextNode(void){
  NodeEdgePair temp;
  VecPairNodeEdge blahblah;
  bool error = false;
  int numEdges = 0;

  // if the queue is empty then traversing the graph hasn't started yet
  if(que.empty()){
    //get the first data containing node in the graph
    temp = graph[1][0];
    switch(temp.first->getTraverseType()){
      case SEQUENTIAL:
        // if its transition type is SEQUENTIAL then push the node 
        // connected
        // to it into the queue for later retreival.
        que.push(graph[1][1].first);
        break;
      case FORK:
        // if it is fork than do the same for as above but with all 
        // of the nodes
        // after the first node
        numEdges = static_cast<Task *>(temp.first)->getNumEdges();

        for(int i = 1; i < numEdges; i++){
          que.push(graph[1][i].first);
        }
        break;
      case MERGE:
        cout << "Error: The first data node cannot merge!\n";
        error = true;
        break;
      case JOIN:
        cout << "Error: The first data node cannot join!\n";
        error = true;
        break;
      case DESICION:
        break;
      case START:
        cout << "Error: The graph may have been constructed wrong, "
             << "this node should not be of START type!\n";
        error = true;
        break;
      case STOP:
        cout << "Error: The graph may have been constructed wrong, "
             << "this node should not be of STOP type!\n";
        error = true;
        break;
    }
    if(error){
      temp.first  = NULL;
      temp.second = NULL;
    }
  } 
  else{
    // if its in the middle of traversing the graph than it pops the next
    // node off of the queue and finds it in the graph vector 
    // and then visits
    // its nodes and puts them in a queue depending on the type 
    //of tranistion.
    AbstractNode * node = que.front();
    que.pop();
    VecPairNodeEdge v;

    for(Graph::iterator i = graph.begin(); i != graph.end(); i++){
      v = (*i);

      if(node == v[0].first){
        temp = v[0];
        break;
      } 
    } 
    switch(v[0].first->getTraverseType()){
      case SEQUENTIAL:
        que.push(v[1].first);
        break;
      case FORK:
        numEdges = static_cast<Task *>(v[0].first)->getNumEdges();

        for(int i = 1; i < numEdges; i++){
          que.push(v[i].first);
        }
        break;
      case MERGE:
        break;
      case JOIN:
        break;
      case DESICION:
        break;
      case START:
        cout << "Error: The graph may have been constructed wrong, "
             << "this node should not be of START type!\n";
        error = true;
        break;
      case STOP:
        break;
    }
    if(error){
      temp.first  = NULL;
      temp.second = NULL;
    }
  }

  return temp;
}
