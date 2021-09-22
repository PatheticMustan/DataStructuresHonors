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

// utility function, convert a number to its hex equiv
// 0123456789ABCDEF
char c(int n) {
    return "0123456789ABCDEF"[n];
}

// Converts the argument integer from base 10 to the argument base (base <= 9).
string toBase(int decimal, int base) {
    // edge case lmao
    if (decimal == 0) return "0";

    // speed writing this at 1 am, sorry for bad quality
    int place = 1;

    // get highest place, it's base**n
    while (!(place > decimal)) place *= base;
    place /= base;

    // start from the highest place, every time we go down, we divide base**n by base
    string result = "";
    while (place != 1) {
        result += to_string(decimal / place);
        decimal %= place;
        place /= base;
    }
    result += to_string(decimal);


    return result;
}

// Converts the argument integer from base 10 to base 16.
string toBase16(int decimal) {
    int place = 1;

    // I just copy pasted this from method #1
    if (decimal == 0) return "0";

    while (!(place > decimal)) place *= 16;
    place /= 16;

    // start from the highest place, every time we go down, we divide base**n by base
    string result = "";
    while (place != 1) {
        result += c(decimal / place);
        decimal %= place;
        place /= 16;
    }
    result += c(decimal);

    return result;
}

// Converts the argument string from the argument base to base 10 (base <= 9).
int toInteger(string input, int base) {
    // tbh, I worked on method #4 first, this is just method #4 but without the hex to int conversion thing
    int result = 0;

    /** 420 base 5 --> base 10
     * 4   2   0      loop thru each char
     * 25  5   1      multiply by place, usually just 16**(n-1)
     * ---------
     * 100 + 10 + 0
     * 110
     **/
    for (int i=0; i<input.length(); i++) {
        int place = pow(base, (input.length()-i-1));

        //cout << place << " " << input[i] << " " << place * input[i] << "\n";

        // cpp just isn't as comfy as JS
        // https://stackoverflow.com/a/30727561
        // need to convert `input[i]` to an int, in cpp I take the ASCII and do char-48
        // in Javascript, you can just do +(char)
        // woe is me, I can't use my cheap tricks anymore
        result += place * ((int)input[i]-'0');
    }


    return result;
}

// Converts the argument string from base 16 to base 10.
// i'm going to the dark depths of hell for (string number)
int toInteger16(string number) {
    int result = 0;
    string hexString = "0123456789ABCDEF";

    /** 0xFFF
     * F        F    F      loop thru each char
     * 15      15   15      convert from hex to int
     * 256     16    1      multiply by place, usually just 16**(n-1)
     * ---------------
     * 3840 + 240 + 15
     * 4095
     **/
    for (int i=0; i<number.length(); i++) {
        int place = pow(16, (number.length()-i-1));
        int hexCharToInt = hexString.find(toupper(number[i]));

        result += place * hexCharToInt;
    }


    return result;
}

// get input stuff
int main() {
    cout << "Oh yeah yeah! Pick one option!"                << "\n\n"
         << "[1] Convert a decimal to a base 2-9"           << "\n"
         << "[2] Convert a decimal to base 16"              << "\n"
         << "[3] Convert a number from base 2-9 to decimal" << "\n"
         << "[4] Convert a base 16 string to decimal"       << "\n"
         << "[5] Exit" << "\n\n";

    int input;
    cin >> input;

    switch (input) {
        case 1: {
            // string (int, int)
            // Converts the argument integer from base 10 to the argument base (base <= 9).
            cout << "Enter a number in base 10, and the base you want to convert the number to:\n";

            int a_decimal, a_base;
            cin >> a_decimal >> a_base;

            cout << "\nResult: " << toBase(a_decimal, a_base);
            break;
        }
        
        case 2: {
            // string (int)
            // Converts the argument integer from base 10 to base 16.
            cout << "Enter a decimal to convert to hex:\n";

            int b_decimal;
            cin >> b_decimal;

            cout << "\nResult: " << toBase16(b_decimal);
            break;
        }

        case 3: {
            // int (string, int)
            // Converts the argument string from the argument base to base 10 (base <= 9).
            cout << "Enter a number, and the base (base <= 9) to convert to decimal:\n";

            string c_number;
            int c_base;
            cin >> c_number >> c_base;

            cout << "\nResult: " << toInteger(c_number, c_base);
            break;
        }

        case 4: {
            // int (string)
            // Converts the argument string from base 16 to base 10.
            cout << "Enter a hex string to be converted to decimal:\n";

            string d_number;
            cin >> d_number;

            cout << "\nResult: " << toInteger16(d_number);
            break;
        }

        case 5: {
            // exit
            return 0;
        }

        default: {
            cout << "That's not a valid answer, try again, silly childe\n";
            break;
        }
    }

    cout << "\n\n";

    // go again
    main();

    return 0;
}