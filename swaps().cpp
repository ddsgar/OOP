//21.	Создайте функцию swaps(), обменивающую значения двух аргументов, посылаемыхей. 
//Сделайте из функции шаблон, чтобы она могла использоваться с любыми числовыми 
//типами данных (int, char, float и т. д.). В main() проверьте работу функции с массивами разных типов.

#include <iostream>

template<typename T>
void swaps(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int intA = 10, intB = 20;
    std::cout << "Before swap: intA = " << intA << ", intB = " << intB << std::endl;
    swaps(intA, intB);
    std::cout << "After swap: intA = " << intA << ", intB = " << intB << std::endl;

    char charA = 'A', charB = 'B';
    std::cout << "Before swap: charA = " << charA << ", charB = " << charB << std::endl;
    swaps(charA, charB);
    std::cout << "After swap: charA = " << charA << ", charB = " << charB << std::endl;

    float floatA = 3.14, floatB = 2.71;
    std::cout << "Before swap: floatA = " << floatA << ", floatB = " << floatB << std::endl;
    swaps(floatA, floatB);
    std::cout << "After swap: floatA = " << floatA << ", floatB = " << floatB << std::endl;

    return 0;
}
