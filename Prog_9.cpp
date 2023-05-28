//9.	Построить систему классов для описания плоских геометрических фигур: круг,квадрат, прямоугольник. 
//Предусмотреть методы для создания объектов, перемещения на плоскости, 
//изменения размеров и вращения на заданный угол. Написать программу, демонстрирующую работу с этими классами. 
//Программа должна содержать меню, позволяющее осуществить проверку всех методов классов.

#include <iostream>
#include <cmath>

using namespace std;

class Shape {
protected:
    double x, y; // Координаты центра фигуры

public:
    Shape(double _x, double _y) : x(_x), y(_y) {}

    virtual void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    virtual void resize(double factor) = 0;
    virtual void rotate(double angle) = 0;

    virtual void display() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double _x, double _y, double _radius) : Shape(_x, _y), radius(_radius) {}

    void resize(double factor) override {
        radius *= factor;
    }

    void rotate(double angle) override {
        // Круг не вращается
    }

    void display() const override {
        cout << "Circle: Center(" << x << ", " << y << "), Radius: " << radius << endl;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double _x, double _y, double _side) : Shape(_x, _y), side(_side) {}

    void resize(double factor) override {
        side *= factor;
    }

    void rotate(double angle) override {
        // Квадрат не вращается
    }

    void display() const override {
        cout << "Square: Center(" << x << ", " << y << "), Side: " << side << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double _x, double _y, double _width, double _height) : Shape(_x, _y), width(_width), height(_height) {}

    void resize(double factor) override {
        width *= factor;
        height *= factor;
    }

    void rotate(double angle) override {
        double radians = angle * M_PI / 180.0;
        double newX = x * cos(radians) - y * sin(radians);
        double newY = x * sin(radians) + y * cos(radians);
        x = newX;
        y = newY;
    }

    void display() const override {
        cout << "Rectangle: Center(" << x << ", " << y << "), Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(0, 0, 5);
    shapes[1] = new Square(2, 3, 4);
    shapes[2] = new Rectangle(-1, 2, 3, 6);

    int choice;
    do {
        cout << "1. Move\n2. Resize\n3. Rotate\n4. Display\n0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double dx, dy;
                cout << "Enter the amount to move in x-direction: ";
                cin >> dx;
                cout << "Enter the amount to move in y-direction: ";
                cin >> dy;

                for (int i = 0; i < 3; i++) {
                    shapes[i]->move(dx, dy);
                }
                cout << "Shapes moved successfully." << endl;
                break;
            }
            case 2: {
                double factor;
                cout << "Enter the resizing factor: ";
                cin >> factor;

                for (int i = 0; i < 3; i++) {
                    shapes[i]->resize(factor);
                }
                cout << "Shapes resized successfully." << endl;
                break;
            }
            case 3: {
                double angle;
                cout << "Enter the angle of rotation: ";
                cin >> angle;

                for (int i = 0; i < 3; i++) {
                    shapes[i]->rotate(angle);
                }
                cout << "Shapes rotated successfully." << endl;
                break;
            }
            case 4: {
                for (int i = 0; i < 3; i++) {
                    shapes[i]->display();
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
