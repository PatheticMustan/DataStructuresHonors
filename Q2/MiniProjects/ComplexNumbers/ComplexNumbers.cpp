/** ComplexNumber.cpp, by Kevin Wang
 * 
 * Complete the following program with the given declarations. All user input and output must occur in your
 * main function. You are permitted to create other functions if you feel they would help you complete the task.
 * Call your C++ file ComplexNumbers. This is to be submitted to Classroom by the date on the assignment. You
 * are only completing one C++ file for this mini-project.
 * 
 * In your main function, display a menu to ask the user for their desired task. They are to first choose their
 * operation and then enter the values required. Their options are listed below. When the process is complete, ask
 * the user if they want to do it again.
 * 
 * In mathematics, complex numbers are used as the basis of a vector system on the coordinate plane. When
 * graphing, we think of the real part (a) as the x-value and the imaginary part (b) as the y-value. Create a class
 * called Complex inside of your program. Your class must contain private attributes for the a and b values for a
 * given Complex object. You must also create a constructor to set the values for your object. Your class must
 * also contain the following methods.
 * 
 *   Complex conjugate()
 *      This method returns the complex conjugate for the Complex.
 *   double norm()
 *      This method returns the norm of the Complex.
 *   double real()
 *      This method returns the real part of the Complex.
 *   double imag()
 *      This method returns the imaginary part of the Complex.
 *   double dotProduct(Complex other)
 *      This method returns the dot product of the Complex and the parameter.
 *   Complex scalarProduct(double value)
 *      This method returns the scalar product of the Complex and the parameter.
 *   double angleBetween(Complex other)
 *      This method returns the angle between the Complex and the parameter (in degrees).
 * 
 * Your class must also contain overloaded operators for addition, subtraction, multiplication, division, equality,
 * and conversion (so that your Complex prints out in proper a + bi form). In your main function, you must
 * allow the user to pick their choice of operations and enter the values for their Complex object(s) and required
 * other values. After the user has entered the information, display the requested result.
 * 
 * This project will be graded on:
 *      1. Documentation (4 points): Your code must be fully commented and employ standard C++-style conventions.
 *      2. User-Friendliness (4 points): All interactions with the user must be clear and unambiguous.
 *      3. Methods (21 points): Each function has the proper declaration and works as expected.
 *      4. Overloaded operators (12 points): Each operator works as expected.
 * TOTAL: 41 points
 **/

#include <bits/stdc++.h>
using namespace std;

class Complex {
    private:
        double a, b;
        


    public:
        Complex() {
            a = 0;
            b = 0;
        }

        Complex(double inputA, double inputB) {
            a = inputA;
            b = inputB;
        }



        // This method returns the complex conjugate for the Complex.
        Complex conjugate() {
            return Complex(a, -b);
        }

        // This method returns the norm of the Complex.
        double norm() {
            return sqrt(a*a + b*b);
        }
        
        // This method returns the real part of the Complex.
        double real() {
            return a;
        }

        // This method returns the imaginary part of the Complex.
        double imag() {
            return b;
        }

        // This method returns the dot product of the Complex and the parameter.
        double dotProduct(Complex other) {
            return real()*other.real() + imag()*other.imag();
        }

        // This method returns the scalar product of the Complex and the parameter.
        Complex scalarProduct(double value) {
            return Complex(a*value, b*value);
        }

        // This method returns the angle between the Complex and the parameter (in degrees).*/
        double angleBetween(Complex other) {
            // i hope this is correct
            double rad = atan2(other.imag()-imag(), other.real()-real());
            double deg = rad * (180.0/M_PI);
            if (deg < 0) return (360.0+deg);
            return deg;
        }





        // custom operators
        Complex operator+ (Complex& other) {
            return Complex(real()+other.real(),    imag()+other.imag());
        };
        
        Complex operator- (Complex& other) {
            return Complex(real()-other.real(),    imag()-other.imag());
        };
        // adi!!! wow wow wow
        // (a + bi)(c + di) = ac + adi + bci - bd
        // Complex(ac-bd, ad+bc)
        Complex operator* (Complex& other) {
            double a = real(),
                   b = imag(),
                   c = other.real(),
                   d = other.imag();
            return Complex(a*c - b*d,    a*d + b*c);
        };
        
        // not gonna lie i had to google how to divide two complex numbers
        // i don't think i've learned complex numbers yet :(
        Complex operator/ (Complex& other) {
            double a = real(),
                   b = imag(),
                   c = other.real(),
                   d = other.imag();
            
            return Complex(
                (a*c + b*d)/(c*c + d*d), // real
                (b*c - a*d)/(c*c + d*d)  // imaginary
            );
        };
};

// toString
ostream& operator<< (ostream &strm, Complex& c) {
    string result = "";
    if (c.imag() < 0) {
        result = "(" + to_string(c.real()) + " - " + to_string(-1 * c.imag()) + "i)";
    } else {
        result = "(" + to_string(c.real()) + " + " + to_string(c.imag()) + "i)";
    }
    return strm << result;
}

// get input made easy
Complex getComplexFromInput() {
    cout << "Please enter the real and imaginary values for the complex number\n";
    double a, b;
    cin >> a >> b;

    return Complex(a, b);
}

int main() {
    /*Complex a = Complex(1, 0);
    Complex b(2, -3);
    Complex c = a + b;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;*/

    // why are there so many options
    cout << "\nComplex Numbers! Wow. Select an option!\n"
         << "[1] Conjugate\n"
         << "[2] Norm\n"
         << "[3] Real\n"
         << "[4] Imag\n"
         << "[5] DotProduct\n"
         << "[6] ScalarProduct\n"
         << "[7] AngleBetween\n"
         << "[8] Add\n"
         << "[9] Subtract\n"
         << "[10] Multiply\n"
         << "[11] Divide\n"
         << "[12] Exit\n\n";
    
    int option = -1;
    cin >> option;
    if (option < 1 || option > 12) {
        cout << "Ouch! Not a valid option. Try again!";
        return main();
    }

    // exit
    if (option == 12) return 0;

    Complex first, second;
    switch (option) {
        case 1: {
            first = getComplexFromInput().conjugate();
            cout << first;
            break;
        }
        case 2: {
            cout << getComplexFromInput().norm();
            break;
        }
        case 3: {
            cout << getComplexFromInput().real();
            break;
        }
        case 4: {
            cout << getComplexFromInput().imag();
            break;
        }
        case 5: {
            first = getComplexFromInput();
            second = getComplexFromInput();
            cout << first.dotProduct(second);
            break;
        }
        case 6: {
            first = getComplexFromInput();
            cout << "Please enter the multiplier\n";
            double d;
            cin >> d;
            Complex r = first.scalarProduct(d);
            cout << r;
            break;
        }
        case 7: {
            first = getComplexFromInput();
            second = getComplexFromInput();
            cout << first.angleBetween(second);
            break;
        }
        case 8: {
            first = getComplexFromInput();
            second = getComplexFromInput();
            Complex result = first + second;
            cout << result;
            break;
        }
        case 9: {
            first = getComplexFromInput();
            second = getComplexFromInput();
            Complex result = first - second;
            cout << result;
            break;
        }
        case 10: {
            first = getComplexFromInput();
            second = getComplexFromInput();
            Complex result = first * second;
            cout << result;
            break;
        }
        case 11: {
            first = getComplexFromInput();
            second = getComplexFromInput();
            Complex result = first / second;
            cout << result;
            break;
        }
        case 12: {
            return 0;
            // break;
        }
    }

    cout << "\n\n";
    // there is no escape
    return main();
}