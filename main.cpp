#include <iostream>
#include "WorkflowEngine.h"
#include "WorkflowEditor.h"

int main(){
	cout << endl;
	int test;
	cout << "test number [Editor: 1, Loader: 2]: ";
	cin >> test;

	switch(test){
		case 1:{
			WorkflowEditor editor;
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
	}
	return 0;
}
