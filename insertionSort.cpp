#include <iostream>
using namespace std;

int main() {
    int list[] = {8, 3, 5, 2};
    int n = sizeof(list) / sizeof(list[0]);

    insertion_sort(list, n);

    for(int i = 0; i < n; i++)
        cout << list[i] << " ";

    return 0;
}

void insertion_sort(int list[], int n)
{ 
    int temp; 
    for(int i = 1; i < n; i++) { 
        temp = list[i]; 
        for(int j = i; j > 0 && temp < list[j-1]; j--) { 
            list[j] = list[j-1]; 
            list[j-1] = temp; 
        }
    }
}
