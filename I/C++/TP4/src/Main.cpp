#include <iostream>

#include "../includes/ApplicationManager.h"

using namespace std;

int main(int argc, const char** argv)
{
    ApplicationManager manager;

    if ( manager.Configure ( argc - 1 , argv + 1 ) )
    {
        if ( manager.ExecuteAnalyze ( ) )
        {

        } else
        {
            return 1;
        }
    } else
    {
        return 1;
    }

    return 0;
}