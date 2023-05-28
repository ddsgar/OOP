//23.	Представьте себе издательскую компанию, которая торгует книгами и аудиозаписями этих книг. 
//Создайте класс publication, в котором хранятся название и цена книги. От этого класса наследуются еще два класса: 
//book, который содержит информацию о количестве страниц в книге, и type, который содержит время записи книги в минутах. 
//В каждом из этих трех классов должен быть метод getdata(), через который можно получать данные от пользователя с клавиатуры, и putdata(), 
//предназначенный для вывода этих данных.
//Напишите функцию main() программы для проверки классов book и type. 
//Создайте их объекты в программе и запросите пользователя ввести и вывести данные с использованием методов getdata() и putdata().
//Выполните рефакторинг программного кода.


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
