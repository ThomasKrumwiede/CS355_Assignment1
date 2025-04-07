/*
Thomas Krumiwede
CS355
4/8/25
*/
using namespace System;

void print_order(int a, int b) {
    Console::WriteLine("argument1: {0}, argument2: {1}", a, b);
}

int main() {
    int x = 0, y = 0;
    print_order(x++, y++);

    Console::WriteLine("Press Enter to exit...");
    Console::ReadLine(); 

    return 0;
}