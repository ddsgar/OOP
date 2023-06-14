//28.	Написать программу, реализующую игру «Крестики-нолики» между двумяигроками: 
//пользователь и компьютер (робот). В программе использовать контейнеры STL.

#include <iostream>
#include <vector>

enum class CellState { Empty, X, O };

class TicTacToe {
public:
    TicTacToe() : currentPlayer(CellState::X) {
        board.resize(3, std::vector<CellState>(3, CellState::Empty));
    }

    void play() {
        while (!isGameOver()) {
            if (currentPlayer == CellState::X) {
                playerMove();
            } else {
                computerMove();
            }

            currentPlayer = (currentPlayer == CellState::X) ? CellState::O : CellState::X;
            printBoard();
        }

        printResult();
    }

private:
    std::vector<std::vector<CellState>> board;
    CellState currentPlayer;

    void playerMove() {
        int row, col;
        std::cout << "Your turn. Enter the row and column (0-2): ";
        std::cin >> row >> col;

        if (isValidMove(row, col)) {
            board[row][col] = CellState::X;
        } else {
            std::cout << "Invalid move! Try again." << std::endl;
            playerMove();
        }
    }

    void computerMove() {
        std::cout << "Computer's turn:" << std::endl;

        int row, col;
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (!isValidMove(row, col));

        board[row][col] = CellState::O;
    }

    bool isValidMove(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == CellState::Empty);
    }

    bool isGameOver() {
        return (isBoardFull() || hasPlayerWon(CellState::X) || hasPlayerWon(CellState::O));
    }

    bool isBoardFull() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == CellState::Empty) {
                    return false;
                }
            }
        }
        return true;
    }

    bool hasPlayerWon(CellState player) {
        // Check rows
        for (int row = 0; row < 3; ++row) {
            if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
                return true;
            }
        }

        // Check columns
        for (int col = 0; col < 3; ++col) {
            if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }

        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }

        return false;
    }

    void printBoard() {
        std::cout << "Current Board:" << std::endl;
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == CellState::Empty) {
                    std::cout << "_ ";
                } else if (cell == CellState::X) {
                    std::cout << "X ";
                } else {
                    std::cout << "O ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printResult() {
        if (hasPlayerWon(CellState::X)) {
            std::cout << "Congratulations! You win!" << std::endl;
        } else if (hasPlayerWon(CellState::O)) {
            std::cout << "Computer wins!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }
    }
};

int main() {
    TicTacToe game;
    game.play();

    return 0;
}
