#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

// Edge node (linked list)
struct EdgeNode {
    int adjIndex;          // index of adjacent vertex
    int weight;            // edge weight
    EdgeNode* next;        // next edge
};

// Vertex node (graph array element)
struct GraphVertex {
    string name;           // city name
    EdgeNode* head;        // pointer to first edge
};

// Graph as 1D array
GraphVertex graph[MAX];

// Initialize graph
void initGraph(int n) {
    for (int i = 0; i < n; i++) {
        graph[i].head = NULL;
    }
}

// Add edge (directed, weighted)
void addEdge(int src, int dest, int weight) {
    EdgeNode* newNode = new EdgeNode;
    newNode->adjIndex = dest;
    newNode->weight = weight;
    newNode->next = graph[src].head;
    graph[src].head = newNode;
}

// Display graph
void displayGraph(int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] " << graph[i].name << " -> ";
        EdgeNode* temp = graph[i].head;
        while (temp != NULL) {
            cout << "(" << temp->adjIndex
                 << ", " << temp->weight << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    int n = 7;

    // Assign city names (same as diagram)
    graph[0].name = "Atlanta";
    graph[1].name = "Austin";
    graph[2].name = "Chicago";
    graph[3].name = "Dallas";
    graph[4].name = "Denver";
    graph[5].name = "Houston";
    graph[6].name = "Washington";

    initGraph(n);

    // Edges from diagram
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

    // Display
    displayGraph(n);

    return 0;
}
