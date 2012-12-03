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
 
/******************************************************************
 * constructor
 *
 * Just initializes the decision variable to an empty string.
 *****************************************************************/
DecisionEdge::DecisionEdge(){
	decision = "";
}

/******************************************************************
 * setDecision 
 *
 * Sets the decision member variable.
 *****************************************************************/
void DecisionEdge::setDecision(string decision){
	DecisionEdge::decision = decision;
}

/******************************************************************
 * getDecision 
 *
 * Returns the decision member variable.
 *****************************************************************/
string DecisionEdge::getDecision(void){
	return decision;
}

