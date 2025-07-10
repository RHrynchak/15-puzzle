#include "point.h"

Point::Point( int x, int y ) : m_x(x), m_y(y) {}

bool Point::operator==( const Point& other ) const {
    return (m_x == other.m_x) && (m_y == other.m_y);
}

bool Point::operator!=( const Point& other ) const {
    return !( *this == other );
}

Point Point::getAdjacentPoint( Direction direction ) const {
    switch ( direction.getType() )
    {
    case Direction::Type::UP: return Point{ m_x, m_y - 1};
    case Direction::Type::DOWN: return Point{ m_x, m_y + 1};
    case Direction::Type::LEFT: return Point{ m_x - 1, m_y};
    case Direction::Type::RIGHT: return Point{ m_x + 1, m_y};
    }
    return *this;
}