#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const int SIZE = 50;  // Square array size (adjustable)
const int ITERATIONS = 100000;  // Number of repetitions

void static_arrays() {
    static int arr1[SIZE][SIZE];
    static int arr2[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            arr1[i][j] = arr2[i][j] = i + j;
}

void stack_arrays() {
    int arr1[SIZE][SIZE];
    int arr2[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            arr1[i][j] = arr2[i][j] = i + j;
}

void heap_arrays() {
    int** arr1 = new int*[SIZE];
    int** arr2 = new int*[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr1[i] = new int[SIZE];
        arr2[i] = new int[SIZE];
    }

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            arr1[i][j] = arr2[i][j] = i + j;

    for (int i = 0; i < SIZE; ++i) {
        delete[] arr1[i];
        delete[] arr2[i];
    }

    delete[] arr1;
    delete[] arr2;
}

void measure_time(void (*func)(), const string& label) {
    clock_t start = clock();  // Start time

    for (int i = 0; i < ITERATIONS; ++i) {
        func();
    }

    clock_t end = clock();  // End time
    double duration = double(end - start) / CLOCKS_PER_SEC;  // Convert to seconds
    
    cout << std::setw(15) << label << " | " << setw(10) << duration << " s\n";
}

int main() {
    cout << setw(15) << "Method" << " | " << setw(10) << "Time (s)\n";
    cout << "----------------------------\n";

    measure_time(static_arrays, "Static Arrays");
    measure_time(stack_arrays, "Stack Arrays");
    measure_time(heap_arrays, "Heap Arrays");

    return 0;
}
