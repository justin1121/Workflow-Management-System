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
	list<string> list;
	
	while(!listfile.eof()){
		char * c_workflow;
		workflow = listfile.getline(c_workflow, 256);
		string workflow = c_workflow;
		
		list.push_back(workflow);
	}
	
	list<string>::iterator it;
	
	cout << "These are the available workflows: " << endl;
	
	for (it = list.begin(); it != mylist.end(); it++){
		cout << "	" << *it << endl;
	}
}
