#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Book {
    std::string author;
    std::string title;
    int year;
    int quantity;

    Book(const std::string& a, const std::string& t, int y, int q)
        : author(a), title(t), year(y), quantity(q) {}
};

void addBook(std::vector<Book>& library) {
    std::string author, title;
    int year, quantity;

    std::cout << "Enter author: ";
    std::cin.ignore();
    std::getline(std::cin, author);

    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    std::cout << "Enter year: ";
    std::cin >> year;

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    library.push_back(Book(author, title, year, quantity));
    std::cout << "Book added to the library." << std::endl;
}

void removeBook(std::vector<Book>& library) {
    std::string title;

    std::cout << "Enter title of the book to remove: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    auto it = std::find_if(library.begin(), library.end(), [&title](const Book& book) {
        return book.title == title;
    });

    if (it != library.end()) {
        library.erase(it);
        std::cout << "Book removed from the library." << std::endl;
    } else {
        std::cout << "Book not found in the library." << std::endl;
    }
}

bool sortByAuthor(const Book& book1, const Book& book2) {
    return book1.author < book2.author;
}

bool sortByYear(const Book& book1, const Book& book2) {
    return book1.year < book2.year;
}

void printBooksByAuthor(const std::vector<Book>& library) {
    std::vector<Book> sortedLibrary(library);
    std::sort(sortedLibrary.begin(), sortedLibrary.end(), sortByAuthor);

    std::cout << "Books sorted by author:" << std::endl;
    for (const Book& book : sortedLibrary) {
        std::cout << "Author: " << book.author << ", Title: " << book.title << ", Year: " << book.year
                  << ", Quantity: " << book.quantity << std::endl;
    }
}

void printBooksByYear(const std::vector<Book>& library) {
    std::vector<Book> sortedLibrary(library);
    std::sort(sortedLibrary.begin(), sortedLibrary.end(), sortByYear);

    std::cout << "Books sorted by year:" << std::endl;
    for (const Book& book : sortedLibrary) {
        std::cout << "Author: " << book.author << ", Title: " << book.title << ", Year: " << book.year
                  << ", Quantity: " << book.quantity << std::endl;
    }
}

int main() {
    std::vector<Book> library;

    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add book" << std::endl;
        std::cout << "2. Remove book" << std::endl;
        std::cout << "3. Print books by author" << std::endl;
        std::cout << "4. Print books by year" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                removeBook(library);
                break;
            case 3:
                printBooksByAuthor(library);
                break;
            case 4:
                printBooksByYear(library);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
