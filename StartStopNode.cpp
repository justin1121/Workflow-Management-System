/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 29, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  Contains the StartStopNode implementation.
 */

#include "WorkflowEngine.h"

/******************************************************************
 * getActor 
 *
 * Returns the actor member variable.
 *****************************************************************/
string StartStopNode::getActor(void){
  return actor;
}

/******************************************************************
 * setActor 
 *
 * Sets the actor member variable.
 *****************************************************************/
void StartStopNode::setActor(string actor){
  StartStopNode::actor = actor;
}

/******************************************************************
 * getMessage
 *
 * Returns the message member variable.
 *****************************************************************/
string StartStopNode::getMessage(void){
  return message; 
}

/******************************************************************
 * setMessage 
 *
 * Sets the message member variable.
 *****************************************************************/
void StartStopNode::setMessage(string message){
  StartStopNode::message = message;
}

/******************************************************************
 * getTraverseType 
 *
 * Returns the type member variable.
 *****************************************************************/
int StartStopNode::getTraverseType(void){
  return type;
}

/******************************************************************
 * setTraverseType 
 *
 * Sets the type member variable.
 *****************************************************************/
void StartStopNode::setTraverseType(int type){
	StartStopNode::type = type;
}
