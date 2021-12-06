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
        
        // equality
        bool operator== (Complex other) {
            return (real() == other.real()) && (imag() == other.imag());
        }
};

// toString
ostream& operator<< (ostream &strm, Complex c) {
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