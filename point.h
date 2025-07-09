#pragma once
#include "direction.h"

struct Point{
    Point() = default;
    Point( int x, int y );
    bool operator== ( const Point& other );
    bool operator!= ( const Point& other );
    Point getAdjacentPoint( Direction direction );
    int m_x = 0, m_y = 0;
};