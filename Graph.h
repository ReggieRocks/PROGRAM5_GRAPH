#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Graph {
public:
    Graph();

    // Reads a new graph from the given file, replacing any existing graph data.
    // Returns true on success; returns false if the file could not be opened.
    // Does not print anything.
    bool readGraph(const std::string& filename);
    void printGraph();
    void computeTopologicalSort();
    void computeShortestPaths(const std::string& startNodeName);
    void computeMinimumSpanningTree();

private:
    struct Edge {
        int from = -1;
        int to = -1;
        int weight = 0;
    };

    std::vector<std::string> indexToName;
    std::unordered_map<std::string, int> nameToIndex;
    std::vector<std::vector<std::pair<int, int>>> adj; // (to, weight)
    std::vector<Edge> edges;

    void clear();
    int getIndexOrNeg1(const std::string& name) const;
};

#endif
