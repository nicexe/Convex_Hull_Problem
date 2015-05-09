//
// Created by Nicolas Tsagarides on 4/19/15.
//

#include "misc.h"
#include <iostream>

std::string userInput()
{
    std::string input;
    getline(std::cin, input);

    return (input);
}