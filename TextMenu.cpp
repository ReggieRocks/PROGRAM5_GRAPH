#include "TextMenu.h"
#include "Graph.h"
#include <iostream>

using namespace std;

int TextMenu::getChoice() {
    cout << "\n1. Read Graph\n";
    cout << "2. Print Graph\n";
    cout << "3. Topological Sort\n";
    cout << "4. Shortest Paths\n";
    cout << "5. Minimum Spanning Tree\n";
    cout << "6. Quit\n";
    cout << "Choice: ";

    int choice;
    cin >> choice;
    return choice;
}
