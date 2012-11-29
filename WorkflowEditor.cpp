/*
 *	Name: 				Logan Pitman
 *	Date: 				November 20, 2012
 *	Organization:	Dalhousie - Faculty of Computer Science	
 * 
 *	Description: 	The Editor provides the user with the means to create new Workflow
 */
#include "WorkflowEditor.h"

WorkflowEditor::WorkflowEditor(){

}

WorkflowEditor::~WorkflowEditor(){
	
}

//	display a list of existing workflows
void WorkflowEditor::displayWorkflowList(void){
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

//	This function opens the file that will be used to store the workflow
//	also, this is inputting the first line which will be the name of the workflow
void WorkflowEditor::createWorkflowFile(string workflowId){
	workflowFile.open(workflowId.c_str(), fstream::out);
		
	//check of the file is open	
	if(!workflowFile.is_open()){
		cout << "File could not be opened successfully: " << workflowId << endl;
		exit(1);
	}
	
	//input the first line
	workflowFile << workflowId << endl;

}

// this function creates a new workflow using the others as helper functions
void WorkflowEditor::createWorkflow(void){
	//get the name of the workflow 
	string workflowName;
	cout << "Enter a name for the new workflow (no spaces): ";
	cin >> workflowName;
	cout << endl;
	
	//create the workflow file with the given name
	createWorkflowFile(workflowName);
	
	// get the actors in the workflow
	actorList = getActors();
	
	//get the starting node 
	cout << "For the starting position: \n\tactor(number): ";
	int i_actor;
	cin >> i_actor;
	string actor = actorList[i_actor];
	//workflowFile << actor << ",";
	string nodeString = createNode(actor);
	workflowFile << nodeString << endl;
	
	
	workflowFile.close();
}

string * WorkflowEditor::getActors(){
	cout << "How many actors will you need for your workflow?\n\n";
   
    int actorSize;
    cin >> actorSize;        
    string * actorsArray = new string[sizeof(string) * actorSize];
   
    cout << "\nEnter a name of an actor to use in your workflow, followed by ENTER.\n\n";
	cin >> actorsArray[0];	
	
    string actor;
    int i = 1;
    while(actor.compare("0")!=0) {                
        if(i>actorSize-1)
        {
            cout << "\n\nYou've reached your maximum amount of actors.\n\n";
            break;
        }
        else
        {              
            actorsArray[i] = actor;  
            i++; 
            cin >> actor;
        }
    }
   
    cout << "\n\nThank you!\n\n";
	
	return actorsArray;
   
    //int ii = 0;
    //while (ii < actorSize){
        //cout << ii;
        //cout << actorsArray[ii] << endl;
        //ii++;
    //}
    //cout << "Hey, you're finished";
    //delete [] actorsArray;
}

//	this function will get user input and create each of the nodes
string WorkflowEditor::createNode(string actor){
	string node = actor;
	node += ",";
	string task, transition, numEdges;
	
	//create a list of input questions
 	string * inputList = new string[sizeof(string) * 3];
	inputList[0] = "\n\tTask: ";
	inputList[1] = "\n\tTransition Type: ";
	inputList[2] = "\n\tNumber of edges: ";
	
	cout << inputList[0];
	cin >> task;
	node += task;
	node += ",";
	
	cout << inputList[1];
	cin >> transition;
	node += transition;
	node += ",";
	
	cout << inputList[2];
	cin >> numEdges;
	node += numEdges;
	node += ",";
	
	long l_numEdges = strtol(numEdges.c_str(), NULL, 10);
	
	if (transition.compare("decision") == 0){
		string decision;
		int i;
		for(i = 0; i < l_numEdges; i++){
			cout << "\n\tDecision " << 	i+1 << ": ";
			cin >> decision;
			node += decision;
			node += ",";	
		}
	}
	
	cout << "\nNode created.\n";
	
	return node;
}
