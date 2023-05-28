#include <iostream>

class Complex {
public:
    Complex(double real = 0.0, double imaginary = 0.0) : real(real), imaginary(imaginary) {}

    Complex operator+(const Complex& other) const {
        double sumReal = real + other.real;
        double sumImaginary = imaginary + other.imaginary;
        return Complex(sumReal, sumImaginary);
    }

    Complex operator-(const Complex& other) const {
        double diffReal = real - other.real;
        double diffImaginary = imaginary - other.imaginary;
        return Complex(diffReal, diffImaginary);
    }

    Complex operator*(const Complex& other) const {
        double multReal = real * other.real - imaginary * other.imaginary;
        double multImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(multReal, multImaginary);
    }

    void display() const {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }

private:
    double real;
    double imaginary;
};

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(1.0, -1.5);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    std::cout << "c1: ";
    c1.display();

    std::cout << "c2: ";
    c2.display();

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    difference.display();

    std::cout << "Product: ";
    product.display();

    return 0;
}
