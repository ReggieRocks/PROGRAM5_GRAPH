#include "DisjointSet.h"

// Constructor
DisjointSet::DisjointSet(int n) {
    parent.resize(n);
    rank.resize(n, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;   // each element starts in its own set
    }
}

// Find with path compression
int DisjointSet::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union by rank
void DisjointSet::unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) return;

    if (rank[rootA] < rank[rootB]) {
        parent[rootA] = rootB;
    }
    else if (rank[rootA] > rank[rootB]) {
        parent[rootB] = rootA;
    }
    else {
        parent[rootB] = rootA;
        rank[rootA]++;
    }
}
