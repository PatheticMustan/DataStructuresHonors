/** Lesson7.cpp, by Kevin Wang
 * 1. Write a function with a return type of void that still helps the
 *      caller calculate the area and circumference of a circle when
 *       supplied the radius. No print in function.
 * 2. Write overloaded functions that calculate the volume of a sphere and a cylinder.
 **/

#include <bits/stdc++.h>
using namespace std;

double circum = -1;
double area = -1;

void calcArea(double radius) {
    circum = 2 * M_PI * radius;
    area = M_PI * radius * radius;
}

double calcShape(double radius) {
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}
double calcShape(double radius, double height) {
    return M_PI * pow(radius, 2) * height;
}

int main() {
    cout << "Enter a radius: \n";

    double radius;
    cin >> radius;

    calcArea(radius);

    cout <<
        "circle with a radius of " << radius <<
        " has a circumfrence of " << circum <<
        " and an area of " << area << "\n\n";

    cout << calcShape(5) << " " << calcShape(9, 10);

    return 0;
}