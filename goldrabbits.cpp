// Name: Daniel Winn
// Class: CECS 325-02
// Project Name: Prog 5 - Gold Rabbits
// Due Date 11/18/25
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int goldRabbits(int n);

int main(int argc, char* argv[]) {
    // Loop through CLI
    // Starts at i=1
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        int n;

        try {
            // Convert argument to integer
            size_t pos;
            n = stoi(arg, &pos);

            // Check if string is a number
            if (pos < arg.length()) {
                throw invalid_argument("Not an integer: " + arg);
            }

            if (n == -1) {
                // Logic for map printing
                cout << "fibo(-1):" << endl;
                cout << "Fibo Map contents:" << endl;
                cout << "Print Map Here (to-do)" << endl;
                cout << "end of Fibo map" << endl;
            }

            else {
                // Calculate fibo
                cout << "fibo(" << n << "): \t" << goldRabbits(n) << endl;
            }
        }

        catch (...) {
            // Catches if stoi fails and/or an error was thrown (invalid string or input)
            cout << arg << " is not an integer" << endl;
        }
    }
    return 0;
}

// Placeholder function
int goldRabbits(int n) {
    return 1;
}