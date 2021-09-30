/** PointerFunctions.cpp, by Kevin Wang
 * In your main function, display a menu to ask the user for their desired task. Their options are listed below.
 * Once the user chooses a task, ask them for the input required for the function (and only for that function).
 * When the process is complete, ask the user if they want to do it again.
 * 
 * void swap(int* a, int* b)
 *      This function swaps two integers using pointers.
 * 
 * void letterCount(string s, int* numVowels, int* numConsonants)
 *      This function counts the number of both vowels and consonants in a given string. The input string will
 *      contain no spaces and only capital letters. You MUST use a character pointer in this function instead of
 *      using string or array notation.
 * 
 * void arrayInfo(int* arrPtr, int length)
 *      This function accepts a pointer that refers to the first element of an array of length elements. This
 *      function will display each element and its memory location. The information for each element must be
 *      on a new line, with the element and memory location separated by a single space. The output for this
 *      function is in the function itself.
 * 
 * This project will be graded on:
 * 1. Documentation (4 points): Your code must be fully commented and employ standard C++-style
 *      conventions.
 * 2. User-Friendliness (4 points): All interactions with the user must be clear and unambiguous.
 * 3. Functions (12 points): Each function has the proper declaration and works as expected.
 * 
 * TOTAL: 20 points
 **/

#include <bits/stdc++.h>
using namespace std;

// This function swaps two integers using pointers.
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// This function counts the number of both vowels and consonants in a given string.
void letterCount(string s, int* numVowels, int* numConsonants) {}

int main() {
    cout << "Oh yeah yeah! Pick one option!"                                                       << "\n\n"
         << "[1] Swap two ints with pointy pointers!"                                              << "\n"
         << "[2] This function counts the number of both vowels and consonants in a given string." << "\n"
         << "[3] This function will display each element and its memory location."                 << "\n"
         << "[4] Exit"                                                                             << "\n\n";

    int input;
    cin >> input;

    switch (input) {
        case 1: {
            // get input
            cout << "swapping two numbers with pointers! Input two numbers: " << "\n";
            int a, b;
            cin >> a >> b;

            // log 
            cout << "\nA: " << a << ", B: " << b
                 << "\nSwap!";

            swap(&a, &b);

            cout << "\nA: " << a << ", B: " << b << "\n";
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            // become one with the astral plane
            return 69420;
        }
    }

    // stuck in an infinite loop
    main();

    return 0;
}