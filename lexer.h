#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <string>
#include <regex>

enum TokenType { INT, IDENTIFIER, NUMBER, ASSIGN, PLUS, MINUS, IF, EQUALS, LBRACE, RBRACE, SEMICOLON };

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string &source);
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t pos;
};

#endif
