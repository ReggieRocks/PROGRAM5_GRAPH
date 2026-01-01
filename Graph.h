/*
 * File: Graph.h
 * Author: Scott Schmidt, DataStructures using Graphs. 
 *
 * Description:
 * Defines the Graph class for Program 5. This class represents a
 * weighted graph and provides the operations required by the
 * assignment, including reading a graph from a file and
 * executing graph algorithms.
 *
 * Note:
 * This file was created by the student and is not a provided
 * starter file.
 */
 

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
    Graph();

    void readGraph();
    void printGraph();
    void computeTopologicalSort();
    void computeShortestPaths();
    void computeMinimumSpanningTree();
};

#endif
