/** Shapes.cpp, by Kevin Wang
 * Complete the following program with the given declarations. All user input and output must occur in your
 * main function. You are permitted to create other functions if you feel they would help you complete the task.
 * Call your C++ file Shapes. This is to be submitted to Classroom by the date on the assignment. You are only
 * completing one C++ file for this mini-project.
 * 
 * In your main function, display a menu to ask the user for their desired task. They are to first choose their
 * operation and then enter the values required. Their options are listed below. When the process is complete, ask
 * the user if they want to do it again.
 * 
 * Create a class called Polygon inside of your program. Your class must contain protected attributes for the
 * length and width for a given Polygon object. You must also create a constructor to set the length and width
 * for your object. Your class must also contain the following methods, as well as any relevant accessor and
 * mutator methods.
 * 
 * In class Polygon:
 *  void setValues(int a, int b)
 *       This method sets both the length and width for the Polygon.
 * 
 * You must also create at least two other derived classes that deal with specific types of Polygons, such as
 * Rectangle or Triangle.
 * These classes must have the following methods:
 *  float area()
 *      This method returns the area of the Polygon.
 * 
 * In your main function, you must allow the user to pick their choice of Polygon and enter its information.
 * You must show the invocation using both the constructor and the setValues method, although either one
 * may be commented out if you choose to do so. After the user has entered the information, display the relevant
 * information about the Polygon using the Output class.
 * 
 * The Output class must contain the following public method:
 *  void print();
 *      This method prints the length, width, and area of the calling object.
 *      As a hint, this project uses multiple inheritance (YAY C++!).
 * 
 * This project will be graded on:
 *  1. Documentation (4 points): Your code must be fully commented and employ standard C++-style
 *      conventions.
 *  2. User-Friendliness (4 points): All interactions with the user must be clear and unambiguous.
 *  3. Classes (24 points): Each function has the proper declaration and works as expected.
 * TOTAL: 32 points
 **/

#include <bits/stdc++.h>
using namespace std;

class Polygon {
    public:
        // constructors
        Polygon(int l, int w) {
            setValues(l, w);
        }

        // accessor/mutators
        int getLength() { return length; }
        int getWidth() { return width; }
        void setLength(int l) { length = l; }
        void setWidth(int w) { width = w; }

        // util methods
        // sets both the length and width for the Polygon.
        void setValues(int l, int w) {
            setLength(l);
            setWidth(w);
        }
    
    private:
        int length;
        int width;
};

class Output {
    public:
        // util methods
        // prints the length, width, and area of the calling object.
        void print();
};

class Rectangle : public Polygon, public Output {
    public:
        // constructors
        Rectangle(int l, int w) : Polygon(l, w) {}

        // util methods
        // returns the area of the Polygon.
        float area() {
            return (float)getLength() * (float)getWidth();
        }

        void print() {
            cout <<
                "Length: " << getLength() <<
                " Width: " << getWidth() <<
                " Area: " << area() << "\n";
        }
};

class Triangle : public Polygon, public Output {
    public:
        // constructors
        Triangle(int l, int w) : Polygon(l, w) {}

        // util methods
        // returns the area of the Polygon.
        float area() {
            return (float)getLength() * (float)getWidth() / 2;
        }

        void print() {
            cout <<
                "Length: " << getLength() <<
                " Width: " << getWidth() <<
                " Area: " << area() << "\n";
        }
};





int main() {
    cout << "Aw yeah, let's make a polygon! \n"
         << "[1] Make a triangle \n"
         << "[2] Make a rectangle \n"
         << "[3] Exit \n";

    int choice = -1;
    while (choice != 1 && choice != 2 && choice != 3) {
        cin >> choice;

        // exit
        if (choice == 3) return 0;
        // if it's not valid, ask again
        if (choice != 1 && choice != 2) cout << "\nOuch! Please pick a valid option. \n";
    }



    cout << "\nGive two integers for the length and width: \n";
    int l, w;
    cin >> l >> w;



    // triangle
    if (choice == 1) {
        // constructor
        Triangle t = Triangle(l, w);
        // setValues
        //t.setValues(l, w);

        cout << "Triangle(" << l << ", " << w << "): ";
        t.print();
    } else {
        // constructor
        Rectangle r = Rectangle(l, w);
        // setValues
        //r.setValues(l, w);

        cout << "Rectangle(" << l << ", " << w << "): ";
        r.print();
    }

    cout << "\n\n";
    main();

    return 0;
}