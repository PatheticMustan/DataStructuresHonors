/** Lesson11.cpp, by Kevin Wang
 * Create the special quadrilaterals as a sequence of Base and Derived classes,
 * being sure to solve any multiple inheritance issues.
 * 
 *        Quadrilateral
 *       /           \
 *    Kite       Trapezoid
 *     \           /      \
 *      \  Parallelogram  IsoscelesTrapezoid
 *       \   /        \    /
 *      Rhombus     Rectangle
 *            \    /
 *            Square
 **/

#include <bits/stdc++.h>
using namespace std;



class Quadrilateral {
    private:
        const int numberOfSides = 4;
    public:
        Quadrilateral() {}
        int getNumberOfSides() { return numberOfSides; }
};

class Kite : public Quadrilateral {
    private:
        int diagonalOne,
            diagonalTwo;
    public:
        Kite() {}
        Kite(int diagOne, int diagTwo) {
            setDiagOne(diagOne);
            setDiagTwo(diagTwo);
        }
        int getDiagOne() { return diagonalOne; }
        int getDiagTwo() { return diagonalTwo; }
        void setDiagOne(int diagOne) { diagonalOne = diagOne; }
        void setDiagTwo(int diagTwo) { diagonalTwo = diagTwo; }
        float area() {
            return getDiagOne() * getDiagTwo() / 2.0;
        }
};

class Trapezoid : public Quadrilateral {
    private:
        int bottomBase,
            topBase,
            height;
    public:
        Trapezoid() {}
        Trapezoid(int bb, int tb, int h) {
            setBottomBase(bb);
            setTopBase(tb);
            setHeight(h);
        }
        int getBottomBase() { return bottomBase; }
        int getTopBase() { return topBase; }
        int getHeight() { return height; }
        void setBottomBase(int bb) { bottomBase = bb; }
        void setTopBase(int tb) { topBase = tb; }
        void setHeight(int h) { height = h; }
        float area() {
            return ((getBottomBase() + getTopBase()) / 2.0) * getHeight();
        }
};

class Parallelogram : public Trapezoid {
    public:
        Parallelogram() {}
        Parallelogram(int b, int h) : Trapezoid(b, b, h) {}
};
class Rhombus : public Kite, public Parallelogram {
    public:
        Rhombus() {}
        Rhombus(int diagOne, int diagTwo) : Kite(diagOne, diagTwo) {}
        float area() {
            Kite::area();
        };
        float perimeter() {
            // a2 + b2 = c2
            float a = getDiagOne() / 2.0;
            float b = getDiagTwo() / 2.0;
            return 4.0 * sqrt(a*a + b*b);
        }
};
class IsoscelesTrapezoid : public Trapezoid {
    public:
        IsoscelesTrapezoid() {}
        IsoscelesTrapezoid(int bb, int tb, int h) : Trapezoid(bb, tb, h) {}
        float perimeter() {
            float a = (getBottomBase() - getTopBase()) / 2.0;
            float b = getHeight();
            float sideLength = sqrt(a*a + b*b);
            return getTopBase() + getBottomBase() + sideLength + sideLength;
        }
};
class Rectangle : public Parallelogram, public IsoscelesTrapezoid {
    private:
        int width,
            height;
    public:
        Rectangle() {}
        Rectangle(int w, int h) {
            setWidth(w);
            setHeight(h);
        }
        int getWidth() { return width; }
        int getHeight() { return height; }
        void setWidth(int w) { width = w; }
        void setHeight(int h) { height = h; }
        float area() {
            return getWidth() * getHeight();
        };
        float perimeter() {
            return getWidth() + getWidth() + getHeight() + getHeight();
        }
};
class Square : public Rhombus, public Rectangle {
    public:
        Square() {}
        Square(int sl) : Rectangle(sl, sl) {}
        float area() {
            return Rectangle::area();
        }
};



int main() {
    Kite k(3, 5);
    // expected, 7.5
    cout << "kite area: " << k.area() << "\n";

    Trapezoid t(6, 9, 3);
    // expected, 22.5
    cout << "trapezoid area: " << t.area() << "\n";

    Parallelogram p(6, 7);
    // expected, 42
    cout << "parallelogram area: " << p.area() << "\n";

    Rhombus r(9, 8);
    // expected, 36
    cout << "rhombus area: " << r.area() << "\n";
    // i didn't check expected lmao
    cout << "rhombus perimeter: " << r.perimeter() << "\n";

    IsoscelesTrapezoid it(6, 9, 3);
    // expected, 22.5
    cout << "isoscelesTrapezoid area: " << it.area() << "\n";
    cout << "isoscelesTrapezoid perimeter: " << it.perimeter() << "\n";

    Square s(9);
    // expected, 22.5
    cout << "square area: " << s.area() << "\n";
    cout << "square perimeter: " << s.perimeter() << "\n";

    return 0;
}