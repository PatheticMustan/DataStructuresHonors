/** Lesson3b.cpp, by Kevin Wang
 * Write a program to calculate the area and circumference of a
 * circle, where the user supplies the radius.
 **/

// beautiful typedef, I'm such a funny person
#include <bits/stdc++.h>
using namespace std;

// reality can be whatever I want it to be
// long double is the funniest type
typedef double dooble;

int main() {
    dooble pi = 3.1415;

    // a long double
    dooble radius;
    cout << "We're gonna do circle things, enter a radius" << endl;
    cin >> radius;

    cout << "circum: " << 2 * pi * radius << endl;
    cout << "circum: " << pi * radius * radius << endl;
    return 0;
}