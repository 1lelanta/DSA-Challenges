#include <iostream>
using namespace std;

const int MAX = 10;

int edges[MAX][MAX];
bool visited[MAX];

// ---------- BFS ----------
void BFS_Array(int start, int n) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[start] = true;
    queue[rear++] = start;

    cout << "BFS (Array): ";

    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (edges[v][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

// ---------- DFS ----------
void DFS_Array(int v, int n) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (edges[v][i] != 0 && !visited[i]) {
            DFS_Array(i, n);
        }
    }
}
