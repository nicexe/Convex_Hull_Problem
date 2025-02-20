//
// Created by Nicolas Tsagarides on 5/9/15.
//

#include <iostream>
#include "pointSet.h"
#include "global.h"
#include "misc.h"
#include <random>

double lowerBound = 0;
double upperBound = 600;

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
                std::cout << "\nThere is an already existing point-set.\n";
                printDataSet = "    0: Print existing point-set\n    --\n";
            }
            else
            {
                std::cout << "There is no existing point-set. You need to set a new one.\n";
                printDataSet = "";
            }

            std::cout << "Select an option from below:\n\n" <<

            printDataSet << "    1: Enter a new point-set\n" <<
                            "    2: Generate a new point-set with random values\n" <<
                            "    --\n" <<
                            "    X: Go back\n\n" <<

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
                std::cout << "\nInvalid input\n";
            }

            std::cout << "\nPoint #" << (i+1) << ": x = ";
            input = userInput();

            try
            {
                num = std::stod(input);             // trying to convert a string to a double
                if (!is_double(input))
                {
                    throw std::invalid_argument("Invalid syntax.");
                }
                temp.setX(num);
                isDouble = true;
            }
            catch (std::invalid_argument e)         // catching invalid argument situations
            {
                std::cout << e.what();
                isDouble = false;
            }
            catch (std::out_of_range e)             // catching out of range situations
            {
                std::cout << e.what();
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
                std::cout << "\nInvalid input\n";
            }

            std::cout << "Point #" << (i+1) << ": y = ";
            input = userInput();

            try
            {
                num = std::stod(input);             // trying to convert a string to a double
                if (!is_double(input))
                {
                    throw std::invalid_argument("Invalid syntax.");
                }
                temp.setY(num);
                isDouble = true;
            }
            catch (std::invalid_argument e)         // catching invalid argument situations
            {
                std::cout << e.what();
                isDouble = false;
            }
            catch (std::out_of_range e)             // catching out of range situations
            {
                std::cout << e.what();
                isDouble = false;
            }

            firstRun = false;
        }

        p.push_back(temp);
    }
}

void fillWithRandomPoints()
{
    long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::uniform_real_distribution<double> unif(lowerBound, upperBound);
    std::default_random_engine dre (seed);

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

    for (unsigned long long i = 0; i < numberOfPoints; i++)
    {
        double tempX = unif(dre);
        double tempY = unif(dre);
        Point temp = Point(tempX, tempY);
        p.push_back(temp);
    }
}

void printPointSet()
{
    std::cout << std::endl << "Point-set\n" <<
                              "==========================\n";

    for (unsigned long long i=0; i<p.size(); i++)
    {
        std::cout << "\nPoint #" << (i+1) << "\nx = " << p.at(i).getX() << "\ny = " << p.at(i).getY() << std::endl;
    }

    std::cout << std::endl;
}