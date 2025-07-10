#pragma once
#include "direction.h"

struct Point{
    Point() = default;
    Point( int x, int y );
    bool operator== ( const Point& other ) const;
    bool operator!= ( const Point& other ) const;
    Point getAdjacentPoint( Direction direction ) const;
    int m_x = 0, m_y = 0;
};