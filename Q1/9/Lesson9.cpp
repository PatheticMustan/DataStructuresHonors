/** TemplateFile.cpp, by Kevin Wang
 * Write a class called Circle that computes the area and
 * circumference using the radius that is supplied to the class as a
 * parameter at the time of instantiation. Pi should be contained
 * in a constant private member that cannot be accessed from outside the
 * circle. Your main function must create and display the information on a minimum of 3 circles.
 **/

#include <bits/stdc++.h>
using namespace std;

class Circle {
    private:
        float pi = M_PI;

    public:
        int radius;

        // constructors
        Circle(float r = 1) {radius = r;}

        // get xyz
        float getCircumfrence() {return 2*pi*radius;}
        float getArea() {return pi*radius*radius;}
};

int main() {
    Circle circeArmy[3] = {
        Circle(),
        Circle(5),
        Circle(3.2)
    };
    Circle* c; 

    for (int i=0; i<3; i++) {
        c = &circeArmy[i];
        cout << "A circle with a radius of " << (*c).radius <<
                ", an area of " << (*c).getArea() <<
                ", and a circumfrence of " << (*c).getCircumfrence()
                << "\n\n";
    }

    return 0;
}