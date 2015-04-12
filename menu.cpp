//
// Created by Nicolas Tsagarides on 4/11/15.
//

#include "menu.h"

int menu()
{
    std::string option = "";
    bool firstTime = true;
    while (option !="0" && option !="1" && option !="2" && option !="3")
    {
        if (!firstTime)
        {
            std::cout << "\nInvalid input";
        }
        showMenu();
        option = userInput();
        firstTime = false;
    }

    return (std::stoi(option));
}

void showMenu()
{
    std::cout << std::endl <<
    "Select an option from below:\n\n" <<

    "    1: Graham Scan Algorithm\n" <<
    "    2: Gift Wrapping Algorithm\n" <<
    "    3: Divide and Conquer Algorithm\n" <<
    "    --\n" <<
    "    0: Exit\n\n" <<

    "Option: ";
}

std::string userInput()
{
    std::string input;
    getline(std::cin, input);

    return (input);
}