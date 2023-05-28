#include <iostream>
#include <stdexcept>

const int MAX_SIZE = 100;

class Stack {
public:
    Stack() : size(0) {}

    void push(int element) {
        if (size >= MAX_SIZE) {
            throw std::overflow_error("Stack is full");
        }

        data[size++] = element;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }

        --size;
    }

    int top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }

        return data[size - 1];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == MAX_SIZE;
    }

    int getSize() const {
        return size;
    }

    Stack operator+(int element) {
        push(element);
        return *this;
    }

    Stack operator-(int element) {
        pop();
        return *this;
    }

private:
    int data[MAX_SIZE];
    int size;
};

int main() {
    Stack stack;

    std::cout << "Pushing elements into the stack..." << std::endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack size: " << stack.getSize() << std::endl;

    std::cout << "Top element: " << stack.top() << std::endl;

    std::cout << "Popping an element from the stack..." << std::endl;
    stack.pop();

    std::cout << "Stack size: " << stack.getSize() << std::endl;

    std::cout << "Adding an element to the stack using operator+" << std::endl;
    stack = stack + 40;
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    std::cout << "Removing an element from the stack using operator-" << std::endl;
    stack = stack - 40;
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    return 0;
}
