#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 200;            //Square array size
const int ITERATIONS = 1;  //Number of repetitions

void static_arrays() {
    //declare static 2dimentional arrays 
    static int arr1[SIZE][SIZE];
    static int arr2[SIZE][SIZE];
    static int arr3[SIZE][SIZE];

    //populate the arrays
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            arr1[i][j] = rand() % 100;
            arr2[i][j] = rand() % 100;
        }
    
    clock_t start = clock();
    //Compute matrix multiplication 
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            arr3[i][j] = 0;
            for (int k = 0; k < SIZE; ++k)
                arr3[i][j] += arr1[i][k] * arr2[k][j];
        }
    clock_t end = clock();
    //outpute time 
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Static Arrays" << " | " << setw(10) << duration << " s\n";

     return;
}

void stack_arrays() {

    //declare stack dynamic 2dimentional arrays
    int arr1[SIZE][SIZE];
    int arr2[SIZE][SIZE];
    int arr3[SIZE][SIZE];

    //populate the arrays
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            arr1[i][j] = rand() % 100;
            arr2[i][j] = rand() % 100;
        }

    clock_t start = clock();
    //Compute matrix multiplication 
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            arr3[i][j] = 0;
            for (int k = 0; k < SIZE; ++k)
                arr3[i][j] += arr1[i][k] * arr2[k][j];
        }
    clock_t end = clock();
    //outpute time 
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Stack Arrays" << " | " << setw(10) << duration << " s\n";

    return;
}

void heap_arrays() {

    //initialize heap dynamic 2dimentional arrays
    int** arr1 = new int* [SIZE];
    int** arr2 = new int* [SIZE];
    int** arr3 = new int* [SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr1[i] = new int[SIZE];
        arr2[i] = new int[SIZE];
        arr3[i] = new int[SIZE];
    }

    //populate 
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            arr1[i][j] = rand() % 100;
            arr2[i][j] = rand() % 100;
        }

    clock_t start = clock();
    //Compute matrix multiplication
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            arr3[i][j] = 0;
            for (int k = 0; k < SIZE; ++k)
                arr3[i][j] += arr1[i][k] * arr2[k][j];
        }
    clock_t end = clock();
    //outpute time 
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << setw(15) << "Heap Arrays" << " | " << setw(10) << duration << " s\n";

    //dealocation 
    for (int i = 0; i < SIZE; ++i) {
        delete[] arr1[i];
        delete[] arr2[i];
        delete[] arr3[i];
    }

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); //for random number 

    //Static Array
    clock_t start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        static_arrays();   //Call static_arrays function 
    }
    clock_t end = clock();
    //outpute time 
    double duration = double(end - start) / CLOCKS_PER_SEC;
    //cout << setw(15) << "Static Arrays" << " | " << setw(10) << duration << " s\n";

    //Stack array 
    start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        stack_arrays();     //Call stack_arrays function 
    }
    end = clock();
    //output time 
    duration = double(end - start) / CLOCKS_PER_SEC;
    //cout << setw(15) << "Stack Arrays" << " | " << setw(10) << duration << " s\n";

    //Heap Array 
    start = clock();
    for (int it = 0; it < ITERATIONS; ++it) {
        heap_arrays();      //Call heap_arrays function 
    }
    end = clock();
    //Output time 
    duration = double(end - start) / CLOCKS_PER_SEC;
    //cout << setw(15) << "Heap Arrays" << " | " << setw(10) << duration << " s\n";

    return 0;
}
