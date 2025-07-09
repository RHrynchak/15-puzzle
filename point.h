#pragma once
#include "direction.h"

class Point{
public:
    Point() = default;
    Point( int x, int y );
    bool operator== ( const Point& other );
    bool operator!= ( const Point& other );
    Point getAdjacentPoint( Direction::Type direction );
private:
    int m_x = 0, m_y = 0;
};