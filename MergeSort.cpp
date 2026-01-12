#include <iostream>
using namespace std;

// Function to merge two sorted halves of the array
void merge(int Data[], int left, int mid, int right) {
    int n1 = mid - left + 1; // size of first half
    int n2 = right - mid;    // size of second half

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = Data[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = Data[mid + 1 + j];

    // Merge the temp arrays back into Data[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            Data[k] = L[i];
            i++;
        } else {
            Data[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements (if any)
    while (i < n1) {
        Data[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        Data[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int Data[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(Data, left, mid);

        mergeSort(Data, mid + 1, right);

        merge(Data, left, mid, right);
    }
}

int main() {
    int Data[] = {5, 8, 2, 4, 1, 3, 9, 7, 6, 0};
    int n = 10;

    cout << "Original array:\n";
    for (int i = 0; i < n; i++)
        cout << Data[i] << " ";
    
    mergeSort(Data, 0, n - 1);

    cout << "\n\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << Data[i] << " ";

    return 0;
}
