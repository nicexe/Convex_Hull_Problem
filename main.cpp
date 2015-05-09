#include "menu.h"
#include "global.h"
#include "pointSet.h"

std::vector <Point> p;

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
            // ask for visual output
            //TODO Graham Scan
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

