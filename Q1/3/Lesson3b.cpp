/** Lesson3b.cpp, by Kevin Wang
 * Write a program to calculate the area and circumference of a
 * circle, where the user supplies the radius.
 **/

// the lazy #include
#include <bits/stdc++.h>
using namespace std;

// reality can be whatever I want it to be
// long double is the funniest type
typedef long double dooble;

int main() {
    // a long double
    dooble radius;
    cout << "We're gonna do circle things, enter a radius" << endl;
    cin >> radius;

    cout << "circum: " << 2 * M_PI * radius << endl;
    cout << "area: " << M_PI * radius * radius << endl;
    return 0;
}