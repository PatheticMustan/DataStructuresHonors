#include <iostream>
#include "Stack.h"
using namespace std;

/**
 * Write a program called ParenthesesMatch that first prompts the user for the name of a file and then checks to see whether or
 * not the parentheses for each line match. The txt file will contain a series of runs of the program, where each line consists
 * of mathematical expressions involving the bracket symbols.
 * Your program must output the trial number followed by a colon and a single space and then the result of the call to
 * checkParen, one trial per line, in a new text file called "result.txt" that is created by your program.
 * Your program MUST use a stack to run each trial.
 * 
 * Standard rules apply for formatting and usability.
 *      4 points for documentation,
 *      4 points for user-friendliness,
 *      24 points for the required functionality (file read, stack, file write, correct result for each trial).
 * 
 * To add an element to your stack, create a push method. To remove, create a pop method.
 * In addition, you must have operator overloading for cout and the ability to check the topmost element
 * of the stack (a method typically called peek).
 **/

bool checkParen(string p) {
    string possibleParens = "([{<)]}>";

    for (int i=0; i<p.length(); i++) {
        if (possibleParens.find(p[i]) != -1) cout << p[i];
    }
    cout << endl;

    return true;
}

int main() {
    string fileName = "a.txt";
    //cout << "Input the filename: ";
    //cin >> fileName;

    ifstream input(fileName);
    ofstream result("result.txt");
    
    string parens = "";

    int runs = 0;
    if (input.is_open() && result.is_open()) {
        while (getline(input, parens)) {
            result << runs << ": " << checkParen(parens) << endl;
            runs++;
        }
        input.close();
        result.close();
    } else {
        cout << "unable to open one of the files...?" << endl;
    }

    return 0;
}