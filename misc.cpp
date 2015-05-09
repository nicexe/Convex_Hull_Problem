//
// Created by Nicolas Tsagarides on 4/19/15.
//

#include "misc.h"
#include <iostream>
#include "global.h"

std::string userInput()
{
    std::string input;
    getline(std::cin, input);

    return (input);
}

bool is_number(const std::string& s)    // checks if a string is numeric
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}
