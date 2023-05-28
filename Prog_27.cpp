//27.	Заполните массив четными числами, а множество – нечетными. 
//С помощьюалгоритма merge() объедините эти контейнеры в вектор. 
//Выведите его содержимое, чтобы удостовериться, что слияние прошло успешно.

#include <iostream>

const int SIZE = 10;

void mergeArrays(const int* arr1, const int* arr2, int* mergedArr) {
    int i = 0, j = 0, k = 0;
    
    while (i < SIZE && j < SIZE) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }
    
    while (i < SIZE) {
        mergedArr[k++] = arr1[i++];
    }
    
    while (j < SIZE) {
        mergedArr[k++] = arr2[j++];
    }
}

int main() {
    int evenArray[SIZE];
    int oddSet[SIZE];
    int mergedArray[2 * SIZE];
    
    // Заполняем массив четными числами
    for (int i = 0; i < SIZE; ++i) {
        evenArray[i] = 2 * (i + 1);
    }

    // Заполняем множество нечетными числами
    for (int i = 0; i < SIZE; ++i) {
        oddSet[i] = 2 * i + 1;
    }
    
    // Объединяем массив и множество в массив mergedArray
    mergeArrays(evenArray, oddSet, mergedArray);
    
    // Выводим содержимое mergedArray
    std::cout << "Merged Array: ";
    for (int i = 0; i < 2 * SIZE; ++i) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
