#include <iostream>
using namespace std;

// Function to "heapify" a subtree rooted at index i
// n is size of heap
void heapify(int Data[], int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // left child index
    int right = 2 * i + 2;   // right child index

    // If left child exists and is greater than root
    if (left < n && Data[left] > Data[largest])
        largest = left;

    // If right child exists and is greater than current largest
    if (right < n && Data[right] > Data[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(Data[i], Data[largest]);

        // Recursively heapify the affected subtree
        heapify(Data, n, largest);
    }
}

// Heap Sort function
void heapSort(int Data[], int n) {
    // Step 1: Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(Data, n, i);

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(Data[0], Data[i]);

        // call heapify on the reduced heap
        heapify(Data, i, 0);
    }
}

int main() {
    int Data[] = {5, 8, 2, 4, 1, 3, 9, 7, 6, 0};
    int n = 10;

    cout << "Original array:\n";
    for (int i = 0; i < n; i++)
        cout << Data[i] << " ";
    
    heapSort(Data, n);

    cout << "\n\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << Data[i] << " ";

    return 0;
}
