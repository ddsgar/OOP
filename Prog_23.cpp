#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    double price;

public:
    void getData() {
        std::cout << "Enter title: ";
        std::getline(std::cin >> std::ws, title);

        std::cout << "Enter price: ";
        std::cin >> price;
    }

    void putData() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getData() {
        Publication::getData();

        std::cout << "Enter page count: ";
        std::cin >> pageCount;
    }

    void putData() const {
        Publication::putData();
        std::cout << "Page Count: " << pageCount << std::endl;
    }
};

class Type : public Publication {
private:
    int recordingTime;

public:
    void getData() {
        Publication::getData();

        std::cout << "Enter recording time (minutes): ";
        std::cin >> recordingTime;
    }

    void putData() const {
        Publication::putData();
        std::cout << "Recording Time: " << recordingTime << " minutes" << std::endl;
    }
};

int main() {
    Book book;
    Type type;

    std::cout << "Enter book details: " << std::endl;
    book.getData();

    std::cout << "\nEnter type details: " << std::endl;
    type.getData();

    std::cout << "\nBook details:" << std::endl;
    book.putData();

    std::cout << "\nType details:" << std::endl;
    type.putData();

    return 0;
}
