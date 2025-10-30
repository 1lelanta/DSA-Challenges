#include <iostream>
using namespace std;

// Function declaration (prototype)
int LinearSearch(int list[], int n, int key);

int main() {
    int arr[] = {5, 8, 3, 9, 2};
    int key = 9;
    int n = 5;

    int result = LinearSearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

// Function definition
int LinearSearch(int list[], int n, int key)
{
    int index = 0;
    int found = 0;
    do {
        if (key == list[index])
            found = 1;
        else
            index++;
    } while (found == 0 && index < n);

    if (found == 0)
        index = -1;

    return index;
}
