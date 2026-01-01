// Graph.cpp
#include "Graph.h"
#include "DisjointSet.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>

Graph::Graph() {}

void Graph::clear() {
    indexToName.clear();
    nameToIndex.clear();
    adj.clear();
    edges.clear();
}

int Graph::getIndexOrNeg1(const std::string& name) const {
    auto it = nameToIndex.find(name);
    if (it == nameToIndex.end()) return -1;
    return it->second;
}

bool Graph::readGraph(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) return false;

    clear();

    int n = 0;
    in >> n;
    if (!in || n < 0) {
        clear();
        return false;
    }

    indexToName.resize(static_cast<size_t>(n));
    nameToIndex.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; i++) {
        in >> indexToName[static_cast<size_t>(i)];
        nameToIndex[indexToName[static_cast<size_t>(i)]] = i;
    }

    adj.assign(static_cast<size_t>(n), {});

    int m = 0;
    in >> m;
    if (!in || m < 0) {
        clear();
        return false;
    }

    edges.reserve(static_cast<size_t>(m));
    for (int i = 0; i < m; i++) {
        std::string fromName, toName;
        int w = 0;
        in >> fromName >> toName >> w;
        if (!in) {
            clear();
            return false;
        }

        int from = getIndexOrNeg1(fromName);
        int to = getIndexOrNeg1(toName);
        if (from < 0 || to < 0) {
            clear();
            return false;
        }

        adj[static_cast<size_t>(from)].push_back({to, w});
        edges.push_back(Edge{from, to, w});
    }

    // Make behavior deterministic across runs.
    for (auto& nbrs : adj) {
        std::sort(nbrs.begin(), nbrs.end(),
                  [](const auto& a, const auto& b) { return a.first < b.first; });
    }

    return true;
}

void Graph::printGraph() {
    std::cout << indexToName.size() << "\n";
    for (const auto& name : indexToName) {
        std::cout << name << "\n";
    }

    std::cout << edges.size() << "\n";
    for (const auto& e : edges) {
        std::cout << indexToName[static_cast<size_t>(e.from)] << " "
                  << indexToName[static_cast<size_t>(e.to)] << " " << e.weight << "\n";
    }
}

void Graph::computeTopologicalSort() {
    std::cout << "Topological Sort:\n";

    const int n = static_cast<int>(indexToName.size());
    if (n == 0) {
        std::cout << "This graph cannot be topologically sorted.\n";
        return;
    }

    std::vector<int> indeg(static_cast<size_t>(n), 0);
    for (int u = 0; u < n; u++) {
        for (const auto& [v, w] : adj[static_cast<size_t>(u)]) {
            (void)w;
            indeg[static_cast<size_t>(v)]++;
        }
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[static_cast<size_t>(i)] == 0) q.push(i);
    }

    std::vector<int> order;
    order.reserve(static_cast<size_t>(n));
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (const auto& [v, w] : adj[static_cast<size_t>(u)]) {
            (void)w;
            int& d = indeg[static_cast<size_t>(v)];
            d--;
            if (d == 0) q.push(v);
        }
    }

    if (static_cast<int>(order.size()) != n) {
        std::cout << "This graph cannot be topologically sorted.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) std::cout << " --> ";
        std::cout << indexToName[static_cast<size_t>(order[static_cast<size_t>(i)])];
    }
    std::cout << "\n";
}

void Graph::computeShortestPaths(const std::string& startNodeName) {
    std::cout << "Shortest paths from " << startNodeName << ":\n";

    const int start = getIndexOrNeg1(startNodeName);
    const int n = static_cast<int>(indexToName.size());
    if (start < 0 || n == 0) return;

    const int INF = std::numeric_limits<int>::max() / 4;
    std::vector<int> dist(static_cast<size_t>(n), INF);
    std::vector<int> prev(static_cast<size_t>(n), -1);

    using PQItem = std::pair<int, int>; // (dist, node)
    std::priority_queue<PQItem, std::vector<PQItem>, std::greater<PQItem>> pq;

    dist[static_cast<size_t>(start)] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[static_cast<size_t>(u)]) continue;

        for (const auto& [v, w] : adj[static_cast<size_t>(u)]) {
            if (d + w < dist[static_cast<size_t>(v)]) {
                dist[static_cast<size_t>(v)] = d + w;
                prev[static_cast<size_t>(v)] = u;
                pq.push({dist[static_cast<size_t>(v)], v});
            }
        }
    }

    for (int target = 0; target < n; target++) {
        if (target == start) continue;

        if (dist[static_cast<size_t>(target)] >= INF) {
            std::cout << "No path from " << startNodeName << " to "
                      << indexToName[static_cast<size_t>(target)] << " found.\n";
            continue;
        }

        // Reconstruct path start -> target
        std::vector<int> path;
        for (int cur = target; cur != -1; cur = prev[static_cast<size_t>(cur)]) {
            path.push_back(cur);
        }
        std::reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); i++) {
            if (i > 0) std::cout << " --> ";
            std::cout << indexToName[static_cast<size_t>(path[i])];
        }
        std::cout << " || Weight: " << dist[static_cast<size_t>(target)] << "\n";
    }
}

void Graph::computeMinimumSpanningTree() {
    std::cout << "Minimum Spanning Tree:\n";

    const int n = static_cast<int>(indexToName.size());
    if (n == 0) {
        std::cout << "Total Cost: 0\n";
        return;
    }

    std::vector<Edge> sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(), [](const Edge& a, const Edge& b) {
        if (a.weight != b.weight) return a.weight < b.weight;
        if (a.from != b.from) return a.from < b.from;
        return a.to < b.to;
    });

    DisjointSet ds(n);
    long long total = 0;
    int used = 0;

    for (const auto& e : sortedEdges) {
        int ra = ds.find(e.from);
        int rb = ds.find(e.to);
        if (ra == rb) continue;

        ds.unite(ra, rb);
        std::cout << indexToName[static_cast<size_t>(e.from)] << " -- "
                  << indexToName[static_cast<size_t>(e.to)] << " || Weight: " << e.weight
                  << "\n";
        total += e.weight;
        used++;
        if (used == n - 1) break;
    }

    std::cout << "Total Cost: " << total << "\n";
}
