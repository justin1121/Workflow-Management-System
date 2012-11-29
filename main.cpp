#include <iostream>
#include "WorkflowEngine.h"

int main(){
	WorkflowLoader load("test.txt");

  load.openFile();
  load.generateGraph();
  load.closeFile();

	return 0;
}
