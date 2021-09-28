/** Lesson8.cpp, by Kevin Wang
 * Write a program that accepts 5 integer values from the keyboard.
 * Store them in an array using a pointer. Then print the array,
 * starting at the beginning of the array and again starting at the end using pointers.
 **/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "enter 5 numbers yar har ho" << endl;
    
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int array[5];
    int* sharpStick;
    
    // make pointer point
    // *(int*)++ is the most cursed thing I've written,
    // but I'm sure I'll have the chance to write even worse
    sharpStick = array;
    *sharpStick++ = a;
    *sharpStick++ = b;
    *sharpStick++ = c;
    *sharpStick++ = d;
    *sharpStick++ = e;
    
    // re-point the pointy pointer
    sharpStick = array;
    for (int i=0; i<5; i++) {
        cout << *sharpStick++ << "\n";
    }

    return 0;
}