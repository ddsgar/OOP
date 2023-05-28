// Класс "Двигатель"
class Engine {
public:
    void start() {
        // Логика запуска двигателя
    }
};

// Класс "Машина"
class Car {
private:
    Engine engine; // Композиция: объект класса Engine является частью класса Car

public:
    void startCar() {
        engine.start(); // Используем объект класса Engine
        // Логика запуска автомобиля
    }
};

-------------------------
|         Car           |
-------------------------
|     - engine: Engine  |
-------------------------
| + startCar()          |
-------------------------

-------------------------
|        Engine         |
-------------------------
| + start()             |
-------------------------
