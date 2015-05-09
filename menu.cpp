//
// Created by Nicolas Tsagarides on 4/11/15.
//

#include "menu.h"
#include "misc.h"

std::string menu()
{
    std::string option = "";
    bool firstTime = true;
    while (option != "0" && option != "1" && option != "2" && option != "3" && option != "x" && option != "X")
    {
        if (!firstTime)
        {
            std::cout << "\nInvalid input";
        }
        showMenu();
        option = userInput();
        firstTime = false;
    }

    return (option);
}

void showMenu()
{
    std::cout << std::endl <<
            "Select an option from below:\n\n" <<

            "    0: Manage point-set\n" <<
            "    --\n" <<
            "    1: Graham Scan Algorithm\n" <<
            "    2: Gift Wrapping Algorithm\n" <<
            "    3: Divide and Conquer Algorithm\n" <<
            "    --\n" <<
            "    X: Exit\n\n" <<

            "Option: ";
}
