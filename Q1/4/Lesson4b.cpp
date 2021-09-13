/** Lesson4b.cpp, by Kevin Wang
 * Write a program that asks the user for 3 strings and creates a 2-dimensional array,
 * where each row contains the given strings once.
 * Then create a 2-dimensional array, where each column contains the given strings once.
 **/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    string rowThing[3][3] = {{a, b, c}, {a, b, c}, {a, b, c}};
    string columnThing[3][3] = {{a, a, a}, {b, b, b}, {c, c, c}};

    cout << "\n"

    return 0;
}


for (int i=0; i<sizeof(arr)/sizeof(string); i++) {}