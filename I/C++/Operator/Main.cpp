using namespace std;

#include "Point.h"
#include <iostream>


int main ( int argc, const char** argv ) 
{
    Point p ( 1, 1 );
    Point p2 ( 1, 2 );

    Point result = p + p2;

    cout << result;
    return 0;
}