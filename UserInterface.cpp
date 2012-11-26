#include "UserInterface.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

UserInterface::UserInterface() {

}

UserInterface::~UserInterface() {
}

int UserInterface::input() {
    
    cout << "Welcome. Select a number option from the list below. \n\n1. BUILD Workflow \n2. VIEW Workflow \n3. USE Workflow\n";
    char choice;
    
    while((choice!='1') && (choice!='2') && (choice!='3'))
    {  
    cin >> choice;
    
    switch (choice)
    {
    case '1': cout << "You picked one";
        break;
    case '2': cout << "You picked two";
        break;
    case '3': cout << "You picked three";
        break;
    default: cout << "Please make another selection\n\n";
        break;
    }
    }
    
}
