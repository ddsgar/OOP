#include <iostream>
#include <string>
#include <cmath>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(1970) {}

    void input() {
        std::cout << "Enter date (dd mm yyyy): ";
        std::cin >> day >> month >> year;
    }

    void displayFormat1() const {
        std::cout << day << "." << month << "." << year << std::endl;
    }

    void displayFormat2() const {
        std::string monthName;
        switch (month) {
            case 1:
                monthName = "января";
                break;
            case 2:
                monthName = "февраля";
                break;
            case 3:
                monthName = "марта";
                break;
            case 4:
                monthName = "апреля";
                break;
            case 5:
                monthName = "мая";
                break;
            case 6:
                monthName = "июня";
                break;
            case 7:
                monthName = "июля";
                break;
            case 8:
                monthName = "августа";
                break;
            case 9:
                monthName = "сентября";
                break;
            case 10:
                monthName = "октября";
                break;
            case 11:
                monthName = "ноября";
                break;
            case 12:
                monthName = "декабря";
                break;
            default:
                monthName = "Unknown";
        }

        std::cout << day << " " << monthName << " " << year << std::endl;
    }

    void displayFormat3() const {
        std::string dayStr = (day < 10) ? "0" + std::to_string(day) : std::to_string(day);
        std::string monthStr = (month < 10) ? "0" + std::to_string(month) : std::to_string(month);
        std::string yearStr = std::to_string(year).substr(2);

        std::cout << dayStr << "." << monthStr << "." << yearStr << std::endl;
    }

    int calculateDistance(const Date& other) const {
        // Расчет расстояния между датами в днях
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int days1 = day;
        for (int m = 1; m < month; ++m) {
            days1 += daysInMonth[m - 1];
        }
        days1 += 365 * (year - 1) + std::floor((year - 1) / 4) - std::floor((year - 1) / 100) + std::floor((year - 1) / 400);

        int days2 = other.day;
        for (int m = 1; m < other.month; ++m) {
            days2 += daysInMonth[m - 1];
        }
        days2 += 365 * (other.year - 1) + std::floor((other.year - 1) / 4) - std::floor((other.year - 1) / 100) + std::floor((other.year - 1) / 400);

        return std::abs(days2 - days1);
    }

    int calculateWeekday() const {
        // Расчет дня недели для заданной даты
        int d = day;
        int m = month;
        int y = year;

        if (m < 3) {
            m += 12;
            y--;
        }

        int h = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;

        // Переводим результат в формат, где понедельник - 1, воскресенье - 7
        if (h == 0) {
            h = 7;
        }

        return h;
    }

    bool isValid() const {
        // Проверка корректности заданной даты
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > getDaysInMonth(month, year)) {
            return false;
        }

        return true;
    }

private:
    bool isLeapYear(int year) const {
        if (year % 4 != 0) {
            return false;
        } else if (year % 100 != 0) {
            return true;
        } else if (year % 400 != 0) {
            return false;
        } else {
            return true;
        }
    }

    int getDaysInMonth(int month, int year) const {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2 && isLeapYear(year)) {
            return 29;
        } else {
            return daysInMonth[month - 1];
        }
    }
};

int main() {
    Date date1, date2;

    std::cout << "Enter date 1:" << std::endl;
    date1.input();

    std::cout << "Enter date 2:" << std::endl;
    date2.input();

    std::cout << "Date 1 in format 1: ";
    date1.displayFormat1();

    std::cout << "Date 1 in format 2: ";
    date1.displayFormat2();

    std::cout << "Date 1 in format 3: ";
    date1.displayFormat3();

    std::cout << "Date 2 in format 1: ";
    date2.displayFormat1();

    std::cout << "Date 2 in format 2: ";
    date2.displayFormat2();

    std::cout << "Date 2 in format 3: ";
    date2.displayFormat3();

    int distance = date1.calculateDistance(date2);
    std::cout << "Distance between dates: " << distance << " days" << std::endl;

    int weekday = date1.calculateWeekday();
    std::cout << "Weekday of date 1: " << weekday << std::endl;

    bool isValid1 = date1.isValid();
    std::cout << "Date 1 is " << (isValid1 ? "valid" : "invalid") << std::endl;

    bool isValid2 = date2.isValid();
    std::cout << "Date 2 is " << (isValid2 ? "valid" : "invalid") << std::endl;

    return 0;
}
