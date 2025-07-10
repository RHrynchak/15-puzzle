#include "direction.h"
#include "random.h"

Direction::Direction( Type type ) : m_type( type ) {}

Direction::Type Direction::getType() const { return m_type; }

void Direction::changeType( Type type ) { m_type = type; }

Direction Direction::operator-() const{
    switch ( m_type ){
        case UP: return Direction { DOWN };
        case DOWN: return Direction { UP };
        case LEFT: return Direction { RIGHT };
        case RIGHT: return Direction { LEFT };
    }
    return *this;
}

Direction Direction::getRandomDirection(){
    return Direction { static_cast<Type>( Random::get( 0, Type::TOTAL_DIRECTIONS - 1 ) ) };
}