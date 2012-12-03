/*
 * File:   Simulator.h
 * Author: Chris Dingwell
 *
 * Created on November 29, 2012, 3:29 PM
 */
 
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>

#include "WorkflowEngine.h"
 
class Simulator {
public:
    string displayTask(Task);
    void setGraph(WorkflowGraph graph);
    void simulate(void);
    void askIfCompleted(Task *);
private:
    WorkflowGraph graph; 
};
 
#endif  /* SIMULATOR_H */
