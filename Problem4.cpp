#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 100;            //Square array size
const int ITERATIONS = 10000;  //Number of repetitions


void accessWithSubscripts() {
    int arr[SIZE][SIZE]; //stack-allocated 2D array

    //Fill the array
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            arr[i][j] = i + j;

    //Read access using subscript
    int sum = 0;
    for (int repeat = 0; repeat < 10; ++repeat)
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                sum += arr[i][j];
}

void accessWithPointerArithmetic() {
    int arr[SIZE][SIZE]; //stack-allocated

    //Fill the array
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            arr[i][j] = i + j;

    //Pointer to the beginning
    int* ptr = &arr[0][0];

    //Read access using pointer arithmetic
    int sum = 0;
    for (int repeat = 0; repeat < 10; ++repeat)
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                sum += *(ptr + i * SIZE + j); //storage mapping
}


void accessWithSubscriptsHeap() {
    //Allocate memory on the heap
    int** arr = new int* [SIZE];
    for (int i = 0; i < SIZE; ++i)
        arr[i] = new int[SIZE];

    //Fill the array
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            arr[i][j] = i + j;

    //Read access
    int sum = 0;
    for (int repeat = 0; repeat < 10; ++repeat)
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                sum += arr[i][j];

    //Deallocate
    for (int i = 0; i < SIZE; ++i)
        delete[] arr[i];
    delete[] arr;
}

void accessWithPointerArithmeticHeap() {
    //Allocate flat 1D array on the heap
    int* arr = new int[SIZE * SIZE];

    //Fill the array
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            arr[i * SIZE + j] = i + j;

    //Read access using pointer arithmetic
    int sum = 0;
    for (int repeat = 0; repeat < 10; ++repeat)
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                sum += *(arr + i * SIZE + j);

    //Deallocate
    delete[] arr;
}


int main() {
    srand(static_cast<unsigned>(time(nullptr))); //for random number 

    //Stored on the stack 
    clock_t start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        accessWithSubscripts();   //Call static_arrays function 
    }
    clock_t end = clock();
    //outpute time 
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Subscript access: " << " | " << setw(10) << duration << " s\n";

    //Stack array 
    start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        accessWithPointerArithmetic();     //Call stack_arrays function 
    }
    end = clock();
    //output time 
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Pointer Arithmetic access" << " | " << setw(10) << duration << " s\n";


    // Stored on the heap 
    start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        accessWithSubscriptsHeap();   //Call static_arrays function 
    }
    end = clock();
    //outpute time 
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Subscript access (heap): " << " | " << setw(10) << duration << " s\n";

    //Stack array 
    start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        accessWithPointerArithmeticHeap();     //Call stack_arrays function 
    }
    end = clock();
    //output time 
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Pointer Arithmetic access (heap):" << " | " << setw(10) << duration << " s\n";

    return 0;
}