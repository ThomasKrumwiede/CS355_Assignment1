#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 100;           // Square array size
const int ITERATIONS = 22710; // Number of repetitions

void static_arrays() {
   
     static int arr1[SIZE][SIZE];
     static int arr2[SIZE][SIZE];

     return;
}

void stack_arrays() {

    int arr1[SIZE][SIZE];
    int arr2[SIZE][SIZE];

    return;
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

    return;
}

void heap_arrays_noDealocation() {
    int iterations = 0; //Track Number of Iterations 

    try {
        while (true) {
            int** arr1 = new int* [SIZE];  
            int** arr2 = new int* [SIZE];

            for (int i = 0; i < SIZE; ++i) {
                arr1[i] = new int[SIZE];  
                arr2[i] = new int[SIZE];
            }

            iterations++;  //Increment successful iterations
        }
    }
    catch (const std::bad_alloc& e) {
        //When memory allocation fails, print the number of successful iterations
        cout << "Ran out of memory after " << iterations << " iterations\n";
    }

    return;
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

    //Heap Array No Dealocation 
    cout << "\nStarting heap_arrays_noDealocation function:\n";
    heap_arrays_noDealocation();

    return 0;
}
