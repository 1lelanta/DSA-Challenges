#include <iostream>
using namespace std;

const int MAX = 100;

// Initialize adjacency matrix
void initMatrix(int graph[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

// Add edge to the graph
void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;     
    graph[v][u] = 1;   


void printMatrix(int graph[MAX][MAX], int n) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, edges;
    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    initMatrix(graph, n);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    printMatrix(graph, n);

    return 0;
}
