//32.	Написать программу «Англо-русский и русско-английский словарь». 
//«База данных»словаря должна содержать синонимичные варианты перевода слов. 
//Следует обеспечить выбор с помощью меню и выполнение следующих функций:
//− загрузка «базы данных» словаря (из файла);
//− выбор режима работы: англо-русский или русско-английский;
//− вывод вариантов перевода заданного английского слова; − вывод вариантов перевода заданного русского слова.
//Базу данных словаря реализовать в виде двух контейнеров типа map.


#include <iostream>
#include <fstream>
#include <string>
#include <map>

void loadDictionary(std::map<std::string, std::string>& engToRus,
                    std::map<std::string, std::string>& rusToEng) {
    std::ifstream file("dictionary.txt");
    if (!file) {
        std::cout << "Failed to open dictionary file." << std::endl;
        return;
    }

    std::string engWord, rusWord;
    while (file >> engWord >> rusWord) {
        engToRus[engWord] = rusWord;
        rusToEng[rusWord] = engWord;
    }

    file.close();
    std::cout << "Dictionary loaded successfully." << std::endl;
}

void translateEnglishWord(const std::map<std::string, std::string>& engToRus) {
    std::string word;
    std::cout << "Enter an English word: ";
    std::cin >> word;

    auto it = engToRus.find(word);
    if (it != engToRus.end()) {
        std::cout << "Translation(s) of " << word << ": " << it->second << std::endl;
    } else {
        std::cout << "Translation not found." << std::endl;
    }
}

void translateRussianWord(const std::map<std::string, std::string>& rusToEng) {
    std::string word;
    std::cout << "Enter a Russian word: ";
    std::cin >> word;

    auto it = rusToEng.find(word);
    if (it != rusToEng.end()) {
        std::cout << "Translation(s) of " << word << ": " << it->second << std::endl;
    } else {
        std::cout << "Translation not found." << std::endl;
    }
}

int main() {
    std::map<std::string, std::string> engToRus;
    std::map<std::string, std::string> rusToEng;

    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Load dictionary" << std::endl;
        std::cout << "2. English to Russian translation" << std::endl;
        std::cout << "3. Russian to English translation" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadDictionary(engToRus, rusToEng);
                break;
            case 2:
                translateEnglishWord(engToRus);
                break;
            case 3:
                translateRussianWord(rusToEng);
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
