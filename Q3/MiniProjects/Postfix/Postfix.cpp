#include <iostream>
#include "Stack.h"
using namespace std;

/**
 * Write a program called Postfix that first prompts the user for the name of a file and then displays
 * the answer to the mathematical expression that is written in postfix notation.
 * The txt file will contain a series of runs of the program, where each line consists of
 * mathematical expressions in postfix notation. The attached handout has some examples of postfix
 * notation (as well as what the results should be for those expressions).
 * 
 * Your program must output the trial expression followed by a colon and a single space and then the result of the call to eval,
 * one trial per line, in a new text file called "result.txt" that is created by your program.
 * 
 * Your program MUST use a stack to run each trial.
 * Standard rules apply for formatting and usability.
 *      4 points for documentation,
 *      4 points for user-friendliness,
 *      24 points for the required functionality (file read, stack, file write, correct result for each trial).
 * 
 * Postfix.cpp. We will limit our operations to addition, subtraction, multiplication, division,
 * exponents, modulus, and factorial. Every token in the postfix string will be separated by spaces, e.g.,
 * "3 4 5 * +"
 * Assume that the postfix string is well-formed with no mistakes. Your program must take a file of test
 * data. Output both the expression and its numerical evaluation into a file called “result.txt”.
 **/

int evaluate(string p) {
    Stack* tokens = new Stack("");

    //cout << "checking: " << p << endl;

    //convert string to tokens
    stringstream river;
    river << p; // hahahahah im so funny, get it get it get it, stream/river!?!?!?!?! hahaahahahhahahahahahahahaah
    string t;
    while (river >> t) {
        //cout << t << " ";

        if (t.length() == 1) { // it might be an operator
            switch (t[0]) {
                case '+': {
                    // a + b
                    int b = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a + b));
                    break;
                }
                case '-': {
                    // a - b
                    int b = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a - b));
                    break;
                }
                case '*': {
                    // a * b
                    int b = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a * b));
                    break;
                }
                case '/': {
                    // a / b
                    int b = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a / b));
                    break;
                }
                case '^': {
                    // base ** exponent
                    int exponent = stoi(tokens->pop()), base = stoi(tokens->pop());
                    tokens->push(to_string(pow(base, exponent)));
                    break;
                }
                case '%': {
                    // a % n
                    int n = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a % n));
                    break;
                }
                case '!': {
                    // !n
                    int n = stoi(tokens->pop()), r = 1;
                    for (int i=1; i<=n; i++) r *= i;
                    tokens->push(to_string(r));
                    break;
                }
                default: {
                    // if it's not any of the operators, it's a number
                    tokens->push(t);
                    break;
                }
            };
        } else { // it's definitely a number
            tokens->push(t);
        }
    }

    //cout << "ending with " << parens->peek() << endl;
    return stoi(tokens->peek());
}

int main() {
    string fileName = "a.txt";
    //cout << "Input the filename: ";
    //cin >> fileName;

    ifstream input(fileName);
    ofstream result("result.txt");
    
    string expression = "";

    int runs = 0;
    if (input.is_open() && result.is_open()) {
        while (getline(input, expression)) {
            result << (runs+1) << ": " << evaluate(expression) << endl;
            runs++;
        }
        input.close();
        result.close();
    } else {
        cout << "unable to open one of the files...?" << endl;
    }

    return 0;
}