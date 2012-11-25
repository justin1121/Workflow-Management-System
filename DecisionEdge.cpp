/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 25, 2012
 * 	Organization:	  Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  This is a special case of the edge. Normally an edge has no
 *  representation, but if there is a desicion to make this 
 *  class holds the question.
 */
 
 #include "WorkflowEngine.h"
 
DecisionEdge::DecisionEdge(){
	decision = "";
}

void DecisionEdge::setDecision(string decision){
	DecisionEdge::decision = decision;
}

string DecisionEdge::getDecision(void){
	return decision;
}

