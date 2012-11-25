/*
 *	Name: 				Logan Pitman
 *	Date: 				November 20, 2012
 *	Organization:	Dalhousie - Faculty of Computer Science	
 * 
 *	Description: 	The Editor provides the user with the means to create new Workflow
 */
#include "WorkflowEditor.h"

//	display a list of existing workflows
void displayWorkflowList(void){
	char * filename = "list.txt";
	fstream listFile;
	listFile.open(filename, fstream::in);
	list<string> flowList;
	
	while(!listFile.eof()){
		char * c_workflow;
		string workflow;
		listFile.getline(c_workflow, 256);
		workflow = c_workflow;
		
		flowList.push_back(workflow);
	}
	
	list<string>::iterator it;
	
	cout << "These are the available workflows: " << endl;
	
	for (it = flowList.begin(); it != flowList.end(); it++){
		cout << "	" << *it << endl;
	}
}
