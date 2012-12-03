/*
 *	Name: 			  Chris Dingwell 
 *	Date: 			  November 22, 2012
 * 	Organization:	Dalhousie - Faculty of Computer Science
 *	
 * 	Description:
 *  Handles the start of the UI and than hands it off to the module
 *  of the user's choice.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "UserInterface.h"

using namespace std;

int UserInterface::getInput() {
    
    cout << "Welcome. Select a number option from the list below. \n\n1. BUILD Workflow \n2. VIEW Workflows \n3. SIMULATE Workflow\n";
    char choice;
    
    while((choice!='1') && (choice!='2') && (choice!='3'))
    {  
    cin >> choice;
    
    switch (choice)
    {
    case '1':
        startEditing();
        break;
    case '2':
        showWorkflowList();
        break;
    case '3': 
        startSimulating();
        break;
    default: cout << "Please make another selection\n\n";
        break;
    }
    }
    
}

void UserInterface::startEditing(void){
    editor.createWorkflow();
}

void UserInterface::startSimulating(void){
    string fileName;
    
    cout << "Which workflow do you want to simulate?\n";
    editor.displayWorkflowList();
    cout << endl;

    cin >> fileName;  
    
    loader.setFileName(fileName);
    loader.openFile();
    graph = loader.createGraph();
    graph = loader.generateGraph(graph);

    simulator.setGraph(graph);
    simulator.simulate();
}

void UserInterface::showWorkflowList(void){
    editor.displayWorkflowList();
    exit(0);
}
