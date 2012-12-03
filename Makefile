#Author: Justin Patriquin
#ID:     B00549827
#File:   Makefile
#Developed for Faculty of Computer Science course CSCI 3132 assingment 4.

#Description:
#The make file that is used to build the generate executable.

OBJS = AbstractNode.o \
     Task.o \
     StartStopNode.o \
	   WorkflowGraph.o \
	   WorkflowLoader.o \
	   DecisionEdge.o \
	   WorkflowEditor.o \
     UserInterface.o \
	   main.o
	   
CC = g++
CFLAGS = -Wall -g
LFLAGS = -Wall -g
EXEC = workflow_management

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS)
	
clean:
	rm *.o $(EXEC)
