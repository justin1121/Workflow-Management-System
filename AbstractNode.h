/*
 *	Name: 			  Justin Patriquin
 *	Date: 			  November 29, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  The AbstractNode's definition.
 */

class AbstractNode{
  public:
    AbstractNode();
    virtual int getTraverseType(void);
    virtual void setTraverseType(int);
  protected:
    int type;
};

