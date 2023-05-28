#include <iostream>
#include <fstream>
#include <stack>
#include <string>

class Stack {
public:
    bool isEmpty() const {
        return elements.empty();
    }

    bool isFull() const {
        // Assuming the stack has unlimited capacity
        return false;
    }

    int size() const {
        return elements.size();
    }

    void push(char element) {
        elements.push(element);
    }

    char pop() {
        char topElement = elements.top();
        elements.pop();
        return topElement;
    }

private:
    std::stack<char> elements;
};

bool isBalanced(const std::string& text) {
    Stack stack;
    
    for (char c : text) {
        if (c == '(' || c == '<') {
            stack.push(c);
        } else if (c == ')' || c == '>') {
            if (stack.isEmpty()) {
                return false;
            }
            char topElement = stack.pop();
            if ((c == ')' && topElement != '(') || (c == '>' && topElement != '<')) {
                return false;
            }
        }
    }
    
    return stack.isEmpty();
}

int main() {
    std::string filename = "text.txt";
    std::ifstream file(filename);
    
    if (!file) {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }
    
    std::string text;
    std::string line;
    while (getline(file, line)) {
        text += line;
    }
    
    file.close();
    
    bool balanced = isBalanced(text);
    if (balanced) {
        std::cout << "The text in the file is balanced." << std::endl;
    } else {
        std::cout << "The text in the file is not balanced." << std::endl;
    }
    
    return 0;
}
