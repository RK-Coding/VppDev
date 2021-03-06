//Description: This file contains the parser which turns tokens into abstract syntax tree
//Author: RK-Coding

#pragma once

#include "ConvertExpressions.hpp"
#include "ParserExpressions.hpp"
#include "ExpressionPrinter.hpp"
#include <iostream> //Debug
#include <vector>


namespace parser
{
    class Parser
    {
    public:
        Expression parse_tokens(std::vector<lexer::Token> tokens)
        {
            Expression tree;

            for (size_t i = 0; i < tokens.size(); i++)
            {
                if (tokens[i].getType() == lexer::TokenType::MINUS)
                {
                    if (i == 0 || tokens[i+1].getType() != lexer::TokenType::NUMBER || tokens[i+1].getType() != lexer::TokenType::RIGHT_PAREN)
                    {
                        std::vector<lexer::Token> right_side_tokens = tokens;
                        right_side_tokens.erase(right_side_tokens.begin() + i);
                        
                        tree = Unary(tokens[i], parse_tokens(right_side_tokens));
                        print_expression(ToUnary(tree, tokens[i], parse_tokens(right_side_tokens)));

                        return tree;
                    }
                }

                if (tokens[i].getType() == lexer::TokenType::NUMBER)
                {
                    tree = Literal(tokens[i]);
                    print_expression(ToLiteral(tree, tokens[i]));

                    return tree;
                }

                if (tokens[i].getType() == lexer::TokenType::STAR)
                {

                }
            }
        }
    };
}