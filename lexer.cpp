#include <iostream>
#include <vector>
#include <regex>
#include <string>

enum TokenType { INT, IDENTIFIER, NUMBER, ASSIGN, PLUS, MINUS, IF, EQUALS, LBRACE, RBRACE, SEMICOLON };

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string &source) : source(source), pos(0) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        std::regex patterns("(int)|([a-zA-Z_][a-zA-Z0-9_]*)|(\\d+)|(=)|([+])|([-])|(if)|(==)|(\\{)|(\\})|(;)");
        auto words_begin = std::sregex_iterator(source.begin(), source.end(), patterns);
        auto words_end = std::sregex_iterator();

        for (auto i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            if (match[1].matched) tokens.push_back({INT, match.str()});
            else if (match[2].matched) tokens.push_back({IDENTIFIER, match.str()});
            else if (match[3].matched) tokens.push_back({NUMBER, match.str()});
            else if (match[4].matched) tokens.push_back({ASSIGN, match.str()});
            else if (match[5].matched) tokens.push_back({PLUS, match.str()});
            else if (match[6].matched) tokens.push_back({MINUS, match.str()});
            else if (match[7].matched) tokens.push_back({IF, match.str()});
            else if (match[8].matched) tokens.push_back({EQUALS, match.str()});
            else if (match[9].matched) tokens.push_back({LBRACE, match.str()});
            else if (match[10].matched) tokens.push_back({RBRACE, match.str()});
            else if (match[11].matched) tokens.push_back({SEMICOLON, match.str()});
        }
        return tokens;
    }

private:
    std::string source;
    size_t pos;
};
