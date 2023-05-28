//24.	Определить класс с именем Student, содержащий следующие поля: 
//фамилия иинициалы; номер группы; успеваемость (массив из пяти элементов). 
//Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа Student. 
//Написать программу, выполняющую следующие действия:
//− ввод с клавиатуры данных в массив, состоящий из десяти объектов типа Student
//(записи должны быть упорядочены по возрастанию номера группы);
//− вывод на дисплей фамилий и номеров групп для всех студентов, включенных в массив, 
//если средний балл студента больше 4 (если таких студентов нет, вывести соответствующее сообщение).
//Выполните рефакторинг программного кода.


#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    std::string group;
    double grades[5];

public:
    Student() {}

    Student(const std::string& name, const std::string& group, const double* grades) {
        this->name = name;
        this->group = group;
        for (int i = 0; i < 5; i++) {
            this->grades[i] = grades[i];
        }
    }

    std::string getName() const {
        return name;
    }

    std::string getGroup() const {
        return group;
    }

    double getAverageGrade() const {
        double sum = 0.0;
        for (int i = 0; i < 5; i++) {
            sum += grades[i];
        }
        return sum / 5;
    }

    friend std::istream& operator>>(std::istream& in, Student& student) {
        std::cout << "Enter name: ";
        std::getline(in >> std::ws, student.name);

        std::cout << "Enter group: ";
        std::getline(in >> std::ws, student.group);

        std::cout << "Enter grades (5 grades separated by spaces): ";
        for (int i = 0; i < 5; i++) {
            in >> student.grades[i];
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << "Name: " << student.name << std::endl;
        out << "Group: " << student.group << std::endl;
        out << "Grades: ";
        for (int i = 0; i < 5; i++) {
            out << student.grades[i] << " ";
        }
        out << std::endl;
        return out;
    }
};

int main() {
    const int SIZE = 10;
    Student students[SIZE];

    // Ввод данных студентов
    std::cout << "Enter data for " << SIZE << " students:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Student " << (i + 1) << ":" << std::endl;
        std::cin >> students[i];
    }

    // Сортировка по возрастанию номера группы
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (students[j].getGroup() > students[j + 1].getGroup()) {
                std::swap(students[j], students[j + 1]);
            }
        }
    }

    // Вывод фамилий и номеров групп для студентов с средним баллом > 4
    bool found = false;
    std::cout << "\nStudents with average grade > 4:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        if (students[i].getAverageGrade() > 4) {
            std::cout << students[i].getName() << " - " << students[i].getGroup() << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No students with average grade > 4 found." << std::endl;
    }

    return 0;
}
