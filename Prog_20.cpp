#include <iostream>

template<typename T>
T calculateAverage(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    int intArrSize = sizeof(intArr) / sizeof(int);
    int intAverage = calculateAverage(intArr, intArrSize);
    std::cout << "Average of int array: " << intAverage << std::endl;

    long longArr[] = {1000, 2000, 3000, 4000, 5000};
    int longArrSize = sizeof(longArr) / sizeof(long);
    long longAverage = calculateAverage(longArr, longArrSize);
    std::cout << "Average of long array: " << longAverage << std::endl;

    double doubleArr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int doubleArrSize = sizeof(doubleArr) / sizeof(double);
    double doubleAverage = calculateAverage(doubleArr, doubleArrSize);
    std::cout << "Average of double array: " << doubleAverage << std::endl;

    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    int charArrSize = sizeof(charArr) / sizeof(char);
    char charAverage = calculateAverage(charArr, charArrSize);
    std::cout << "Average of char array: " << charAverage << std::endl;

    return 0;
}
