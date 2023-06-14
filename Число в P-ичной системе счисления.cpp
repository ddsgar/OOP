//14.	Реализовать класс «Число в P-ичной системе счисления». Основание системысчисления должно быть компонентным данным класса. 
//Реализовать в виде методов следующие операции над натуральными числами в P-ичной системе счисления (2 ≤ P ≤ 9): 
//− сложение;
//− вычитание;
//− умножение;
//− деление;
//− перевод из десятичной системы счисления в P-ичную;
//− перевод из P-ичной системы счисления в десятичную систему счисления; − проверка правильности записи числа в P-ичной системе счисления.
//В программе продемонстрировать использование объектов класса «Число в P-ичной системе счисления».


#include <iostream>
#include <string>
#include <cmath>

class PNumber {
private:
    int base;        // Основание системы счисления
    std::string num; // Число в P-ичной системе счисления

public:
    PNumber(int base) : base(base), num("") {}

    void input() {
        std::cout << "Enter number in base-" << base << " system: ";
        std::cin >> num;
    }

    void display() const {
        std::cout << "Number in base-" << base << " system: " << num << std::endl;
    }

    PNumber add(const PNumber& other) const {
        int maxLength = std::max(num.length(), other.num.length());
        int carry = 0;
        std::string result = "";

        for (int i = 0; i < maxLength; i++) {
            int digit1 = (i < num.length()) ? num[num.length() - i - 1] - '0' : 0;
            int digit2 = (i < other.num.length()) ? other.num[other.num.length() - i - 1] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / base;
            int digit = sum % base;

            result = std::to_string(digit) + result;
        }

        if (carry > 0) {
            result = std::to_string(carry) + result;
        }

        return PNumber(base, result);
    }

    PNumber subtract(const PNumber& other) const {
        std::string result = "";
        int borrow = 0;

        for (int i = 0; i < num.length(); i++) {
            int digit1 = num[num.length() - i - 1] - '0';
            int digit2 = (i < other.num.length()) ? other.num[other.num.length() - i - 1] - '0' : 0;

            int diff = digit1 - digit2 - borrow;

            if (diff < 0) {
                diff += base;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result = std::to_string(diff) + result;
        }

        return PNumber(base, result);
    }

    PNumber multiply(const PNumber& other) const {
        std::string result = "0";

        for (int i = other.num.length() - 1; i >= 0; i--) {
            int digit = other.num[i] - '0';
            std::string partialProduct = multiplyByDigit(digit);

            for (int j = 0; j < other.num.length() - 1 - i; j++) {
                partialProduct += "0";
            }

            result = add(result, partialProduct);
        }

        return PNumber(base, result);
    }

    PNumber divide(const PNumber& other) const {
        std::string quotient = "0";
        std::string remainder = num;

        while (compare(remainder, other) >= 0) {
            int count = 0;

            while (compare(remainder, multiplyByDigit(count + 1, other.base)) >= 0) {
                count++;
            }

            std::string partialQuotient = std::to_string(count);
            std::string partialProduct = multiplyByDigit(count, other.base);
            remainder = subtract(remainder, partialProduct);

            quotient = add(quotient, partialQuotient);
        }

        return PNumber(base, quotient);
    }

    std::string toDecimal() const {
        int decimal = 0;

        for (int i = 0; i < num.length(); i++) {
            int digit = num[i] - '0';
            decimal = decimal * base + digit;
        }

        return std::to_string(decimal);
    }

    bool isValid() const {
        for (int i = 0; i < num.length(); i++) {
            int digit = num[i] - '0';

            if (digit < 0 || digit >= base) {
                return false;
            }
        }

        return true;
    }

private:
    PNumber(int base, const std::string& num) : base(base), num(num) {}

    std::string multiplyByDigit(int digit) const {
        std::string result = "";
        int carry = 0;

        for (int i = num.length() - 1; i >= 0; i--) {
            int numDigit = num[i] - '0';
            int product = numDigit * digit + carry;
            carry = product / base;
            int remainder = product % base;

            result = std::to_string(remainder) + result;
        }

        if (carry > 0) {
            result = std::to_string(carry) + result;
        }

        return result;
    }

    std::string multiplyByDigit(int digit, int base) const {
        std::string result = "";
        int carry = 0;

        for (int i = num.length() - 1; i >= 0; i--) {
            int numDigit = num[i] - '0';
            int product = numDigit * digit + carry;
            carry = product / base;
            int remainder = product % base;

            result = std::to_string(remainder) + result;
        }

        if (carry > 0) {
            result = std::to_string(carry) + result;
        }

        return result;
    }

    std::string add(const std::string& num1, const std::string& num2) const {
        int maxLength = std::max(num1.length(), num2.length());
        int carry = 0;
        std::string result = "";

        for (int i = 0; i < maxLength; i++) {
            int digit1 = (i < num1.length()) ? num1[num1.length() - i - 1] - '0' : 0;
            int digit2 = (i < num2.length()) ? num2[num2.length() - i - 1] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / base;
            int digit = sum % base;

            result = std::to_string(digit) + result;
        }

        if (carry > 0) {
            result = std::to_string(carry) + result;
        }

        return result;
    }

    std::string subtract(const std::string& num1, const std::string& num2) const {
        std::string result = "";
        int borrow = 0;

        for (int i = 0; i < num1.length(); i++) {
            int digit1 = num1[num1.length() - i - 1] - '0';
            int digit2 = (i < num2.length()) ? num2[num2.length() - i - 1] - '0' : 0;

            int diff = digit1 - digit2 - borrow;

            if (diff < 0) {
                diff += base;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result = std::to_string(diff) + result;
        }

        return result;
    }

    int compare(const std::string& num1, const std::string& num2) const {
        if (num1.length() != num2.length()) {
            return num1.length() - num2.length();
        }

        for (int i = 0; i < num1.length(); i++) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[i] - '0';

            if (digit1 != digit2) {
                return digit1 - digit2;
            }
        }

        return 0;
    }
};

int main() {
    int base;
    std::cout << "Enter the base (2-9): ";
    std::cin >> base;

    PNumber num1(base), num2(base);
    num1.input();
    num2.input();

    std::cout << std::endl;
    num1.display();
    num2.display();
    std::cout << std::endl;

    PNumber sum = num1.add(num2);
    PNumber difference = num1.subtract(num2);
    PNumber product = num1.multiply(num2);
    PNumber quotient = num1.divide(num2);

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    difference.display();

    std::cout << "Product: ";
    product.display();

    std::cout << "Quotient: ";
    quotient.display();

    std::cout << "Num1 in decimal: " << num1.toDecimal() << std::endl;
    std::cout << "Num2 in decimal: " << num2.toDecimal() << std::endl;

    bool isValid1 = num1.isValid();
    std::cout << "Num1 is " << (isValid1 ? "valid" : "invalid") << std::endl;

    bool isValid2 = num2.isValid();
    std::cout << "Num2 is " << (isValid2 ? "valid" : "invalid") << std::endl;

    return 0;
}
