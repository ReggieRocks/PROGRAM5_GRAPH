/*
 * File: Graph.h
 * Author: Scott Schmidt
 *
 * Description:
 * This file defines the Graph class used for Program 5.
 * The Graph class represents a weighted graph and provides
 * functionality to:
 *  - Read a graph from an input file
 *  - Print the graph in the required format
 *  - Compute a topological ordering of the graph
 *  - Compute shortest paths using Dijkstra’s algorithm
 *  - Compute a minimum spanning tree using Kruskal’s algorithm
 *
 * Note:
 * This file was created by the student for this assignment.
 * It is not a provided starter file.
 */

#include "Graph.h"
#include <iostream>

Graph::Graph() {}

/*
 * readGraph:
 *  - Accepts the name of a file as a parameter.
 *  - Reads in a new graph from that file, replacing any existing data.
 *  - Returns true if the file was opened and read successfully.
 *  - Returns false if the file could not be opened.
 *  - Does NOT print anything to the console under any circumstances.
 */
void Graph::readGraph(const string& filename)
{
    cout << "readGraph(" << filename << ")\n";
}

/*
printGraph:
will print your graph to standard output (cout) in the same format as the graphs you are reading.
This must read the data from your class member variables (e.g., adjacency matrix/list, etc.), 
and is primarilty meant to be used as a debugging tool for you.
Do not just store the file contents in a string and regurgitate them to the console
*/
void Graph::printGraph() {
    std::cout << "printGraph()\n";
}

/*
computeTopologicalSort:
print to standard output a topological sort of the graph or an error message indicating that a topological sort of the graph is not possible. 
You will use a queue for the algorithm. See below for the exact output format.
*/
void Graph::computeTopologicalSort() {
    // TODO: compute indegree of each vertex
    void Graph::computeTopologicalSort() {
    vector<int> indegree(numVertices, 0);
    queue<int> q; //declare the q
    int processed = 0;
    
    // for every edge (connection between nodes) increase indegree by one:
    for (int u = 0; u < numVertices; u++) {
        for (int v : adjList[u]) {
            indegree[v]++;
        }
    }
    // TODO: push all indegree-0 vertices into a queue
    
    // TODO: process queue (Kahn’s algorithm)
    // TODO: detect cycle
    // TODO: print topological ordering OR error
}

/*
computeShortestPaths:
-Accept a node name as a parameter
-Print to standard output the actual path and the cost to each other vertex that can be reached (one path and cost per line). For any nodes that cannot be reached, it will print a message indicating that. Again, see below for the exact output format. 
-Use Dijkstra’s algorithm implemented using a priority queue 
*/

void Graph::computeShortestPaths() {
    std::cout << "shortestPaths()\n";
}

/*
ComputeMinimumSpanningTree:
-Print to standard output a list of the edges in the minimum spanning tree for the graph, one per line, with the weight of each edge, followed by the total weight of the minimum spanning tree. See below for the exact output format. 
-Your method will have the graph being connected as a precondition (and your comments must make that clear). 
-You will compute the minimum spanning tree with Kruskal’s algorithm, using your DisjointSet class from program 4. In order to guarantee that your results match the provided output, make sure that your sort of the edges orders by edge weight (obviously), then index of the from node, then index of the to node.
-If you are allocating memory dynamically, your class MUST handle it correctly.
-May use relevant STL classes such as vector, list, stack, queue, priority_queue, etc. 
-There is a sample program for making a vector of vectors provided.
-Making a vector of lists is very similar (but a little easier)).
*/
void Graph::computeMinimumSpanningTree() {
    std::cout << "mst()\n";
}