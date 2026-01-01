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
