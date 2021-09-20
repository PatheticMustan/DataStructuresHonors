/** Conversions.cpp, by Kevin Wang
 * 
 * Complete the following functions with the given declarations. All user input and output must occur in your
 * main function. You are permitted to create other functions if you feel they would help you complete the task.
 * Call your C++ file Conversions.
 * 
 * This is to be submitted to Classroom by the date on the assignment. You are only completing one file for this mini-project.
 * In your main function, you are going to be invoking the following functions. Obtain test values from the user
 * through the cin command. Your program must contain enough input to properly invoke the following
 * functions. The declarations are below:
 * 
 * string toBase(int decimal, int base)
 *      Converts the argument integer from base 10 to the argument base (base <= 9).
 * string toBase16(int decimal)
 *      Converts the argument integer from base 10 to base 16.
 * int toInteger(string number, int base)
 *      Converts the argument string from the argument base to base 10 (base <= 9).
 * int toInteger16(string number)
 *      Converts the argument string from base 16 to base 10.
 * 
 * This project will be graded on:
 * 1. Documentation (4 points): Your code must be fully commented and employ standard C++-style
 *      conventions.
 * 2. User-Friendliness (4 points): All interactions with the user must be clear and unambiguous.
 * 3. Functions (16 points): Each function has the proper declaration and works as expected.
 * TOTAL: 24 points
 **/

#include <bits/stdc++.h>
using namespace std;

// Converts the argument integer from base 10 to the argument base (base <= 9).
string toBase(int decimal, int base) {
    // just like base 10 has the ones place, tens place, hundreds place,
    // base n has the n**0's place, n**1's place, and n**2's place
    return "test";
}

// Converts the argument integer from base 10 to base 16.
string toBase16(int decimal) {
    return "poop";
}

// Converts the argument string from the argument base to base 10 (base <= 9).
int toInteger(string input, int base) {
    return 5;
}

// Converts the argument string from base 16 to base 10.
int toInteger16(string number) {
    return 2;
}

// get input stuff
int main() {
    cout << "Oh yeah yeah! Pick one option!"                << "\n\n"
         << "[1] Convert a decimal to a base 2-9"           << "\n"
         << "[2] Convert a decimal to base 16"              << "\n"
         << "[3] Convert a number from base 2-9 to decimal" << "\n"
         << "[4] Convert a base 16 string to decimal"       << "\n\n";

    int input;
    cin >> input;

    switch (input) {
        case 1: {
            // string (int, int)
            // Converts the argument integer from base 10 to the argument base (base <= 9).
            cout << "Enter a number in base 10, and the base you want to convert the number to:\n";

            int a_decimal, a_base;
            cin >> a_decimal >> a_base;

            cout << toBase(a_decimal, a_base);
            break;
        }
        
        case 2: {
            // string (int)
            // Converts the argument integer from base 10 to base 16.
            cout << "Enter a decimal to convert to hex:\n";

            int b_decimal;
            cin >> b_decimal;

            cout << toBase16(b_decimal);
            break;
        }

        case 3: {
            // int (string, int)
            // Converts the argument string from the argument base to base 10 (base <= 9).
            cout << "Enter a number, and the base (base <= 9) to convert to decimal:\n";

            string c_number;
            int c_base;
            cin >> c_number >> c_base;

            cout << toInteger(c_number, c_base);
            break;
        }

        case 4: {
            // int (string)
            // Converts the argument string from base 16 to base 10.
            cout << "Enter a hex string to be converted to decimal:\n";

            string d_number;
            cin >> d_number;

            cout << toInteger16(d_number);
            break;
        }

        default: {
            cout << "That's not a valid answer, try again, silly childe\n";
            break;
        }
    }

    return 0;
}