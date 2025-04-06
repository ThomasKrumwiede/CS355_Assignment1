#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 100;           // Square array size
const int ITERATIONS = 100000; // Number of repetitions

void static_arrays() {
   
     static int arr1[SIZE][SIZE];
     static int arr2[SIZE][SIZE];
}

void stack_arrays() {

    int arr1[SIZE][SIZE];
    int arr2[SIZE][SIZE];
}

void heap_arrays() {

    int** arr1 = new int* [SIZE];
    int** arr2 = new int* [SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr1[i] = new int[SIZE];
        arr2[i] = new int[SIZE];
    }
    for (int i = 0; i < SIZE; ++i) {
        delete[] arr1[i];
        delete[] arr2[i];
    }

    delete[] arr1;
    delete[] arr2;
}

int main() {
    
    //Static Array
    clock_t start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        static_arrays();
    }
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC;
    //double averageDuration = duration / ITERATIONS;
    cout << setw(15) << "Static Arrays" << " | " << setw(10) << duration << " s\n";

    //Stack array 
    start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        stack_arrays();
    }
    end = clock();

    duration = double(end - start) / CLOCKS_PER_SEC;
    //averageDuration = duration / ITERATIONS;
    cout << setw(15) << "Stack Arrays" << " | " << setw(10) << duration << " s\n";

    //Heap Array 
    start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        heap_arrays();
    }
   
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    //duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Heap Arrays" << " | " << setw(10) << duration << " s\n";

    return 0;
}
