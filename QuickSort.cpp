#include <iostream>
using namespace std;


int partition(int Data[], int low, int high) {
    int left = low;
    int right = high;
    int pivotPos = left;

    while (left < right) {
        if (pivotPos == left) {
            if (Data[left] > Data[right]) {
                swap(Data[left], Data[right]);
                pivotPos = right;
                left++;
            } else {
                right--;
            }
        } else {
            if (Data[left] > Data[right]) {
                swap(Data[left], Data[right]);
                pivotPos = left;
                right--;
            } else {
                left++;
            }
        }
    }
    return pivotPos;  
}


void quickSort(int Data[], int low, int high) {
    if (low < high) {
        int p = partition(Data, low, high);  
        quickSort(Data, low, p - 1);          
        quickSort(Data, p + 1, high);         
    }
}

int main() {
    int Data[] = {10,4,5,67,4,6,7,4,3,5};
    int n = 10;

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++)
        cout << Data[i] << " ";

    quickSort(Data, 0, n - 1);

    cout << "\n\nAfter sorting:\n";
    for (int i = 0; i < n; i++)
        cout << Data[i] << " ";

    return 0;
}
