#include <iostream>
#include <getopt.h>
#include <cstdlib>
#include "Graph.hpp"

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " -v <vertices> -e <edges> -s <seed>\n";
    std::cout << "Options:\n";
    std::cout << "  -v <num>    Number of vertices\n";
    std::cout << "  -e <num>    Number of edges\n";
    std::cout << "  -s <num>    Random seed\n";
    std::cout << "  -h          Show this help message\n";
}

int main(int argc, char* argv[]) {
    int vertices = 0;
    int edges = 0;
    int seed = 42;  // Default seed
    int opt;

    while ((opt = getopt(argc, argv, "v:e:s:h")) != -1) {
        switch (opt) {
            case 'v':
                vertices = std::atoi(optarg);
                break;
            case 'e':
                edges = std::atoi(optarg);
                break;
            case 's':
                seed = std::atoi(optarg);
                break;
            case 'h':
                printUsage(argv[0]);
                return 0;
            default:
                printUsage(argv[0]);
                return 1;
        }
    }

    if (vertices <= 0 || edges <= 0) {
        std::cerr << "Error: Invalid number of vertices or edges\n";
        printUsage(argv[0]);
        return 1;
    }

    // Generate random graph
    Graph g = Graph::generateRandom(vertices, edges, seed);
    
    std::cout << "Generated Graph:\n";
    g.print();

    // Find and print Euler circuit
    if (g.hasEulerCircuit()) {
        std::cout << "\nEuler Circuit exists!\n";
        std::vector<int> circuit = g.findEulerCircuit();
        std::cout << "Circuit: ";
        for (int v : circuit) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "\nNo Euler Circuit exists in this graph\n";
    }

    return 0;
}