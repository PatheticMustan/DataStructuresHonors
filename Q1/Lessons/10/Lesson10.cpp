/** Lesson10.cpp, by Kevin Wang
 * Create classes Polygon, Triangle, and Shape using proper inheritance protocols.
 * Have methods in each that relate to the classes themselves.
 * Create an object in your main function to test the implementation.
 **/

#include <bits/stdc++.h>
using namespace std;

class Shape {
    protected:
        Shape() {}
};
class Polygon : public Shape {
    public:
        Polygon(int s) {
            sides = s;
        }
        int GetSides() {
            return sides;
        }

    private:
        int sides;
};
class Triangle : public Polygon {
    public:
        Triangle() : Polygon(3) {}
        void Illuminati() {
            cout << "THE TRIANGLE CALLS" << "\n";
        }

};

int main() {
    Triangle t = Triangle();
    
    cout << t.GetSides() << "\n";
    t.Illuminati();

    Polygon p = Polygon(17);
    cout << p.GetSides() << "\n";

    return 0;
}