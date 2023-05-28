//3.	Выполните объектно-ориентированный анализ предметной области комплексныхчисел. Приведите пример инкапсуляции.

// Класс для комплексного числа
class ComplexNumber {
private:
    double real;    // Действительная часть
    double imaginary;   // Мнимая часть

public:
    // Конструктор
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Методы доступа (геттеры) для чтения значений частей комплексного числа
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // Методы для выполнения операций над комплексными числами
    ComplexNumber add(const ComplexNumber& other) const {
        double newReal = real + other.real;
        double newImaginary = imaginary + other.imaginary;
        return ComplexNumber(newReal, newImaginary);
    }

    ComplexNumber subtract(const ComplexNumber& other) const {
        double newReal = real - other.real;
        double newImaginary = imaginary - other.imaginary;
        return ComplexNumber(newReal, newImaginary);
    }

    ComplexNumber multiply(const ComplexNumber& other) const {
        double newReal = (real * other.real) - (imaginary * other.imaginary);
        double newImaginary = (real * other.imaginary) + (imaginary * other.real);
        return ComplexNumber(newReal, newImaginary);
    }
};

int main() {
    ComplexNumber c1(2.0, 3.0);
    ComplexNumber c2(1.0, 4.0);

    ComplexNumber sum = c1.add(c2);
    ComplexNumber difference = c1.subtract(c2);
    ComplexNumber product = c1.multiply(c2);

    cout << "Sum: " << sum.getReal() << " + " << sum.getImaginary() << "i" << endl;
    cout << "Difference: " << difference.getReal() <<
