#include "menu.h"
#include "global.h"
#include "pointSet.h"
#include "grahamScan.h"
#include "misc.h"

std::vector <Point> p;
std::vector <Point> grahamScanPointSet;
std::time_t timerStart, timerEnd;

int main()
{
    std::string option = "";

    while ( (option.compare("x")!=0) && (option.compare("X")!=0) )
    {
        option = menu();

        if (option.compare("0")==0)
        {
            pointSetMenu();
        }
        else if (option.compare("1")==0)
        {
            grahamScanPointSet = p;

            timerStart = time(NULL);

            std::sort(grahamScanPointSet.begin(), grahamScanPointSet.end(), compareXOfPoints);

            std::vector<Point> temp = grahamScanConvexHull();

            timerEnd = time(NULL);

            double seconds = std::difftime(timerEnd, timerStart);
            std::cout << "Time: " << seconds;

            std::cout << "\npress enter\n";
            userInput();

            for (unsigned long long int i = 0; i < temp.size(); ++i)
            {
                std::cout << "\nPoint #" << i << "\nx: " << temp.at(i).getX() << "\ny: " << temp.at(i).getY() << "\n\n";
            }
        }
        else if (option.compare("2")==0)
        {
            //TODO Gift Wrapping
        }
        else if (option.compare("3")==0)
        {
            //TODO Divide and Conquer
        }
    }
    return 0;
}

