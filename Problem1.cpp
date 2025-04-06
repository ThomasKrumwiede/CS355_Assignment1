#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 100;           // Square array size
const int ITERATIONS = 100000; // Number of repetitions

void static_arrays() {
   
    for (int it = 0; it < ITERATIONS; ++it) {
        static int arr1[SIZE][SIZE];
        static int arr2[SIZE][SIZE];
    }
}

void stack_arrays() {

    for (int it = 0; it < ITERATIONS; ++it) {
        int arr1[SIZE][SIZE];
        int arr2[SIZE][SIZE];
    }
}

void heap_arrays() {

    for (int it = 0; it < ITERATIONS; ++it) {
        int** arr1 = new int* [SIZE];
        int** arr2 = new int* [SIZE];

        delete[] arr1;
        delete[] arr2;
    }
}

int main() {
    cout << setw(15) << "Method" << " | " << setw(10) << "Time (s)\n";
    cout << "----------------------------\n";

    //Static Array
    clock_t start = clock();
    static_arrays();
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Static Arrays" << " | " << setw(10) << duration << " s\n";

    //Stack array 
    start = clock();
    stack_arrays();
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Stack Arrays" << " | " << setw(10) << duration << " s\n";

    //Heap Array 
    start = clock();
    heap_arrays();
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Heap Arrays" << " | " << setw(10) << duration << " s\n";

    return 0;
}
