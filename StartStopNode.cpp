/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 29, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  Contains the StartStopNode implementation.
 */

#include "WorkflowEngine.h"

string StartStopNode::getMessage(void){
  return message; 
}

void StartStopNode::setMessage(string message){
  StartStopNode::message = message;
}

int StartStopNode::getTraverseType(void){
  return type;
}

void StartStopNode::setTraverseType(int type){
	StartStopNode::type = type;
}
