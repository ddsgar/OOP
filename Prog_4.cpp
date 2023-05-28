//4.	Выполните объектно-ориентированный анализ предметной области домашнихживотных. Приведите пример полиморфизма.

// Абстрактный базовый класс для домашнего животного
class Pet {
public:
    virtual void makeSound() const = 0;
};

// Класс для собаки
class Dog : public Pet {
public:
    void makeSound() const override {
        cout << "Woof!" << endl;
    }
};

// Класс для кошки
class Cat : public Pet {
public:
    void makeSound() const override {
        cout << "Meow!" << endl;
    }
};

// Класс для хомяка
class Hamster : public Pet {
public:
    void makeSound() const override {
        cout << "Squeak!" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    Hamster hamster;

    Pet* pet1 = &dog;
    Pet* pet2 = &cat;
    Pet* pet3 = &hamster;

    pet1->makeSound(); // Вывод: "Woof!"
    pet2->makeSound(); // Вывод: "Meow!"
    pet3->makeSound(); // Вывод: "Squeak!"

    return 0;
}

