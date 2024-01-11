//complex.cpp
#include <iostream>
#include <cmath>
using namespace std;

// Represents a complex number as an Abstract Data Type (ADT): a + jb
class Complex{
    public:
        Complex(int re = 0 , int im = 0) : real(re), imag(im){} // paramterized constructor
        double getReal() const { return real;}
        double getImag() const { return imag;}
        void print() const;
        double magnitude() const;
        void conjugate();

        Complex add(Complex other) const{ // member function
            return Complex(real + other.real, imag + other.imag);
        }
        // Complex operator+(Complex other) const{ // member function
        //     return Complex(real + other.real, imag + other.imag);
        // }
   
    private:
        double real;
        double imag; 
};
Complex operator+(Complex a, Complex b) { // non-member function
        return Complex(a.getReal() + b.getReal(), b.getImag() + a.getImag());
}
   

void Complex::print() const{
    cout << real << " + " << imag << "j" << endl;
}

double Complex::magnitude() const {
    return sqrt(pow(getReal(),2) + pow(getImag(), 2));
}

void Complex::conjugate() { imag = -1 * imag;}


int main(int argc, char const *argv[])
{
    Complex x(3, 4), y(1, 2);
    Complex w(1, 2);
    cout << x.magnitude() << endl;
    Complex z;
    // z = x.add(y);
    z = x + y; // operator overloading
    z.print();
    return 0;
}