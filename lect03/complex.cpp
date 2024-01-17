//complex.cpp
#include <iostream>
#include <cmath>
using namespace std;

// Represents a complex number as an Abstract Data Type (ADT): a + jb
class Complex{
    public:
        Complex(int re = 0 , int im = 0) : real(re), imag(im){} // paramterized constructor
        ~Complex(){
         //   cout << "Bye" << endl;
        } // default destructor

        Complex(const Complex& other){
            real = other.real;
            imag = other.imag;
        }

        Complex& operator=(const Complex& other){
            // some code
            real = other.real;
            imag = other.imag;
        }
        // x = y; x & y are of type complex

        // Pass by value always calls the copy constructor

        // Complex c(z);

        // Complex other(z);

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

ostream& operator<<(ostream& out, const Complex& c){
    c.print();
    // out << c;
    return out;
}
   

void Complex::print() const{
    cout << real << " + " << imag << "j" << endl;
}

double Complex::magnitude() const {
    return sqrt(pow(getReal(),2) + pow(getImag(), 2));
}

void Complex::conjugate() { imag = -1 * imag;}
// memory leak
void foo(){
    Complex* p = new Complex(1, 3);
}

Complex* bar(){
    Complex x, y;
    Complex* p = new Complex(1, 3);
    return p;

}
int main(int argc, char const *argv[])
{
    Complex* q= bar();
    delete q;
    foo();
    Complex x(3, 4), y(1, 2);
    Complex w(1, 2);
    Complex r(w); // r will be initialized using w's values
                  //Calls copy constructor
    Complex z = r; // also calls copy
    z = x; // Copy assignment function

    cout << r;
    // cout << x.magnitude() << endl;
    // Complex z;
    // z = x.add(y);
    // z = x + y + w; // operator overloading
    //            // x.operator+(y) or operator+(x, y)
    // z.print();
    // cout << z << x;
    return 0;
}