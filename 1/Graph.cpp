#include "Graph.hpp"
#include <iostream>
#include <stack>

// Constructor
Graph::Graph(int vertices) : V(vertices) {
    adj.resize(V);
    degree.resize(V, 0);
}

// Add edge to graph
void Graph::addEdge(int v1, int v2) {
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
    degree[v1]++;
    degree[v2]++;
}

// Check if Euler circuit exists
bool Graph::hasEulerCircuit() const {
    for (int i = 0; i < V; i++) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Find Euler circuit
std::vector<int> Graph::findEulerCircuit() {
    std::vector<int> circuit;
    if (!hasEulerCircuit()) {
        return circuit;
    }
    
    // Create a copy of the adjacency list
    std::vector<std::list<int>> adjCopy = adj;
    std::stack<int> currentPath;
    currentPath.push(0);  // Start from vertex 0

    while (!currentPath.empty()) {
        int v = currentPath.top();

        if (adjCopy[v].empty()) {
            circuit.push_back(v);
            currentPath.pop();
        } else {
            int u = adjCopy[v].front();
            currentPath.push(u);
            adjCopy[v].remove(u);
            adjCopy[u].remove(v);
        }
    }

    return circuit;
}

// Print graph
void Graph::print() const {
    for (int v = 0; v < V; ++v) {
        std::cout << "Vertex " << v << " -> ";
        for (int u : adj[v]) {
            std::cout << u << " ";
        }
        std::cout << "\n";
    }
}

// Generate random graph
Graph Graph::generateRandom(int vertices, int edges, int seed) {
    Graph g(vertices);
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, vertices - 1);

    int addedEdges = 0;
    while (addedEdges < edges) {
        int v1 = dis(gen);
        int v2 = dis(gen);
        
        if (v1 != v2) {
            bool edgeExists = false;
            for (int neighbor : g.adj[v1]) {
                if (neighbor == v2) {
                    edgeExists = true;
                    break;
                }
            }
            
            if (!edgeExists) {
                g.addEdge(v1, v2);
                addedEdges++;
            }
        }
    }
    return g;
}