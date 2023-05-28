//На диаграмме показан базовый класс Shape (Фигура), а также его классы-наследники: 
//Circle (Круг), Triangle (Треугольник), Square (Квадрат) и Rectangle (Прямоугольник).

//Базовый класс Shape определяет общие свойства и методы для всех геометрических фигур. 
//У него есть приватное поле color для хранения цвета фигуры. 
//Он также предоставляет публичные методы для установки цвета (setColor(color: string)) и получения цвета (getColor(): string), 
//а также методы для вычисления площади (calculateArea(): double) и периметра (calculatePerimeter(): double).

//Классы-наследники (Circle, Triangle, Square, Rectangle) наследуют от базового класса Shape и добавляют специфические свойства и методы для каждой фигуры.


-------------------------
|      Shape            |
-------------------------
| - color: string       |
-------------------------
| + setColor(color:     |
|              string)  |
| + getColor(): string  |
| + calculateArea():    |
|          double       |
| + calculatePerimeter(): |
|            double     |
-------------------------
           ^
           |
-------------------------
|      Circle           |
-------------------------
| - radius: double      |
-------------------------
| + setRadius(radius:   |
|             double)   |
| + getRadius(): double |
| + calculateArea():    |
|          double       |
| + calculatePerimeter(): |
|            double     |
-------------------------
           ^
           |
-------------------------
|    Triangle           |
-------------------------
| - sideA: double       |
| - sideB: double       |
| - sideC: double       |
-------------------------
| + setSides(a: double, |
|            b: double, |
|            c: double) |
| + getSideA(): double  |
| + getSideB(): double  |
| + getSideC(): double  |
| + calculateArea():    |
|          double       |
| + calculatePerimeter(): |
|            double     |
-------------------------
           ^
           |
-------------------------
|    Square             |
-------------------------
| - side: double        |
-------------------------
| + setSide(side:       |
|           double)     |
| + getSide(): double   |
| + calculateArea():    |
|          double       |
| + calculatePerimeter(): |
|            double     |
-------------------------
           ^
           |
-------------------------
|    Rectangle          |
-------------------------
| - width: double       |
| - height: double      |
-------------------------
| + setDimensions(w:    |
|                double,|
|                h:    |
|                double)|
| + getWidth(): double  |
| + getHeight(): double |
| + calculateArea():    |
|          double       |
| + calculatePerimeter(): |
|            double     |
-------------------------
