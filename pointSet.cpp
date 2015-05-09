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

            printDataSet << "    1: Enter a new point-set\n" <<
                            "    2: Generate a new point-set with random values\n" <<
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
            printPointSet();
            option = "";
        }
        else if (option.compare("1") == 0)
        {
            fillWithUserPoints();
            pointSetAvailable = true;
            option = "";
        }
        else if (option.compare("2") == 0)
        {
            fillWithRandomPoints();
            pointSetAvailable = true;
            option = "";
        }
    }
}

void fillWithUserPoints()
{
    unsigned long long numberOfPoints;
    std::string input = "a";
    bool firstRun = true;

    while (!is_number(input) || (input.compare("0")==0) || (input.compare("1")==0) || (input.compare("2")==0) || (input.compare("3")==0) )
    {
        if (!firstRun)
        {
            std::cout << "\nInvalid input";
        }

        std::cout << "\nEnter the number of points you want to register: ";
        input = userInput();

        firstRun = false;
    }

    numberOfPoints = std::stoull(input);
    p.clear();

    for (unsigned long long i=0; i<numberOfPoints; i++)
    {
        Point temp;
        double num;
        std::string input = "a";
        bool firstRun = true;
        bool isDouble = false;

        while (!isDouble)
        {
            if (!firstRun)
            {
                std::cout << "\nInvalid input";
            }

            std::cout << "\nPoint #" << i << ": x = ";
            input = userInput();

            try
            {
                num = std::stod(input);             // trying to convert a string to a double
                temp.setX(num);
                isDouble = true;
            }
            catch (std::invalid_argument e)         // catching invalid argument situations
            {
                std::cout << e.what() << std::endl;
                isDouble = false;
            }
            catch (std::out_of_range e)             // catching out of range situations
            {
                std::cout << e.what() << std::endl;
                isDouble = false;
            }

            firstRun = false;
        }

        input = "a";
        firstRun = true;
        isDouble = false;

        while (!isDouble)
        {
            if (!firstRun)
            {
                std::cout << "\nInvalid input";
            }

            std::cout << "\nPoint #" << i << ": y = ";
            input = userInput();

            try
            {
                num = std::stod(input);             // trying to convert a string to a double
                temp.setY(num);
                isDouble = true;
            }
            catch (std::invalid_argument e)         // catching invalid argument situations
            {
                std::cout << e.what() << std::endl;
                isDouble = false;
            }
            catch (std::out_of_range e)             // catching out of range situations
            {
                std::cout << e.what() << std::endl;
                isDouble = false;
            }

            firstRun = false;
        }

        p.push_back(temp);
    }
}

void fillWithRandomPoints()
{
    unsigned long long numberOfPoints;
    std::string input = "a";
    bool firstRun = true;

    while (!is_number(input) || (input.compare("0")==0) || (input.compare("1")==0) || (input.compare("2")==0) || (input.compare("3")==0) )
    {
        if (!firstRun)
        {
            std::cout << "\nInvalid input";
        }

        std::cout << "\nEnter the number of points you want to be generated: ";
        input = userInput();

        firstRun = false;
    }

    numberOfPoints = std::stoull(input);
    p.clear();

    //TODO generate points
}

void printPointSet()
{
    std::cout << std::endl << "Point-set\n" <<
                              "==========================\n";

    for (unsigned long long i=0; i<p.size(); i++)
    {
        std::cout << "\nPoint #" << i << "\nx = " << p.at(i).getX() << "\ny = " << p.at(i).getY() << std::endl;
    }

    std::cout << std::endl;
}