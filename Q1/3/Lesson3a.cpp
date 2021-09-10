/** Lesson3a.cpp, by Kevin Wang
 * Write a program that demonstrates that the size of an
 * unsigned integer and a normal integer are the same, and that
 * both are smaller in size than a long integer (and long long if you’d like).
 **/
#include <iostream>

int main() {
    using namespace std;

    cout << "sizeof(int) lol xd: " << sizeof(int) << "\n";
    cout << "sizeof(uint) you should: " << sizeof(uint) << "\n";
    cout << "sizeof(long) read: " << sizeof(long) << "\n";
    cout << "sizeof(long long) bittersweet candy bowl: " << sizeof(long long) << "\n";

    // read at https://www.bittersweetcandybowl.com/ or https://bcb.com/
    return 0;
}