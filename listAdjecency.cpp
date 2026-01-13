struct EdgeNode {
    int adj;
    EdgeNode* next;
};

struct Vertex {
    EdgeNode* head;
};

Vertex graph[MAX];

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
