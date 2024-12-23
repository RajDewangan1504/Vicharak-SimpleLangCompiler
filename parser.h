#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>
#include <string>
#include <stdexcept>

class Parser {
public:
    Parser(const std::vector<Token> &tokens);
    void parse();

private:
    std::vector<Token> tokens;
    size_t pos;

    void parseDeclaration();
    void parseAssignment();
    void parseExpression();
    void parseConditional();
};

#endif
