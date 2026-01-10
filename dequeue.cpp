#include <iostream>
#include <string>

using namespace std;


void enqueue(string q[], int &f, int &r, int n, string y) {
    if (r == n - 1) {
        cout << "Overflow" << endl;
        return;
    }

    if (f == -1) {
        f = 0;
    }

    q[++r] = y;
}


void dequeue(string q[], int &f, int &r) {
    if (f == -1) {
        cout << "Underflow" << endl;
        return;
    }

    string y = q[f];

    if (f == r) {
        f = r = -1;
    } else {
        f = f + 1;
    }

    cout << "Deleted element: " << y << endl;
}

int main() {
    string q[5];        
    int f = -1, r = -1; 
    int n = 5;

   
    enqueue(q, f, r, n, "A");
    enqueue(q, f, r, n, "B");
    enqueue(q, f, r, n, "C");

    dequeue(q, f, r);   
    dequeue(q, f, r);   

    enqueue(q, f, r, n, "D");

    dequeue(q, f, r);   
    dequeue(q, f, r);   
    dequeue(q, f, r);   

    return 0;
}
