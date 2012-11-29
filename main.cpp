#include <iostream>
#include "WorkflowEngine.h"
#include "WorkflowEditor.h"

int main(){
	WorkflowEditor editor;
	editor.createWorkflow();


	WorkflowLoader load("test.txt");

  load.openFile();
  load.generateGraph();
  load.closeFile();

	return 0;
}
