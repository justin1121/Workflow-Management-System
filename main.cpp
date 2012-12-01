#include <iostream>
#include "WorkflowEngine.h"
#include "WorkflowEditor.h"

int main(){
	cout << endl;
	int test;
	cout << "test number [Editor: 1, Loader: 2, List Workflows: 3]: ";
	cin >> test;
	WorkflowEditor editor;

	switch(test){
		case 1:{
			editor.createWorkflow();
			break;
		}	
		case 2:{
			WorkflowLoader load("test.txt");
			WorkflowGraph graph;
			load.openFile();
			graph = load.createGraph(); 
			graph = load.generateGraph(graph);
			load.closeFile();
			break;
		}
		case 3:{
			editor.displayWorkflowList();
			break;
		}
		default :{
			cout << "\n\t"<< test << " not a transition type.. exiting.." << endl;
			exit(1);
		}
	}
	return 0;
}
