/** Lesson7a.cpp, by Kevin Wang
 * Write a function that accepts a nonnegative integer from the user
 * and displays true in main if the integer is a perfect number.
 * The function has no return and no print.
 **/

#include <bits/stdc++.h>
using namespace std;

void isPerfect(int n, bool& isTrue) {
    int sum = 0;
    for (int i=1; i<n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    isTrue = (sum == n);
}

int main() {
    int input;
    cin >> input;

    bool thing;
    isPerfect(input, thing);

    cout << "\n" << (thing? "trueeeeee!" : "falsetto")<< "\n";
    return 0;
}




