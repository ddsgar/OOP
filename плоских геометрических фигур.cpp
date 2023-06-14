//1.	Выполните объектно-ориентированный анализ предметной области плоскихгеометрических фигур. Приведите пример абстракции данных.

// Абстрактный базовый класс для плоской геометрической фигуры
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// Класс для круга
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

// Класс для прямоугольника
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};

// Класс для треугольника
class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double area() const override {
        // Используем формулу Герона для вычисления площади треугольника
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle

