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
#include <sstream>
#include <string>
#include <list>
using namespace std;


class WorkflowEditor{
	private:
		fstream 	workflowFile;
		string * 	actorList;
		int 		edgeCount;
		
		//		get the actors for a workflow
		string * getActors(void);
		
		//		create a node/line for the workflow
		
		string createNode(string actor);
		
		// 		creating a workflow file
		void createWorkflowFile(string workflowId);
		
		//		add new workflow to the list.txt
		void addWorkflow2List (string name);
		
		//		handle the different types of transition that can be chosen
		string handleTransition(int type);
		
	public:
		WorkflowEditor(void);
		~WorkflowEditor(void);
		
		//		display the list of workflows
		void displayWorkflowList(void);
		
		//		user interaction for creating a new workflow
		void createWorkflow(void);
	
};
