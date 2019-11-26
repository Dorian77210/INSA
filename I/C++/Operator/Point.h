#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
    public:
        Point ( int _x = 0, int _y = 0 );
        Point ( const Point & p );
        virtual ~Point ( );

        // ------ Friend functions ------- //
        friend Point operator + ( const Point & p1, const Point & p2 );
        Point operator + ( const Point p );
        friend ostream & operator << ( ostream & out, const Point & p );
        Point & operator = ( const Point & p1 );

    private:
        int x;
        int y;
};

#endif