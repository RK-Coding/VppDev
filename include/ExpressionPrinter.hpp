//Description: This file prints Parser Expressions
//Author: RK-Coding

#pragma once

#include "ParserExpressions.hpp"

namespace parser
{
    template <class T>
    void print_expression(T expression) 
    {
        std::cout << expression.get_string_form() << std::endl;
    }
}