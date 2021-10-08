/** Lesson2 but better.cpp, by Kevin Wang
 * Asks for numbers and screams them out with Maths! OwO UwU
 **/
#include <iostream>

int main()                                                                                                 {
    using namespace std /*i love std's, but typing it out every time is a bit painful*/                    ;
                        /*now I can replace "std::cin" with "cin"*/                                        ;
    cout << "Alright give me three numbers, seperated by spaces. Don't use commas or I will cry: \n"       ;
    int a, b, c       /*get input with the magic that is cin*/                                             ;
    cin >> a >> b >> c                                                                                     ;
                                                                                                           ;
    cout << "a: "           << a           << "\n"     /*omg im so cool copy paste is next gen*/           ;
    cout << "b: "           << b           << "\n"     /*isn't my spacing beautiful*/                      ;
    cout << "c: "           << c           << "\n"                                                         ;
    cout << "a+b: "         << a+b         << "\n"                                                         ;
    cout << "b+c: "         << b+c         << "\n"                                                         ;
    cout << "c+a: "         << c+a         << "\n"                                                         ;
    cout << "a*b-c: "       << a*b-c       << "\n"                                                         ;
    cout << "a+a+a+a+a+a: " << a+a+a+a+a+a << "\n"     /*or as my friends like to call it, AAAAAA*/        ;
    return 0           /*I wonder if I can return whatever I want here*/                                   ;
                                                                                                           }