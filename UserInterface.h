/*
 *	Name: 			  Chris Dingwell 
 *	Date: 			  November 22, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  Handles the start of the UI and than hands it off to the module
 *  of the user's choice.
 */
#include "WorkflowEditor.h"
#include "WorkflowEngine.h"

class UserInterface {
public:
    int getInput(void);
    void startEditing(void);
    void startSimulating(void);
    void showWorkflowList(void);
private:
    WorkflowEditor editor;
    WorkflowLoader loader;
    WorkflowGraph  graph;
};

