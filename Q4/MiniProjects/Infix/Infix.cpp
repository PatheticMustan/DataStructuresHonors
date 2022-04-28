#include <iostream>
#include "Stack.h"
using namespace std;

/**
 * Write a program called Infix that first prompts the user for the name of a file and then displays
 * the answer to the mathematical expression that is written in infix notation.
 * The txt file will contain a series of runs of the program, where each line consists of mathematical
 * expressions in infix notation.
 * The attached handout has some examples of infix notation (as well as what the results should be for those expressions).
 * 
 * Your program must output the trial infix expression followed by the trial postfix expression followed by the result,
 * one trial per line, in a new text file called "result.txt" that is created by your program.
 * 
 * Your program MUST use a stack to run each trial.
 * Standard rules apply for formatting and usability.
 *      4 points for documentation,
 *      4 points for user-friendliness,
 *      24 points for the required functionality (file read, stack, file write, correct result for each trial).
 **/

// returns true if c1 has lower or equal precedence than c2
bool isLower(char c1, char c2) {
    // we're assuming both c1 and c2 are valid operators
    // [P][E][MD][AS]
    map<char, int> values = {
        { '(', 3 }, { ')', 3 }, // P is the most important, 3
        { '*', 2 }, { '/', 2 }, // MD is second, 2
        { '+', 1 }, { '-', 1 }, // AS is least important, 1
    };
    return values[c1] <= values[c2];
}
bool isNumber(string token) {
    // handles negative numbers too..?
    // all numbers must end with a digit
    return isdigit(token[token.length()-1]);
}
string infixToPostfix(string infix) {
    Stack* tokens = new Stack("");
    string result = "";

    //convert string to tokens
    stringstream river; river << infix;
    string t;
    while (river >> t) {
        if (isNumber(t)) {
            result += t + " ";
        } else if (t == "(") {
            tokens->push("(");
        } else if (t == ")") {
            // append until you hit the left paren, pop it
            while (tokens->peek() != "(") result += tokens->pop() + " ";
            tokens->pop();
        } else {
            // if it's not a number, and not a paren, it's an operator
            // t[0] just converts it to a char
            // atrocious indentation
            while (
                tokens->peek() != "" &&
                tokens->peek() != "(" &&
                isLower(t[0], tokens->peek()[0])
            ) {
                result += tokens->pop() + " ";
            }
            tokens->push(t);
        }
    }
    // empty 'em pockets, boi
    while (tokens->peek() != "") result += tokens->pop() + " ";

    return result;
}

// copy pasted from my postfix project, slightly modified and cleaned
int evaluate(string p) {
    Stack* tokens = new Stack("");

    //convert string to tokens
    stringstream river; river << p;
    string t;
    while (river >> t) {
        if (t.length() == 1) { // it might be an operator
            switch (t[0]) {
                case '+': {
                    int b = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a + b));
                    break;
                }
                case '-': {
                    int b = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a - b));
                    break;
                }
                case '*': {
                    int b = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a * b));
                    break;
                }
                case '/': {
                    int b = stoi(tokens->pop()), a = stoi(tokens->pop());
                    tokens->push(to_string(a / b));
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
    return stoi(tokens->peek());
}

int main() {
    string fileName = "a.txt";
    cout << "Input the filename: ";
    cin >> fileName;

    ifstream input(fileName);
    ofstream result("result.txt");
    
    string expression = "";
    if (input.is_open() && result.is_open()) {
        result << "Infix   -->   Postfix   -->   Evaluate" << endl;
        while (getline(input, expression)) {
            // Your program must output the trial infix expression followed by the trial postfix expression followed by the result
            // expression, postfix, result
            result << expression << "\t\t" << infixToPostfix(expression) << "\t\t" << evaluate(infixToPostfix(expression)) << endl;
        }
        input.close();
        result.close();
    } else {
        cout << "unable to open one of the files...?" << endl;
    }

    return 0;
}