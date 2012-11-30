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

enum trans_enum{
  SEQUENTIAL = 0,
  FORK,
  MERGE,
  JOIN,
  DESICION
};

class WorkflowEditor{
	private:
		fstream 	workflowFile;
		string * 	actorList;
		int 		edgeCount;
		
	public:
		WorkflowEditor(void);
		~WorkflowEditor(void);
		
		// 		creating a workflow file
		void createWorkflowFile(string workflowId);
		
		//		display the list of workflows
		void displayWorkflowList(void);
		
		//		user interaction for creating a new workflow
		void createWorkflow(void);
		
		//		get the actors for a workflow
		string * getActors(void);
		
		//		create a node/line for the workflow
		
		string createNode(string actor); 
	
};
