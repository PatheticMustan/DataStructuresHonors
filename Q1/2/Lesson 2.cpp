/** Lesson 2.cpp, by Kevin Wang
 * Asks for numbers and screams them out with Maths! OwO UwU
 **/
#include <iostream>

int main() {
    // i love std's, but typing it out every time is a bit painful
    // now I can replace "std::cin" with "cin"
    using namespace std;

    cout << "Alright give me three numbers, seperated by spaces. Don't use commas or I will cry: \n";

    // get input with the magic that is cin
    int a, b, c;
    cin >> a >> b >> c;

    // omg im so cool copy paste is next gen
    // isn't my spacing beautiful
    cout << "a: "           << a           << "\n";
    cout << "b: "           << b           << "\n";
    cout << "c: "           << c           << "\n";
    cout << "a+b: "         << a+b         << "\n";
    cout << "b+c: "         << b+c         << "\n";
    cout << "c+a: "         << c+a         << "\n";
    cout << "a*b-c: "       << a*b-c       << "\n";
    cout << "a+a+a+a+a+a: " << a+a+a+a+a+a << "\n"; // or as my friends like to call it, AAAAAA

    // I wonder if I can return whatever I want here
    return 0;
}