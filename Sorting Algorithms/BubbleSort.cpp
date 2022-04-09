/*// Optimized bubble sort in C++

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

void bubbleSort(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        // Run loops two times: one for walking throught the array
        // and the other for comparison
        int swapped = 0;
        for (int i = 0; i < size - step - 1; ++i) {
            // To sort in descending order, change > to < in this line.
            if (array[i] > array[i + 1]) {

                // Swap if greater is at the rear position
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        // If there is not swapping in the last swap, then the array is already sorted.
        if (swapped == 0)
            break;
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << "\n";
}

// Driver code
int main() {
    fstream myfile;
    int* arr = nullptr;
    int n = 0;
    myfile.open("data5000.txt", ios::in);

    if (myfile.is_open()) {

        myfile >> n;
        arr = new int[n];
        cout << "n =" << n << endl;
        for (int i = 0; i < n; i++) {
            myfile >> arr[i];
        }
        myfile.close();
    }
    clock_t tStart = clock();
    bubbleSort(arr, n);
    cout << "Time Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
    
    cout << "Sorted Array in Ascending Order:\n";
    printArray(arr, n);
    return 0;
}*/