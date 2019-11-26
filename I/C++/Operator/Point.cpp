using namespace std;

#include "Point.h"

#include <iostream>

Point::Point ( int _x, int _y ) : x ( _x ), y ( _y )
{

}

Point::~Point ( )
{

}

Point::Point ( const Point & p ) : x ( p.x ), y ( p.y )
{
    cout << "Appel au constructeur de copie" << endl;
}

Point operator + ( const Point & p1, const Point & p2 )
{
    Point p ( p1.x + p2.x, p1.y + p2.y );
    return p;
}

Point & Point::operator = ( const Point & p1 )
{
    if ( this != &p1 )
    {
        x = p1.x;
        y = p1.y;
    }

    return *this;
}

ostream & operator << ( std::ostream & out, const Point & p )
{
    cout << "x = " << p.x << ", y = " << p.y << endl;
    return out;
}