// Класс "Студент"
class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {}
    // Другие методы класса
};

// Класс "Группа студентов"
class StudentGroup {
private:
    vector<Student> students; // Агрегация: объекты класса Student являются частью класса StudentGroup

public:
    void addStudent(const Student& student) {
        students.push_back(student); // Добавление студента в группу
    }
    // Другие методы класса
};

-------------------------
|      Student          |
-------------------------
| - name: string        |
| - age: int            |
-------------------------
| + Student(n: string,  |
|            a: int)    |
|                      |
-------------------------

-------------------------
|     StudentGroup      |
-------------------------
| - students: vector<   |
|              Student>  |
-------------------------
| + addStudent(student: |
|                 const |
|                 Student&) |
|                      |
-------------------------
