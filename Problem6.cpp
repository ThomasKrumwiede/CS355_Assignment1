/*
Thomas Krumiwede 
CS355
4/8/25
*/

#include <iostream>
using namespace std;

void print_order(int x, int y) {
    cout << "argument1: " << x << ", argument2: " << y << endl;
}

int main() {
    int value = 0;
   
    print_order(value++, value++);

    return 0;
}
