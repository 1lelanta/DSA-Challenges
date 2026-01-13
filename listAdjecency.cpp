#include <iostream>
using namespace std;

#define MAX 10

bool visited[MAX];

// ---------- Structures ----------
struct EdgeNode {
    int adj;
    EdgeNode* next;
};

struct Vertex {
    EdgeNode* head;
};

Vertex graph[MAX];

// ---------- Add Edge ----------
void addEdge(int u, int v) {
    EdgeNode* newNode = new EdgeNode;
    newNode->adj = v;
    newNode->next = graph[u].head;
    graph[u].head = newNode;
}

// ---------- BFS ----------
void BFS_List(int start, int n) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[start] = true;
    queue[rear++] = start;

    cout << "BFS (List): ";

    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        EdgeNode* temp = graph[v].head;
        while (temp != NULL) {
            int adj = temp->adj;
            if (!visited[adj]) {
                visited[adj] = true;
                queue[rear++] = adj;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

// ---------- DFS ----------
void DFS_List(int v) {
    visited[v] = true;
    cout << v << " ";

    EdgeNode* temp = graph[v].head;
    while (temp != NULL) {
        if (!visited[temp->adj]) {
            DFS_List(temp->adj);
        }
        temp = temp->next;
    }
}

// ---------- MAIN ----------
int main() {
    int n = 5; // number of vertices: 0,1,2,3,4

    // Initialize graph
    for (int i = 0; i < n; i++)
        graph[i].head = NULL;

    // Build example graph:
    // 0 → 1, 0 → 3
    // 1 → 2
    // 2 → 4
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 4);

    // Run BFS
    BFS_List(0, n);

    // Reset visited for DFS
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Run DFS
    cout << "DFS (List): ";
    DFS_List(0);
    cout << endl;

    return 0;
}
