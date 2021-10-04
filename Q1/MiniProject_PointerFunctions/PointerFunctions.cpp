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
void letterCount(string s, int* numVowels, int* numConsonants) {
    string vowels = "AEIOU";
    string consonants = "BCDFGHJKLMNPQRSTVWXYZ";

    for (int i=0; i<s.length(); i++) {
        // edge case: lowercase letters, numbers
        // spec says all uppercase letters and no spaces, but it doesn't say anything about symbols/numbers

        // debug thing
        //cout << "letter: " << s[i] << " cons: " << *numConsonants << " vowel: " << *numVowels << "\n";

        // use string#find to check if it's included in the list
        // if it doesn't find it, it returns -1! If it's not -1, it's in the string
        if (vowels.find(s[i]) != -1) {
            *numVowels = *numVowels + 1;
        }
        if (consonants.find(s[i]) != -1) {
            *numConsonants = *numConsonants + 1;
        }
    }

    cout << "\n\n";
}

// This function will display each element and its memory location. The information for each element must be
// on a new line, with the element and memory location separated by a single space.
void arrayInfo(int* arrPtr, int length) {
    for (int i=0; i<length; i++) {
        cout << (arrPtr+i) << " " << *(arrPtr+i) << "\n";
    }
}

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
            // I spent 30 minutes trying to figure out why these ints started out as seemingly random numbers
            // it was because I didn't initialize it to 0, bruh bruh bruh
            int vowels = 0,
                consonants = 0;
            
            //cout << vowels << consonants;
            string input;

            cout << "Put in an all caps string: " << "\n";
            //getline(cin, input);
            // I don't know why getline is not waiting for input, but I'm just gonna blame it on language bad
            // there's probably a very obvious reason for why it's not working, but my monkey brain can't find it
            cin >> input;

            letterCount(input, &vowels, &consonants);

            cout << "Vowels: " << vowels << " Consonants: " << consonants << "\n";

            break;
        }
        case 3: {
            int size;

            cout << "Type in the size of the array: " << "\n";
            cin >> size;
            if (size <= 0) {
                cout << "AHHHHHHH INVALID SIZE AHHHHHH" << "\n\n";
                break;
            }

            int arr[size];
            
            cout << "Now type in " << size << " numbers: " << "\n";
            for (int i=0; i<size; i++) {
                cin >> arr[i];
            }

            cout << "\n";
            arrayInfo(arr, size);
            cout << "\n";

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