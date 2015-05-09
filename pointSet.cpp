//
// Created by Nicolas Tsagarides on 5/9/15.
//

#include <iostream>
#include "pointSet.h"
#include "global.h"
#include "misc.h"

void pointSetMenu()
{
    std::cout << "\n";

    std::string option = "";

    while ( (option.compare("x")!=0) && (option.compare("X")!=0) )
    {
        bool firstTime = true;
        while (option != "0" && option != "1" && option != "2" && option != "x" && option != "X")
        {
            if (!firstTime)
            {
                std::cout << "\nInvalid input\n";
            }

            std::string printDataSet;
            if (pointSetAvailable)
            {
                std::cout << "\nThere is an already existing point-set.";
                printDataSet = "    0: Print existing point-set\n    --\n";
            }
            else
            {
                std::cout << "There is no existing point-set. You need to set a new one.\n";
                printDataSet = "\n";
            }

            std::cout << "Select an option from below:\n\n" <<

            printDataSet << "    1: Enter a new point-set\n" << "    2: Generate a new point-set with random values\n" <<
                            "    --\n" << "    X: Cancel\n\n" <<

            "Option: ";

            option = userInput();
            if ((option.compare("0") == 0) && (!pointSetAvailable))   // the user can't select the option zero if there is no available point-set
            {
                option = "";
            }

            firstTime = false;
        }

        if (option.compare("0") == 0)
        {
            // code

            option = "";
        }
        else if (option.compare("1") == 0)
        {
            // code

            option = "";
        }
        else if (option.compare("2") == 0)
        {
            // code

            option = "";
        }
    }
}

void fillWithUserPoints(unsigned long long int i)
{

}

void fillWithRandomPoints(unsigned long long int i)
{

}
