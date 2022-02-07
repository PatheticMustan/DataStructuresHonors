/** BigMath.cpp, by Kevin Wang
 * Complete the following program with the given declarations. All user input and output must occur in your
 * main function.
 * You are permitted to create other functions if you feel they would help you complete the task.
 * 
 * Call your C++ file BigMath. This is to be submitted to Classroom by the date on the assignment. You are only
 * completing one C++ file for this mini-project.
 * In your main function, display a menu to ask the user for their desired task. They are to first choose their
 * operation and then enter the values required. Their options are listed below. When the process is complete, ask
 * the user if they want to do it again.
 * 
 * Create a class called BigMath inside of your program. Your class must contain private attributes for the digit
 * of a given BigMath object, as well as a pointer to the next object in the list. Your constructor must take an
 * integer representing a digit and a reference to the next node in the linked list. Assume that the numbers the user
 * enters are positive. Your class must also contain the following operators, as well as any relevant accessor and
 * mutator methods.
 * 
 * Adding two BigMath objects together returns a BigMath representing the sum.
 * Subtracting two BigMath objects returns a BigMath representing the difference. The result can be negative.
 * 
 * This project will be graded on:
 *      1. Documentation (4 points): Your code must be fully commented and employ standard C++-style
 *          conventions.
 *      2. User-Friendliness (4 points): All interactions with the user must be clear and unambiguous.
 *      3. Linked list and class structure (8 points): Linked list works properly to store an individual number
 *          from the user.
 *      4. Functionality (8 points): Each operator works as expected.
 * TOTAL: 24 points
 * 
 * Sample output (testing addition only):
 *      Enter first positive integer: 87435704325782438757285045089847
 *      Enter second positive integer: 4523852345234255895 
 *      Sum = 87435704325786962609630279345742
 * 
 *      Enter first positive integer: ...
 *          99999999999999999999999999999999999999999999999999999999999999999999999999999999
 *          9999999999999999999999999999999999999999999999999999999999999999999999999999999
 *      Enter second positive integer: 1
 *      Sum = ...
 *          10000000000000000000000000000000000000000000000000000000000000000000000000000000
 *          00000000000000000000000000000000000000000000000000000000000000000000000000000000
 * 
 * Sample output (testing subtraction only):
 *      Enter first positive integer: 98765432109876543210
 *      Enter second positive integer: 9999999999
 *      Difference = 98765432099876543211
 * 
 *      Enter first positive integer: 1000000000000000
 *      Enter second positive integer: 7
 *      Difference = 999999999999993
 * 
 *      Enter first positive integer: 12345
 *      Enter second positive integer: 67890
 *      Difference = -55545
 **/

#include <bits/stdc++.h>
#include "ListLab.h"
using namespace std;

/*void printMe(BigMath* head) {
	cout << "[";
	while(head != NULL) {
		cout << head->getDigit();
		head = head->getNext();
		if(head != NULL) cout << ", ";
	}
	cout << "]" << endl;
}*/

int main() {
    string t1="1", t2="10";
    //cin >> t1 >> t2;

    BigMath a = BigMath(t1);
    BigMath b = BigMath(t2);

    printMe(&a);
    printMe(&b);

    cout << "first: " << a << endl;
    cout << "second: " << b << endl;
    cout << "a+b: " << a+b << endl;
    cout << "a-b: " << a-b << endl;

    return 0;
}