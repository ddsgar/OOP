#include <iostream>
#include <list>
#include <string>
#include <ctime>

struct File {
    std::string name;
    std::string creationDate;
    int accessCount;

    File(const std::string& n, const std::string& date) : name(n), creationDate(date), accessCount(0) {}
};

void initializeCatalog(std::list<File>& catalog) {
    catalog.push_back(File("file1.txt", "2022-01-01"));
    catalog.push_back(File("file2.txt", "2022-02-15"));
    catalog.push_back(File("file3.txt", "2022-03-10"));
    catalog.push_back(File("file4.txt", "2022-04-25"));
}

void printCatalog(const std::list<File>& catalog) {
    std::cout << "Catalog Files:" << std::endl;
    for (const File& file : catalog) {
        std::cout << "Name: " << file.name << ", Creation Date: " << file.creationDate << ", Access Count: " << file.accessCount << std::endl;
    }
}

void deleteFilesBeforeDate(std::list<File>& catalog, const std::string& date) {
    std::list<File>::iterator it = catalog.begin();
    while (it != catalog.end()) {
        if (it->creationDate < date) {
            it = catalog.erase(it);
        } else {
            ++it;
        }
    }
}

File* getFileWithMaxAccessCount(std::list<File>& catalog) {
    if (catalog.empty()) {
        return nullptr;
    }

    std::list<File>::iterator maxIt = catalog.begin();
    for (std::list<File>::iterator it = catalog.begin(); it != catalog.end(); ++it) {
        if (it->accessCount > maxIt->accessCount) {
            maxIt = it;
        }
    }

    return &(*maxIt);
}

int main() {
    std::list<File> catalog;

    initializeCatalog(catalog);

    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Print catalog" << std::endl;
        std::cout << "2. Delete files before date" << std::endl;
        std::cout << "3. Get file with max access count" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                printCatalog(catalog);
                break;
            case 2:
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::string date;
                std::cin >> date;
                deleteFilesBeforeDate(catalog, date);
                break;
            case 3:
                {
                    File* file = getFileWithMaxAccessCount(catalog);
                    if (file != nullptr) {
                        std::cout << "File with max access count: " << file->name << std::endl;
                    } else {
                        std::cout << "No files in the catalog." << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
