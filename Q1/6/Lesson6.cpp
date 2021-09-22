/** Lesson6.cpp, by Kevin Wang
 * Adds two equal length arrays, reverses it
 * 
 * Write a program that adds corresponding elements in two
 * same-sized arrays in reverse order so that the sum of the last two
 * elements is first, etc.
 * {1,3,5,8} + {2,2,4,12} = {20,9,5,3}
 **/

#include <bits/stdc++.h>
using namespace std;

int main() {
    const int size = 5;

    // the holy numbers
    int one[size] = {1337, 69, 420, 666, 42},
        two[size] = {177013, 228922, 135135, 2769, 184594917};
    // 184594917 is the best number

    int result[size];

    for (int i=0; i<size; i++) {
        // ah yes, i[result], the lesser known brother of result[i]
        result[size-i-1] = one[i] + two[i];
    }

    cout << "Result: \n";
    for (int i=0; i<size; i++) {
        cout << result[i];
    }
    cout << "\n\n";

    return 0;
}