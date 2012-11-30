/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 29, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  Contains some implementation stuff for the AbstractNode.
 */
#include "AbstractNode.h"

AbstractNode::AbstractNode(void){
  type = 0;
}

int AbstractNode::getTraverseType(void){
  return type;
}

void AbstractNode::setTraverseType(int type){
  AbstractNode::type = type;
}
