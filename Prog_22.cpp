//22.	Создайте функцию amax(), возвращающую значение максимального элементамассива. 
//Аргументами функции должны быть адрес и размер массива. 
//Сделайте из функции шаблон, чтобы она могла работать с массивом любого числового типа. 
//В main() проверьте работу функции с массивами разных типов.

#include <iostream>

template<typename T>
T amax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int intArr[] = {5, 2, 8, 1, 9};
    int intSize = sizeof(intArr) / sizeof(int);
    std::cout << "Max value in intArr: " << amax(intArr, intSize) << std::endl;

    double doubleArr[] = {3.14, 1.23, 2.78, 0.99};
    int doubleSize = sizeof(doubleArr) / sizeof(double);
    std::cout << "Max value in doubleArr: " << amax(doubleArr, doubleSize) << std::endl;

    char charArr[] = {'A', 'C', 'B', 'E'};
    int charSize = sizeof(charArr) / sizeof(char);
    std::cout << "Max value in charArr: " << amax(charArr, charSize) << std::endl;

    return 0;
}
