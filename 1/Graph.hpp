#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>
#include <random>

class Graph {
private:
    int V;                              // Number of vertices
    std::vector<std::list<int>> adj;    // Adjacency list
    std::vector<int> degree;            // Degree of each vertex

public:
    // Constructor
    explicit Graph(int vertices);
    
    // Graph functions
    void addEdge(int v1, int v2);
    bool hasEulerCircuit() const;
    std::vector<int> findEulerCircuit();
    void print() const;
    
    // Static function to generate a random graph
    static Graph generateRandom(int vertices, int edges, int seed);
};

#endif // GRAPH_HPP