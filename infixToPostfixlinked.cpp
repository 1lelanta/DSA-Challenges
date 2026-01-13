#include <iostream>
#include <cctype>
using namespace std;

// Node for stack
struct Node {
    char data;
    Node* next;
};

// Global stack top
Node* top = NULL;

// Push operation
void push(char x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop operation
char pop() {
    if (top == NULL)
        return '\0';
    Node* temp = top;
    char x = temp->data;
    top = top->next;
    delete temp;
    return x;
}

// Peek operation
char peek() {
    if (top == NULL)
        return '\0';
    return top->data;
}

// Precedence function
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Operand goes directly to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // Left parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // Right parenthesis
        else if (ch == ')') {
            while (top != NULL && peek() != '(') {
                postfix += pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != NULL && precedence(peek()) >= precedence(ch)) {
                postfix += pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != NULL) {
        postfix += pop();
    }

    cout << "Postfix expression: " << postfix << endl;
}

// Main function
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix);

    return 0;
}
