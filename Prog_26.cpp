#include <iostream>
#include <string>

void sortArray(std::string arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int MAX_SIZE = 100;
    std::string words[MAX_SIZE];
    int count = 0;
    std::string word;

    std::cout << "Enter words (enter 'done' to stop):" << std::endl;

    while (true) {
        std::cin >> word;

        if (word == "done")
            break;

        words[count] = word;
        count++;

        if (count == MAX_SIZE)
            break;
    }

    sortArray(words, count);

    std::cout << "Sorted words: ";
    for (int i = 0; i < count; ++i) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
