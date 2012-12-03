/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 29, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  Contains some implementation stuff for the AbstractNode.
 */
#include "AbstractNode.h"

/******************************************************************
 * constructor
 *
 * Just initializes the type variable to 0.
 *****************************************************************/
AbstractNode::AbstractNode(void){
  type = 0;
}

/******************************************************************
 * getTraverseType 
 *
 * Default implementation for returning the traverse type.
 *****************************************************************/
int AbstractNode::getTraverseType(void){
  return type;
}

/******************************************************************
 * setTraverseType 
 *
 * Default implementation for setting the traverse type.
 *****************************************************************/
void AbstractNode::setTraverseType(int type){
  AbstractNode::type = type;
}
