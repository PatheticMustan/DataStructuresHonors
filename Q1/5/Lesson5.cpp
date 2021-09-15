/** Lesson5.cpp, by Kevin Wang
 * Write a program that asks the user to input two Boolean values and
 * demonstrates the result of various bitwise operators on them.
 **/

#include <bits/stdc++.h>

// why you booli me
typedef bool booli;

int main() {
    using namespace std;

    cout << "Input two booleans (1 or 0) seperated a space: " << endl;
    booli a, b;
    cin >> a >> b;

    cout << "a & b: " << (a & b) << endl;
    cout << "a | b: " << (a | b) << endl;
    cout << "a ^ b: " << (a ^ b) << endl;
    cout << "!a & !b: " << (!a & !b) << endl;
    cout << "!a | !b: " << (!a | !b) << endl;
    return 0;
}