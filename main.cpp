#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;

    for (int i = 0; i < (int)line.length(); i++) {
        char c = line[i];

        if (isspace(c)) {
            continue;
        }
        if (isdigit(c)) {
            string num;
            while (i < (int)line.length() && isdigit(line[i])) {
                num += line[i];
                i++;
            }
            i--;
            tokens.push_back({num});
        }
        else {
            string s(1, c);
            tokens.push_back({s});
        }
    }
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

bool isNumber(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int precedence(const string& op) {
    if (op == "+" || op == "-") {
        return 1;
    }
    else if (op == "*" || op == "/") {
        return 2;
    }
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    if (tokens.empty()) {
        return false;
    }

    int count = 0;

    for (const auto& t : tokens) {
        if (isNumber(t.value)) {
            count++;
        }
        else if (isOperator(t.value)) {
            if (count < 2) {
                return false;
            }
            count--;
        }
        else {
            return false;
        }
    }

    return count == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    if (tokens.empty()) {
        return false;
    }

    bool expectOperand = true;
    int parenBalance = 0;

    for (const auto& t : tokens) {
        if (expectOperand) {
            if (isNumber(t.value)) {
                expectOperand = false;
            }
            else if (t.value == "(") {
                parenBalance++;
            }
            else {
                return false;
            }
        }
        else {
            if (isOperator(t.value)) {
                expectOperand = true;
            }
            else if (t.value == ")") {
                if (parenBalance == 0) {
                    return false;
                }
                parenBalance--;
            }
            else {
                return false;
            }
        }
    }

    return parenBalance == 0 && expectOperand == false;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    ArrayStack<Token> opstack;

    for (const auto& t : tokens) {
        if (isNumber(t.value)) {
            output.push_back(t);
        }
        else if (t.value == "(") {
            opstack.push(t);
        }
        else if (t.value == ")") {
            while (!opstack.empty() && opstack.top().value != "(") {
                output.push_back(opstack.top());
                opstack.pop();
            }
            if (!opstack.empty()) {
                opstack.pop();
            }
        }
        else if (isOperator(t.value)) {
            while (!opstack.empty() &&
                   isOperator(opstack.top().value) &&
                   precedence(opstack.top().value) >= precedence(t.value)) {
                output.push_back(opstack.top());
                opstack.pop();
            }
            opstack.push(t);
        }
    }

    while (!opstack.empty()) {
        output.push_back(opstack.top());
        opstack.pop();
    }

    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;

    for (const auto& t : tokens) {
        if (isNumber(t.value)) {
            stack.push(stod(t.value));
        }
        else if (isOperator(t.value)) {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            double result = 0.0;

            if (t.value == "+") result = a + b;
            else if (t.value == "-") result = a - b;
            else if (t.value == "*") result = a * b;
            else if (t.value == "/") result = a / b;

            stack.push(result);
        }
    }

    return stack.top();
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (int i = 0; i < (int)postfix.size(); i++) {
            cout << postfix[i].value;
            if (i < (int)postfix.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}
