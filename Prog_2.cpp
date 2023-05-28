// Абстрактный базовый класс для шахматной фигуры
class ChessPiece {
public:
    virtual void move() const = 0;
};

// Класс для пешки
class Pawn : public ChessPiece {
public:
    void move() const override {
        // Логика для хода пешки
        cout << "Pawn moves forward" << endl;
    }
};

// Класс для ладьи
class Rook : public ChessPiece {
public:
    void move() const override {
        // Логика для хода ладьи
        cout << "Rook moves horizontally or vertically" << endl;
    }
};

// Класс для коня
class Knight : public ChessPiece {
public:
    void move() const override {
        // Логика для хода коня
        cout << "Knight moves in an L-shape" << endl;
    }
};

// Класс для слона
class Bishop : public ChessPiece {
public:
    void move() const override {
        // Логика для хода слона
        cout << "Bishop moves diagonally" << endl;
    }
};

// Класс для ферзя
class Queen : public ChessPiece {
public:
    void move() const override {
        // Логика для хода ферзя
        cout << "Queen moves horizontally, vertically or diagonally" << endl;
    }
};

// Класс для короля
class King : public ChessPiece {
public:
    void move() const override {
        // Логика для хода короля
        cout << "King moves one square in any direction" << endl;
    }
};

int main() {
    Pawn pawn;
    Rook rook;
    Knight knight;

    pawn.move();   // Вывод: "Pawn moves forward"
    rook.move();   // Вывод: "Rook moves horizontally or vertically"
    knight.move(); // Вывод: "Knight moves in an L-shape"

    return
