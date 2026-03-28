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

    for (int i = 0; i < line.length(); i++) {
        char c = line[i];

        if (isspace(c)) {
            continue;
        }
        if (isdigit(c)) {
            string num;
            while (i < line.length () && isdigit(line[i])) {
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

bool isNumber (const string& s) {
    return isdigit(s[0]);
}

int precedence(const string& op) {

    if (isOperator(op)) {
        if (op == "+" || op == "-") {
            return 1;
        }
        else if (op == "*" || op == "/") {
            return 2;
        }
    }
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {

    bool expectOperand = true;
    int parenBalance = 0;

    if (!tokens.empty()) {

        for (const auto& t : tokens) {
            if (t.value == "(") {
                parenBalance++;
            }
            if (t.value == ")") {
                parenBalance--;
            }
            if ( isNumber(t.value)) {
                expectOperand = false;
            }
            if (isOperator(t.value)) {
                expectOperand = true;
            }

            if (parenBalance == 0 && expectOperand == false) {
                return true;
            }

            if (parenBalance == 1 || expectOperand == true) {
                return false;
            }
        }
    }
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    return false;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    return 0.0;
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
        for (const auto& t : postfix) {
            cout << t.value << " ";
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
