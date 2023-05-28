#include <iostream>
#include <vector>

using namespace std;

class ChessPiece {
protected:
    int x; // позиция по горизонтали
    int y; // позиция по вертикали

public:
    ChessPiece(int _x, int _y) : x(_x), y(_y) {}

    virtual bool isCheckmate() const {
        return false;
    }

    virtual void move(int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }

    virtual void display() const = 0;
};

class King : public ChessPiece {
public:
    King(int x, int y) : ChessPiece(x, y) {}

    bool isCheckmate() const override {
        // Проверка на мат короля
        // Реализация опущена для простоты примера
        return false;
    }

    void display() const override {
        cout << "King: Position(" << x << ", " << y << ")" << endl;
    }
};

class Queen : public ChessPiece {
public:
    Queen(int x, int y) : ChessPiece(x, y) {}

    void display() const override {
        cout << "Queen: Position(" << x << ", " << y << ")" << endl;
    }
};

class Rook : public ChessPiece {
public:
    Rook(int x, int y) : ChessPiece(x, y) {}

    void display() const override {
        cout << "Rook: Position(" << x << ", " << y << ")" << endl;
    }
};

class Bishop : public ChessPiece {
public:
    Bishop(int x, int y) : ChessPiece(x, y) {}

    void display() const override {
        cout << "Bishop: Position(" << x << ", " << y << ")" << endl;
    }
};

class Knight : public ChessPiece {
public:
    Knight(int x, int y) : ChessPiece(x, y) {}

    void display() const override {
        cout << "Knight: Position(" << x << ", " << y << ")" << endl;
    }
};

class Pawn : public ChessPiece {
public:
    Pawn(int x, int y) : ChessPiece(x, y) {}

    void display() const override {
        cout << "Pawn: Position(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    vector<ChessPiece*> chessPieces;

    // Создание шахматных фигур
    chessPieces.push_back(new King(5, 1));
    chessPieces.push_back(new Queen(4, 2));
    chessPieces.push_back(new Rook(1, 1));
    chessPieces.push_back(new Bishop(3, 3));
    chessPieces.push_back(new Knight(6, 4));
    chessPieces.push_back(new Pawn(2, 2));

    // Проверка на мат одного из королей
    bool isCheckmate = false;
    for (const auto& piece : chessPieces) {
        if (piece->isCheckmate()) {
            isCheckmate = true;
            break;
        }
    }

    // Вывод информации о шахматных фигурах
    for (const auto& piece : chessPieces) {
        piece->display();
    }

    if (isCheckmate) {
        cout << "One of the kings is in checkmate!" << endl;
    } else {
        cout << "No kings are in checkmate." << endl;
    }

    // Освобождение памяти
    for (const auto& piece : chessPieces) {
        delete piece;
    }

    return 0;
}
