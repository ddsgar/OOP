#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int _hours, int _minutes, int _seconds) : hours(_hours), minutes(_minutes), seconds(_seconds) {}

    void display() const {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    Time addTime(const Time& t) const {
        Time result;
        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes + result.seconds / 60;
        result.hours = hours + t.hours + result.minutes / 60;

        result.seconds %= 60;
        result.minutes %= 60;
        result.hours %= 24;

        return result;
    }
};

int main() {
    Time t1(10, 30, 45);
    Time t2(4, 15, 20);
    Time t3;

    t3 = t1.addTime(t2);

    std::cout << "t1: ";
    t1.display();

    std::cout << "t2: ";
    t2.display();

    std::cout << "t3: ";
    t3.display();

    return 0;
}
