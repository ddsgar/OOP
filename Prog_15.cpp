//15.	Разработать класс «Римское число» для работы с числами, записанными в римскойсистеме счисления. 
//Реализовать возможность ввода и вывода чисел в римской системе счисления, а также методы, реализующие операции:
//− перевод натурального числа из десятичной системы счисления в римскую;
//− перевод числа из римской системы счисления в десятичную;
//− сложение;
//− вычитание;
//− умножение;
//− целочисленное деление и нахождение остатка от деления; − операции отношения (описать в виде логических функций) − проверка правильности записи римского числа.
//Операции сложения, вычитания, деления и умножения римских чисел реализовать как перегрузки соответствующих операций.
//В программе продемонстрировать использование объектов класса «Римское число».


#include <iostream>
#include <string>
#include <unordered_map>

class RomanNumber {
public:
    RomanNumber() {}

    RomanNumber(const std::string& roman) : roman(roman) {}

    void input() {
        std::cout << "Enter a Roman number: ";
        std::cin >> roman;
    }

    void display() const {
        std::cout << roman << std::endl;
    }

    std::string toDecimal() const {
        int decimal = 0;

        for (int i = 0; i < roman.length(); i++) {
            int value = romanToDecimalMap[roman[i]];
            int nextValue = (i < roman.length() - 1) ? romanToDecimalMap[roman[i + 1]] : 0;

            if (value < nextValue) {
                decimal -= value;
            } else {
                decimal += value;
            }
        }

        return std::to_string(decimal);
    }

    static std::string fromDecimal(int decimal) {
        std::string roman = "";

        for (const auto& pair : decimalToRomanMap) {
            int value = pair.first;
            const std::string& symbol = pair.second;

            while (decimal >= value) {
                roman += symbol;
                decimal -= value;
            }
        }

        return roman;
    }

    RomanNumber operator+(const RomanNumber& other) const {
        int decimal1 = std::stoi(toDecimal());
        int decimal2 = std::stoi(other.toDecimal());
        int sum = decimal1 + decimal2;
        return RomanNumber(fromDecimal(sum));
    }

    RomanNumber operator-(const RomanNumber& other) const {
        int decimal1 = std::stoi(toDecimal());
        int decimal2 = std::stoi(other.toDecimal());
        int difference = decimal1 - decimal2;
        return RomanNumber(fromDecimal(difference));
    }

    RomanNumber operator*(const RomanNumber& other) const {
        int decimal1 = std::stoi(toDecimal());
        int decimal2 = std::stoi(other.toDecimal());
        int product = decimal1 * decimal2;
        return RomanNumber(fromDecimal(product));
    }

    RomanNumber operator/(const RomanNumber& other) const {
        int decimal1 = std::stoi(toDecimal());
        int decimal2 = std::stoi(other.toDecimal());
        int quotient = decimal1 / decimal2;
        return RomanNumber(fromDecimal(quotient));
    }

    RomanNumber operator%(const RomanNumber& other) const {
        int decimal1 = std::stoi(toDecimal());
        int decimal2 = std::stoi(other.toDecimal());
        int remainder = decimal1 % decimal2;
        return RomanNumber(fromDecimal(remainder));
    }

    bool operator==(const RomanNumber& other) const {
        return roman == other.roman;
    }

    bool operator!=(const RomanNumber& other) const {
        return !(*this == other);
    }

    bool operator<(const RomanNumber& other) const {
        int decimal1 = std::stoi(toDecimal());
        int decimal2 = std::stoi(other.toDecimal());
        return decimal1 < decimal2;
    }

    bool operator>(const RomanNumber& other) const {
        return !(*this < other || *this == other);
    }

    bool operator<=(const RomanNumber& other) const {
        return (*this < other || *this == other);
    }

    bool operator>=(const RomanNumber& other) const {
        return !(*this < other);
    }

    bool isValid() const {
        std::string romanCopy = roman;

        for (const auto& pair : invalidPairs) {
            const std::string& invalidSubstr = pair.first;
            const std::string& validReplacement = pair.second;

            size_t pos = romanCopy.find(invalidSubstr);
            while (pos != std::string::npos) {
                romanCopy.replace(pos, invalidSubstr.length(), validReplacement);
                pos = romanCopy.find(invalidSubstr, pos + 1);
            }
        }

        return romanCopy == roman;
    }

private:
    static const std::unordered_map<char, int> romanToDecimalMap;
    static const std::unordered_map<int, std::string> decimalToRomanMap;
    static const std::unordered_map<std::string, std::string> invalidPairs;

    std::string roman;
};

const std::unordered_map<char, int> RomanNumber::romanToDecimalMap = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

const std::unordered_map<int, std::string> RomanNumber::decimalToRomanMap = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

const std::unordered_map<std::string, std::string> RomanNumber::invalidPairs = {
    {"IIII", "IV"},
    {"VV", "X"},
    {"XXXX", "XL"},
    {"LL", "C"},
    {"CCCC", "CD"},
    {"DD", "M"},
    {"MMMM", ""}
};

int main() {
    RomanNumber num1, num2;
    num1.input();
    num2.input();

    std::cout << std::endl;
    num1.display();
    num2.display();
    std::cout << std::endl;

    std::cout << "Num1 in decimal: " << num1.toDecimal() << std::endl;
    std::cout << "Num2 in decimal: " << num2.toDecimal() << std::endl;

    RomanNumber sum = num1 + num2;
    RomanNumber difference = num1 - num2;
    RomanNumber product = num1 * num2;
    RomanNumber quotient = num1 / num2;
    RomanNumber remainder = num1 % num2;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    difference.display();

    std::cout << "Product: ";
    product.display();

    std::cout << "Quotient: ";
    quotient.display();

    std::cout << "Remainder: ";
    remainder.display();

    bool isValid1 = num1.isValid();
    std::cout << "Num1 is " << (isValid1 ? "valid" : "invalid") << std::endl;

    bool isValid2 = num2.isValid();
    std::cout << "Num2 is " << (isValid2 ? "valid" : "invalid") << std::endl;

    return 0;
}
