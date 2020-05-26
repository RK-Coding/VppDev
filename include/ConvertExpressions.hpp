//Description: This files converts expressions to specific types, like Expression to Unary
//Author: RK-Coding

#pragma once

#include "ParserExpressions.hpp"

namespace parser
{
    Unary ToUnary(Expression actual_expression, lexer::Token prefix, Expression expression) { return Unary(prefix, expression); }
    Literal ToLiteral(Expression actual_expression, lexer::Token type) { return Literal(type); }
}