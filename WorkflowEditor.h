/*
 *	Name: 				Logan Pitman
 *	Date: 				November 20, 2012
 *	Organization:	Dalhousie - Faculty of Computer Science	
 * 
 *	Description: 	The Editor provides the user with the means to create new Workflow
 */
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class WorkflowEditor{
	private:
		fstream workflowFile;
		string * actorList;
		
	public:
		WorkflowEditor(void);
		~WorkflowEditor(void);
		
		// 		creating a workflow file
		void createWorkflowFile(string workflowId);
		
		//		display the list of workflows
		void displayWorkflowList(void);
		
		//		user interaction for creating a new workflow
		void newWorkflow(void);
		
		//		get the actors for a workflow
		string * getActors(void);
	
};
