#include <iostream>
#include <stack>
#include <vector>

struct Coordinate {
    int row;
    int col;

    Coordinate(int r, int c) : row(r), col(c) {}
};

bool isValidMove(const std::vector<std::vector<bool>>& maze, int row, int col) {
    int numRows = maze.size();
    int numCols = maze[0].size();

    return (row >= 0 && row < numRows && col >= 0 && col < numCols && maze[row][col]);
}

std::vector<Coordinate> findPath(const std::vector<std::vector<bool>>& maze, const Coordinate& start) {
    int numRows = maze.size();
    int numCols = maze[0].size();
    std::vector<std::vector<bool>> visited(numRows, std::vector<bool>(numCols, false));

    std::stack<Coordinate> stack;
    stack.push(start);

    std::vector<Coordinate> path;

    while (!stack.empty()) {
        Coordinate current = stack.top();
        stack.pop();

        if (visited[current.row][current.col]) {
            continue;
        }

        visited[current.row][current.col] = true;

        // Check if we have reached the exit
        if (current.row == 0 || current.row == numRows - 1 || current.col == 0 || current.col == numCols - 1) {
            path.push_back(current);
            break;
        }

        // Add valid neighboring squares to the stack
        if (isValidMove(maze, current.row - 1, current.col)) {
            stack.push(Coordinate(current.row - 1, current.col));
        }
        if (isValidMove(maze, current.row + 1, current.col)) {
            stack.push(Coordinate(current.row + 1, current.col));
        }
        if (isValidMove(maze, current.row, current.col - 1)) {
            stack.push(Coordinate(current.row, current.col - 1));
        }
        if (isValidMove(maze, current.row, current.col + 1)) {
            stack.push(Coordinate(current.row, current.col + 1));
        }
    }

    // Construct the path from the stack
    while (!stack.empty()) {
        path.push_back(stack.top());
        stack.pop();
    }

    return path;
}

int main() {
    // Example maze
    std::vector<std::vector<bool>> maze = {
        {true, false, true, true, true},
        {true, false, true, false, true},
        {true, true, true, false, true},
        {false, false, false, false, true},
        {true, true, true, true, true}
    };

    Coordinate start(4, 0);

    std::vector<Coordinate> path = findPath(maze, start);

    if (!path.empty()) {
        std::cout << "Path found:" << std::endl;
        for (const Coordinate& coordinate : path) {
            std::cout << "(" << coordinate.row << ", " << coordinate.col << ")" << std::endl;
        }
    } else {
        std::cout << "No path found." << std::endl;
    }

    return 0;
}
