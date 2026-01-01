// graphRunner.cpp
#include <iostream>
#include "Graph.h"
#include "TextMenu.h"

using namespace std;

int main() {
    Graph g;
    TextMenu menu;

    bool done = false;
    while (!done) {
        int choice = menu.getChoice();

        switch (choice) {
            case 1:
                g.readGraph();
                break;
            case 2:
                g.printGraph();
                break;
            case 3:
                g.computeTopologicalSort();
                break;
            case 4:
                g.computeShortestPaths();
                break;
            case 5:
                g.computeMinimumSpanningTree();
                break;
            case 6:
                done = true;
                break;
        }
    }
    return 0;
}
