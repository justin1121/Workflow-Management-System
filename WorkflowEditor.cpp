/*
 *	Name: 				Logan Pitman
 *	Date: 				November 20, 2012
 *	Organization:	Dalhousie - Faculty of Computer Science	
 * 
 *	Description: 	The Editor provides the user with the means to create a new Workflow
 */
#include "WorkflowEditor.h"

WorkflowEditor::WorkflowEditor(){

}

WorkflowEditor::~WorkflowEditor(){

}

//	display a list of existing workflows
void WorkflowEditor::displayWorkflowList(void){
	fstream listFile;
	listFile.open("list.txt", fstream::in);
	list<string> flowList;
	
	while(!listFile.eof()){
		string workflow;
		getline(listFile, workflow);
		
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
	string filename = workflowId;
	filename.append(".wf");
	workflowFile.open(filename.c_str(), fstream::out);
			
	//check of the file is open	
	if(!workflowFile.is_open()){
		cout << "File could not be opened successfully: " << workflowId << endl;
		exit(1);
	}
	
	//input the first line
	workflowFile << workflowId << endl;

}

string * WorkflowEditor::getActors(){
	cout << "How many actors will you need for your workflow?: ";
   
    int actorSize;
    cin >> actorSize;        
    string * actorsArray = new string[sizeof(string) * actorSize];
   
    cout << "\n\nEnter a name of an actor to use in your workflow, followed by ENTER:\n";
	
    string actor;
    int i = 0;
    while(i <= actorSize) {                	
		if(i == actorSize)
		{
            cout << "\nActors added.\n";
            break;
        }
        else
        {    
			cin >> actorsArray[i];	  
            i++; 
        }
    }
   	
	cout << "\nActor List: \n";
	
    int ii = 0;
    while (ii < actorSize){
      cout << "\t";
	  cout << ii+1 << ": ";
      cout << actorsArray[ii] << endl;
      ii++;
    }
	
	return actorsArray;
	
}

//	this function will get user input and create each of the nodes
string WorkflowEditor::createNode(string actor){
	string node = actor;
	node += ",";
	string task, numEdges;
	int transition;
	
	//create a list of input questions
 	string * inputList = new string[sizeof(string) * 3];
	inputList[0] = "\tTask: ";
	inputList[1] = "\tTransition Type: ";
	inputList[2] = "/tNumber of Edges: ";
	
	cout << inputList[0];
	cin.ignore();
	getline(cin,task);
	node += task;
	node += ",";
	
	cout << inputList[1];
	cin >> transition;
	stringstream transString;
	transString << transition;
	node += transString.str();
	node += ",";
	
	//cout << inputList[2];
	//cin >> numEdges;
	//node += numEdges;
	//node += ",";
	
	//long l_numEdges = strtol(numEdges.c_str(), NULL, 10);
	//edgeCount = l_numEdges;
	
	//	handle transition
	node += handleTransition(transition);
	
	/*
	if (transition.compare("5") == 0){
		string decision;
		int i;
		for(i = 0; i < l_numEdges; i++){
			cout << "\n\tDecision " << 	i+1 << ": ";
			cin >> decision;
			node += decision;
			node += ",";	
		}
	}
	*/
	
	cout << "\nNode created.\n";
	
	return node;
}

//		add new workflow to the list.txt
void WorkflowEditor::addWorkflow2List (string name){
	fstream listfile;
	listfile.open("list.txt", fstream::out | fstream::app);
	
	listfile << name << endl;
	
	listfile.close();
}

//		handle the different types of transition that can be chosen
string WorkflowEditor::handleTransition(int type){
	switch(type){
		
		//	sequential
		case 1:{
			edgeCount = 1;
			return "1,0,";
		}
		
		//	fork
		case 2:{
			string forkNum, forkString;
			
			cout << "\tNumber of forks: ";
			cin >> forkNum;
			edgeCount = strtol(forkNum.c_str(), NULL, 10);
			forkString += forkNum;
			forkString += ",0,";
			return forkString;
		}
		
		//	merge
		case 3:{
			cout << "\nMerging." << endl;
			edgeCount = 1;
			return "1,0,";
		}
		
		//	join
		case 4:{
			cout << "\nJoining." << endl;
			edgeCount = 1;
			return "1,0,";
		}
		
		//	decision
		case 5:{
			string decision;
			string allDecisions = "";
			int numDecisions;
			cout << "\tNumber of decisions: ";
			cin >> numDecisions;
			edgeCount = numDecisions;
			
			int i;
			for(i = 0; i < numDecisions; i++){
				cout << "\n\tDecision " << 	i+1 << ": ";
				cin.ignore();
				getline(cin, decision);
				allDecisions += decision;
				allDecisions += ",";
			
			}
			return allDecisions;
		}
		
		//	start
		case 6:{
			edgeCount = 1;
			return "1,0,";
		}
		
		// 	stop
		case 7:{
			edgeCount = 0;
			return "0,0,";
		}
		
		default :{
			cout << "\nNot an available transition type." << endl;
			exit(1);
		}
	}
}

// this function creates a new workflow using the others as helper functions
void WorkflowEditor::createWorkflow(void){
	//get the name of the workflow 
	string workflowName;
	cout << "Enter a name for the new workflow (no spaces): ";
	cin >> workflowName;
	
	//create the workflow file with the given name
	createWorkflowFile(workflowName);
	
	// get the actors in the workflow
	actorList = getActors();
	
	// show the different types of transitions
	string transArray [] = {"SEQUENTIAL", "FORK", "MERGE", "JOIN", "DECISION","START", "STOP"}; 
	cout << "\nTransition list:";
	int i;
	for(i = 0; i < 7; i++){
		cout << "\n\t" << i+1;
		cout << ": " << transArray[i];
	}
	
	//get the starting node 
	cout << "\n\nFor the starting position: \n\tActor(number): ";
	int i_actor;
	cin >> i_actor;
	string actor = actorList[i_actor-1];
	string nodeString = createNode(actor);
	workflowFile << nodeString << endl;
	
	// continue to create nodes till the end
	while (edgeCount != 0){
		cout << "\nFor the next node: \n\tActor(number): ";
		cin >> i_actor;
		actor = actorList[i_actor-1];
		nodeString = createNode(actor);
		workflowFile << nodeString << endl;
	}
	
	/*
	// get the terminal node information
	cout << "\nFor the terminal position: \n\tactor(number): ";
	cin >> i_actor;
	actor = actorList[i_actor];
	workflowFile << actor << ",0,7,0" << endl;
	*/
	
	// add the workflow to the list.txt
	addWorkflow2List(workflowName);
	
	cout << "\nWorkflow file created." << endl;
	
	workflowFile.close();
}
