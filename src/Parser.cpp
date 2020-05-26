//Description: This is just a file that tests and implements the Parser from Paser.hpp
//Author: RK-Coding

#include "Parser.hpp"

std::vector<lexer::Token> tokens = {lexer::Token(lexer::TokenType::MINUS, "-", "-", 1), lexer::Token(lexer::TokenType::NUMBER, "5", "5", 1)};
parser::Parser test;

int main()
{
    test.parse_tokens(tokens);
}