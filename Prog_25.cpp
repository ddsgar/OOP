#include <iostream>

void sort(float arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 100;
    float numbers[size];
    float num;
    int count = 0;

    std::cout << "Enter numbers (enter -1 to stop):" << std::endl;

    while (true) {
        std::cin >> num;

        if (num == -1)
            break;

        numbers[count] = num;
        count++;

        if (count >= size)
            break;
    }

    sort(numbers, count);

    std::cout << "Sorted numbers: ";
    for (int i = 0; i < count; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
