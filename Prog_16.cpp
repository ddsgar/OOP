#include <iostream>
#include <vector>

class Polynomial {
public:
    Polynomial(const std::vector<double>& coefficients) : coefficients(coefficients) {}

    double evaluate(double x) const {
        double result = 0.0;
        double power = 1.0;

        for (double coefficient : coefficients) {
            result += coefficient * power;
            power *= x;
        }

        return result;
    }

    Polynomial operator+(const Polynomial& other) const {
        std::vector<double> resultCoefficients;

        size_t maxSize = std::max(coefficients.size(), other.coefficients.size());

        for (size_t i = 0; i < maxSize; i++) {
            double coefficient1 = (i < coefficients.size()) ? coefficients[i] : 0.0;
            double coefficient2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0.0;
            resultCoefficients.push_back(coefficient1 + coefficient2);
        }

        return Polynomial(resultCoefficients);
    }

    Polynomial operator-(const Polynomial& other) const {
        std::vector<double> resultCoefficients;

        size_t maxSize = std::max(coefficients.size(), other.coefficients.size());

        for (size_t i = 0; i < maxSize; i++) {
            double coefficient1 = (i < coefficients.size()) ? coefficients[i] : 0.0;
            double coefficient2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0.0;
            resultCoefficients.push_back(coefficient1 - coefficient2);
        }

        return Polynomial(resultCoefficients);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<double> resultCoefficients(coefficients.size() + other.coefficients.size() - 1, 0.0);

        for (size_t i = 0; i < coefficients.size(); i++) {
            for (size_t j = 0; j < other.coefficients.size(); j++) {
                resultCoefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultCoefficients);
    }

    Polynomial differentiate() const {
        std::vector<double> resultCoefficients;

        for (size_t i = 1; i < coefficients.size(); i++) {
            resultCoefficients.push_back(coefficients[i] * i);
        }

        return Polynomial(resultCoefficients);
    }

    Polynomial differentiate(size_t order) const {
        Polynomial result = *this;

        for (size_t i = 0; i < order; i++) {
            result = result.differentiate();
        }

        return result;
    }

    void display() const {
        for (size_t i = 0; i < coefficients.size(); i++) {
            std::cout << coefficients[i] << "x^" << i;
            if (i != coefficients.size() - 1) {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }

private:
    std::vector<double> coefficients;
};

int main() {
    std::vector<double> coefficients1 = {1, -3, 2};  // x^2 - 3x + 2
    std::vector<double> coefficients2 = {2, 4, -1};  // 2x^2 + 4x - 1

    Polynomial polynomial1(coefficients1);
    Polynomial polynomial2(coefficients2);

    std::cout << "Polynomial 1: ";
    polynomial1.display();

    std::cout << "Polynomial 2: ";
    polynomial2.display();

    double x = 2.0;

    std::cout << "Evaluate polynomial 1 at x = " << x << ": " << polynomial1.evaluate(x) << std::endl;
    std::cout << "Evaluate polynomial 2 at x = " << x << ": " << polynomial2.evaluate(x) << std::endl;

    Polynomial sum = polynomial1 + polynomial2;
    std::cout << "Sum of the polynomials: ";
    sum.display();

    Polynomial difference = polynomial1 - polynomial2;
    std::cout << "Difference of the polynomials: ";
    difference.display();

    Polynomial product = polynomial1 * polynomial2;
    std::cout << "Product of the polynomials: ";
    product.display();

    size_t order = 2;
    Polynomial derivative = polynomial1.differentiate(order);
    std::cout << "Derivative of polynomial 1 (order " << order << "): ";
    derivative.display();

    return 0;
}
