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

// Macro (defines integer type)
#define INTEGER int
// #define INTEGER short
// #define INTEGER long long

INTEGER goldRabbits(INTEGER n);

int main(int argc, char* argv[]) {
    // Loop through CLI
    // Starts at i=1
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        INTEGER n;

        try {
            // Convert argument to integer
            size_t pos;
            long long inputVal = stoll(arg, &pos);
            n = (INTEGER)inputVal;

            // Check if string is a number
            if (pos < arg.length()) {
                throw invalid_argument("Not an integer: " + arg);
            }

            if (n == -1) {
                // Execute fuction goldRabbits to print map
                cout << "fibo(-1):" << endl;
                goldRabbits(-1);
            }

            else {
                // Calculate fibo, store as static map
                cout << "fibo(" << n << "): \t";
                
                // try-catch is needed for math logic errors
                try {
                    INTEGER result = goldRabbits(n);
                    cout << result << endl;
                }
                catch (string error) {
                    // Catch overflow
                    cout << error << endl;
                }
            }
        }

        catch (...) {
            // Catches if stoi fails and/or an error was thrown (invalid string or input)
            cout << arg << " is not an integer" << endl;
        }
    }
    return 0;
}

INTEGER goldRabbits(INTEGER n) {
    static map<INTEGER, INTEGER> fiboMap;

    // Print the map
    if (n == -1) {
        cout << "Fibo Map contents:" << endl;
        // Iterate through map, print key:value pairs
        for (auto const& [key, val] : fiboMap) {
            cout << key << ":" << val << endl;
        }
        cout << "end of Fibo map" << endl;
        return 0;
    }

    // Add base cases to the map
    if (n == 0 || n == 1) {
        fiboMap[n] =1;
        return 1;
    }

    // Check if value 'n' was already calculated
    if (fiboMap.count(n)) {
        // Return 1 if found, 0 if not
        return fiboMap[n];
    }

    // Store fiboMap before returning
    INTEGER result = goldRabbits(n - 1) + goldRabbits(n - 2);

    // Check if result is negative (for overflow)
    if (result < 0) {
        throw string("overflow error at fib(" + to_string(n) + "):" + to_string(result));
    }

    fiboMap[n] = result;
    return result;
}


