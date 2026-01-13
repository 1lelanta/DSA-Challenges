#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

// Graph data
string vertices[MAX];
int edges[MAX][MAX];

// Initialize adjacency matrix
void initGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;   // no edge
        }
    }
}

// Add weighted edge
void addEdge(int src, int dest, int weight) {
    edges[src][dest] = weight;
}

// Display adjacency matrix
void displayGraph(int n) {
    cout << "\nAdjacency Matrix (Weights):\n\n    ";
    for (int i = 0; i < n; i++)
        cout << "[" << i << "]  ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] ";
        for (int j = 0; j < n; j++) {
            cout << edges[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    int n = 7;

    // Vertex names (same order as image)
    vertices[0] = "Atlanta";
    vertices[1] = "Austin";
    vertices[2] = "Chicago";
    vertices[3] = "Dallas";
    vertices[4] = "Denver";
    vertices[5] = "Houston";
    vertices[6] = "Washington";

    initGraph(n);

    // Edges exactly as shown in the image
    addEdge(0, 5, 800);
    addEdge(0, 6, 600);

    addEdge(1, 3, 200);
    addEdge(1, 5, 160);

    addEdge(2, 4, 1000);

    addEdge(3, 1, 200);
    addEdge(3, 2, 900);
    addEdge(3, 4, 780);

    addEdge(4, 0, 1400);
    addEdge(4, 2, 1000);

    addEdge(5, 0, 800);

    addEdge(6, 0, 600);
    addEdge(6, 3, 1300);

    displayGraph(n);

    return 0;
}
