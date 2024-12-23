#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum TokenType { INT, IDENTIFIER, NUMBER, ASSIGN, PLUS, MINUS, IF, EQUALS, LBRACE, RBRACE, SEMICOLON };

struct Token {
    TokenType type;
    std::string value;
};

class Parser {
public:
    Parser(const std::vector<Token> &tokens) : tokens(tokens), pos(0) {}

    void parse() {
        while (pos < tokens.size()) {
            if (tokens[pos].type == INT) {
                parseDeclaration();
            } else if (tokens[pos].type == IDENTIFIER) {
                parseAssignment();
            } else if (tokens[pos].type == IF) {
                parseConditional();
            } else {
                throw std::runtime_error("Unexpected token: " + tokens[pos].value);
            }
        }
    }

private:
    std::vector<Token> tokens;
    size_t pos;

    void parseDeclaration() {
        pos++;  // Skip 'int'
        if (tokens[pos].type == IDENTIFIER) {
            std::cout << "Declare variable: " << tokens[pos].value << std::endl;
            pos++;  // Skip variable name
            if (tokens[pos].type == SEMICOLON) {
                pos++;  // Skip semicolon
            } else {
                throw std::runtime_error("Expected ';' after declaration");
            }
        } else {
            throw std::runtime_error("Expected variable name after 'int'");
        }
    }

    void parseAssignment() {
        std::string var = tokens[pos].value;
        pos++;  // Skip variable name
        if (tokens[pos].type == ASSIGN) {
            pos++;  // Skip '='
            std::cout << "Assign to variable: " << var << std::endl;
            parseExpression();
            if (tokens[pos].type == SEMICOLON) {
                pos++;  // Skip semicolon
            } else {
                throw std::runtime_error("Expected ';' after assignment");
            }
        } else {
            throw std::runtime_error("Expected '=' after variable name");
        }
    }

    void parseExpression() {
        if (tokens[pos].type == NUMBER) {
            std::cout << "Number: " << tokens[pos].value << std::endl;
            pos++;
        } else if (tokens[pos].type == IDENTIFIER) {
            std::cout << "Variable: " << tokens[pos].value << std::endl;
            pos++;
        } else {
            throw std::runtime_error("Expected a number or variable in expression");
        }

        while (pos < tokens.size() && (tokens[pos].type == PLUS || tokens[pos].type == MINUS)) {
            std::cout << "Operator: " << tokens[pos].value << std::endl;
            pos++;
            if (tokens[pos].type == NUMBER) {
                std::cout << "Number: " << tokens[pos].value << std::endl;
                pos++;
            } else if (tokens[pos].type == IDENTIFIER) {
                std::cout << "Variable: " << tokens[pos].value << std::endl;
                pos++;
            } else {
                throw std::runtime_error("Expected a number or variable after operator");
            }
        }
    }

    void parseConditional() {
        pos++;  // Skip 'if'
        if (tokens[pos].type == LBRACE) {
            pos++;  // Skip '{'
            while (pos < tokens.size() && tokens[pos].type != RBRACE) {
                if (tokens[pos].type == IDENTIFIER) {
                    parseAssignment();
                } else {
                    throw std::runtime_error("Unexpected token in if block: " + tokens[pos].value);
                }
            }
            if (tokens[pos].type == RBRACE) {
                pos++;  // Skip '}'
            } else {
                throw std::runtime_error("Expected '}' at the end of if block");
            }
        } else {
            throw std::runtime_error("Expected '{' after 'if'");
        }
    }
};
