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
    Stack* parens = new Stack("");

    //cout << "checking: " << p << endl;

    for (int i=0; i<p.length(); i++) {
        int parenIndex = possibleParens.find(p[i]);
        if (parenIndex != string::npos) {
            //cout << parens << " ";

            // if it's a opening bracket
            // possibleParens/2 = 8/2 = 4
            if (parenIndex < 4) {
                //cout << "adding " << to_string(parenIndex) << endl;
                parens->push(to_string(parenIndex));
            } else {
                // it's a closing bracket
                string popThing = parens->pop();
                //cout << "removing " << (parenIndex%4) << ", getting " << popThing << endl;
                if (popThing != to_string(parenIndex%4)) {
                    //cout << "ouch! false" << endl;
                    return false;
                }
            }
            
        }
    }

    //cout << "ending with " << parens->peek() << endl;
    return parens->peek() == "";
}

int main() {
    string fileName = "";
    cout << "Input the filename: ";
    cin >> fileName;

    ifstream input(fileName);
    ofstream result("result.txt");
    
    string parens = "";

    int runs = 0;
    if (input.is_open() && result.is_open()) {
        while (getline(input, parens)) {
            result << (runs+1) << ": " << (checkParen(parens)? "true" : "false") << endl;
            runs++;
        }
        input.close();
        result.close();
    } else {
        cout << "unable to open one of the files...?" << endl;
    }

    return 0;
}