//TASK
//1. Defining syntax and semantics for logical operations
#include <iostream>
using namespace std;

#include "lexer.h"
#include "parser.h"

int main() {
    std::string code = "int a; a = 5 + 3; if (a == 8) { a = a - 1; }";
    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();

    for (const Token &token : tokens) {
        std::cout << "Token: " << token.value << std::endl;
    }

    Parser parser(tokens);
    parser.parse();

    return 0;
}


